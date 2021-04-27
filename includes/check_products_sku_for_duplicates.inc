<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
require_once drupal_get_path('module', 'hexi') . '/vendor/phpexcel/PHPExcel.php';

function check_products_sku_for_duplicates(){
  function check_products_sku_for_duplicates_form($form, &$form_state){
    $form['file'] = array(
      '#title'         => "Выберите <u>.xls</u> или <u>.xlsx</u> файл для загрузки",
      '#description'   => "Максимальный размер загрузки <strong>" . get_upload_max_size() . ".</strong> Допустимые форматы загружаемых файлов: <strong>xls, xlsx</strong>",
      '#type'          => 'file',
    );

    $form['row_start'] = array(
      '#type' => 'textfield', 
      '#title' => 'Начало обработки файла (номер строки файла Excel)', 
      '#default_value' => 0, 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
      '#description'   => "Укажите номер строки файла Excel, с которой начнется обработка файла.",
    );

    $form['row_end'] = array(
      '#type' => 'textfield', 
      '#title' => 'Конец обработки файла (номер строки файла Excel)', 
      '#default_value' => 0, 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
      '#description'   => "Укажите номер строки файла Excel, после которой обработка файла будет прекращена.",
    );

    $form['sku_column'] = array(
      '#type' => 'textfield', 
      '#title' => 'Колонка с артикулами товаров', 
      '#default_value' => 0, 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
      '#description'   => "Укажите колонку файла Excel, в которой находятся артикулы товаров.",
    );
    
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Начать проверку",
    );
    
    return $form;
  }

  function check_products_sku_for_duplicates_form_validate($form, &$form_state){
    $document_import_id = 'hexi_document';
    $upload_max_size = parse_size(ini_get("upload_max_filesize"));

    // Проверяем наличие файла в БД
    $file_name = $_FILES['files']['name']['file'];

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'file')
    ->propertyCondition('filename', $file_name);

    $result = $query->execute();

    // Записываем в конфиг: файл с данными импортируется впервые или обновляется
    if(count($result) > 0){
      drupal_set_message('Файл ' . $file_name .' имеется в базе. Он был обновлен данным файлом.', 'status');
    } else {
      drupal_set_message('Файл ' . $file_name .' был загружен и зарегистрирован в базе данных.', 'status');
    }

    // Валидируем форму
    $validators = array(
      'file_validate_extensions' => array('xls xlsx'), 
      'file_validate_size' => array($upload_max_size),
    );

    if ($file = file_save_upload('file', $validators, 'public://hexi_data/price_files', FILE_EXISTS_REPLACE)) {
      $file->field_file_import_id['und'][0]['value'] = $document_import_id;

      $file = file_save($file);
      $form_state['values']['file'] = $file; 
    }
    else {
      form_set_error('file', 'Файл не был загружен');
    }
  }

  function check_products_sku_for_duplicates_form_submit($form, &$form_state){
    $row_start = intval($form_state['values']['row_start']);
    $row_end = intval($form_state['values']['row_end']);
    $sku_column = intval($form_state['values']['sku_column']) - 1;
    $fid = $form_state['values']['file']->fid;

    $operations[] = array('get_skus_from_file_for_check', array($sku_column, $row_start, $row_end, $fid));

    $batch = array(
      'operations' => $operations,
      'title' => 'Проверка дубликатов артикулов',
      'init_message' => 'Загрузка файла',
      'progress_message' => 'Выполнено @current из @total.',
      'error_message' => 'Произошла ошибка.',
      'file' => drupal_get_path('module', 'hexi') . '/includes/check_products_sku_for_duplicates.inc',
    );

    batch_set($batch);
  }

  $check_products_sku_for_duplicates_form = drupal_get_form('check_products_sku_for_duplicates_form');
  return theme('check_products_sku_for_duplicates', array(
    'check_products_sku_for_duplicates_form' => $check_products_sku_for_duplicates_form
  ));
}

// Получаем данные из файла для проверки
function get_skus_from_file_for_check($sku_column, $row_start, $row_end, $fid){
  // Загружаем объект файла из БД
  $file = file_load($fid);
  $file_path = drupal_realpath($file->uri);

  // Загружаем файл Excel и получаем активный лист
  $excel_file = PHPExcel_IOFactory::load($file_path);

  $excel_file->setActiveSheetIndex(0);
  $sheet = $excel_file->getActiveSheet();

  // Начинаем считывать данные
  $file_skus = array();

  for($row = $row_start; $row <= $row_end; $row++){
    $sku_cell = $sheet->getCellByColumnAndRow($sku_column, $row);
    $sku_cell_value = $sku_cell->getValue();

    if(isset($sku_cell_value) && !empty($sku_cell_value)){
      $sku_cell_value = convert_RichText_to_string($sku_cell_value);
      array_push($file_skus, $sku_cell_value);
    }
  }

  foreach($file_skus as $sku){
    $operations[] = array('check_sku_for_duplicate_in_db', array($sku));
  }

  $batch = array(
    'operations' => $operations,
    'finished' => 'check_products_sku_for_duplicates_finished',
    'title' => 'Обработка данных',
    'init_message' => 'Подготовка данных',
    'progress_message' => 'Выполнено @current из @total.',
    'error_message' => 'Произошла ошибка.',
    'file' => drupal_get_path('module', 'hexi') . '/includes/check_products_sku_for_duplicates.inc',
  );

  batch_set($batch);
}

// Единичная операция проверки sku
function check_sku_for_duplicate_in_db($sku, &$context){
  $get_products_query = new EntityFieldQuery();
  $products = $get_products_query->entityCondition('entity_type', 'commerce_product')
    ->propertyCondition('sku', $sku)
    ->execute();
  
  if(count($products) > 0){
    $context['results']['duplicated_skus'] .= $sku . ' ';
    $context['results']['duplicated_skus_count']++;
  }

  $context['results']['proceeded_rows']++;
  $context['message'] = 'Проверен артикул <strong><em>' . $sku . '</em></strong>';
}

// Окончание проверки
function check_products_sku_for_duplicates_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Обработано ' . $results['proceeded_rows'] . ' строк');

    if(count($results['duplicated_skus_count']) > 0){
      drupal_set_message('Из них дублирующихся артикулов ' . $results['duplicated_skus_count'], 'error');
    
      $duplicated_skus = explode(' ', $results['duplicated_skus']);

      for($i = 0; $i < count($duplicated_skus) - 1; $i++){
        $dsku = $duplicated_skus[$i];

        drupal_set_message('Имеется дубликат акртикула: <strong>' . $dsku . '</strong>', 'error');
      }
    } else {
      drupal_set_message('Дубликаты артикулов не обнаружены');
    }
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}