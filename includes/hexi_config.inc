<?php
/**
 * В данном коде в поле сущности файла field_file_import_id записывается ID файла. 
 * Изначально данное поле у сущности файла отсутствует, поэтому оно должно быть создано через админку у типа файла Document.
 */
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/folders_functions');

function hexi_config(){
  delete_variable_from_db('hexi_import_config');
  delete_variable_from_db('hexi_update_config');
  delete_variable_from_db('hexi_file_data');

  /* -------------------------------- */
  /* Определяем форму с выбором настроек операции
  /* -------------------------------- */
  function hexi_config_form($form, &$form_state){
    $form['file'] = array(
      '#title'         => "Выберите <u>.xls</u> или <u>.xlsx</u> файл для загрузки",
      '#description'   => "Максимальный размер загрузки <strong>" . get_upload_max_size() . ".</strong> Допустимые форматы загружаемых файлов: <strong>xls, xlsx</strong>",
      '#type'          => 'file',
    );

    $form['operation_type'] = array(
      '#type'          => 'radios',
      '#title'         => 'Что необходимо сделать',
      '#options'       => array(
        'import_excel_data' => 'Импорт данных',
        'update_excel_data' => 'Обновление данных'
      ),
      '#required'      => true
    );

    $form['is_filename_changed'] = array(
      '#type'          => 'radios',
      '#title'         => 'Название файла Excel изменено?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => true,
      '#states' => array(
        'visible' => array(
          ':input[name="operation_type"]' => array(
            'value' => 'update_excel_data',
          ),
        ),
      ),
    );

    $form['product_type'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите тип импортируемых товаров',
      '#options'       => get_product_types_form_options_array(),
      '#required'      => true,
      '#states' => array(
        'visible' => array(
          ':input[name="operation_type"]' => array(
            'checked' => TRUE,
          ),
        ),
      ),
    );

    $form['start_row'] = array(
      '#type' => 'textfield', 
      '#title' => 'Начальная строка обработки файла (номер строки файла Excel)', 
      '#default_value' => 0, 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
      '#description'   => "Укажите номер строки файла Excel, с которой начнется обработка файла.",
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'checked' => TRUE,
          ),
        ),
      ),
    );

    $form['end_row'] = array(
      '#type' => 'textfield', 
      '#title' => 'Конечная строка обработки файла (номер строки файла Excel)', 
      '#default_value' => 0, 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
      '#description'   => "Укажите номер строки файла Excel, после которой обработка файла будет прекращена.",
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'checked' => TRUE,
          ),
        ),
      ),
    );

    $form['is_importing_images'] = array(
      '#type'          => 'radios',
      '#title'         => 'Необходимо импортировать фотографии?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => true,
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'checked' => TRUE,
          ),
        ),
      ),
    );

    $form['folder_with_images_nid'] = array(
      '#type' => 'radios', 
      '#title' => 'Выберите папку с изображениями', 
      '#default_value' => NULL, 
      '#description'   => "Папка с изображениями",
      '#states' => array(
        'visible' => array(
          ':input[name="is_importing_images"]' => array(
            'value' => '1',
          ),
        ),
      ),
      '#options'       => generate_photo_folders_form_options_array(),
    );

    $form['is_importing_interrior_examples'] = array(
      '#type'          => 'radios',
      '#title'         => 'Необходимо импортировать примеры интерьеров?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => false,
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'value' => 'stucco',
          ),
        ),
      ),
    );

    $form['folder_with_interrior_examples_images_nid'] = array(
      '#type' => 'radios', 
      '#title' => 'Выберите папку с изображениями примеров интерьера', 
      '#default_value' => NULL, 
      '#description'   => "Папка с изображениями",
      '#states' => array(
        'visible' => array(
          ':input[name="is_importing_interrior_examples"]' => array(
            'value' => '1',
          ),
        ),
      ),
      '#options'       => generate_photo_folders_form_options_array(),
    );

    $form['is_importing_video'] = array(
      '#type'          => 'radios',
      '#title'         => 'Необходимо импортировать видеообзоры?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => false,
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'value' => 'stucco',
          ),
        ),
      ),
    );

    $form['is_importing_specifications'] = array(
      '#type'          => 'radios',
      '#title'         => 'Необходимо импортировать технические характеристики?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => false,
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'value' => 'product_paints',
          ),
        ),
      ),
    );

    $form['folder_with_specifications_nid'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите папку с техническими характеристиками',
      '#options'       => generate_documents_folders_form_options_array(),
      '#states' => array(
        'visible' => array(
          ':input[name="is_importing_specifications"]' => array(
            'value' => '1',
          ),
        ),
      ),
    );

    /*
    $form['image_column_index'] = array(
      '#type' => 'textfield', 
      '#title' => 'Введите номер колонки, содержащей названия изображений', 
      '#default_value' => NULL, 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#description'   => "Целое число. В колонке должны быть указаны названия изображений, разделенные одним пробелом. Тип изображения (расширение файла) не указывается.",
      '#states' => array(
        'visible' => array(
          ':input[name="is_importing_images"]' => array(
            'value' => '1',
          ),
        ),
      ),
    );
    */

    $form['main_catalogue_category'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите категорию продукции в каталоге',
      '#options'       => generate_catalogue_form_options_array('Каталог продукции'),
      '#required'      => true,
      '#states' => array(
        'visible' => array(
          ':input[name="product_type"]' => array(
            'checked' => TRUE,
          ),
        ),
      ),
    );

    /*
    $form['is_import_catalogue_before'] = array(
      '#type'          => 'radios',
      '#title'         => 'Импортировался ли каталог при импорте товаров?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => true,
      '#states' => array(
        'visible' => array(
          ':input[name="main_catalogue_category"]' => array(
            'checked' => TRUE,
          ),
          ':input[name="operation_type"]' => array(
            'value' => 'update_excel_data',
          ),
        ),
      ),
    );
    */

    // DEV
    /*
    $form['is_import_catalogue'] = array(
      '#type'          => 'radios',
      '#title'         => 'Необходимо импортировать категории каталога?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '0',
      '#required'      => true,
      '#states' => array(
        'visible' => array(
          ':input[name="main_catalogue_category"]' => array(
            'checked' => TRUE,
          ),
          ':input[name="operation_type"]' => array(
            'value' => 'import_excel_data',
          ),
        ),
      ),
    );
    */

    // DEV
    /*
    $form['catalogue_category_cell_type'] = array(
      '#type'          => 'radios',
      '#title'         => 'Критерий определения ячейки с категорией каталога',
      '#options'       => array(
        'merged_cell' => 'Объединенная ячейка',
        'empty_cell' => 'Пустая ячейка'
      ),
      '#default_value' => 'merged_cell',
      '#states' => array(
        'visible' => array(
          ':input[name="is_import_catalogue"]' => array(
            'value' => '1',
          ),
          ':input[name="operation_type"]' => array(
            'value' => 'import_excel_data',
          ),
        ),
      ),
    );
    */
    
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Далее",
    );
    
    return $form;
  }

  function hexi_config_form_validate($form, &$form_state) {
    $document_import_id = 'hexi_document';
    $upload_max_size = parse_size(ini_get("upload_max_filesize"));

    // Подготавливаем переменную для хранения конфигурации
    switch ($form_state['values']['operation_type']){
      case 'import_excel_data':
        $import_config = new stdClass();
        break;

      case 'update_excel_data':
        $update_config = new stdClass();
        break;
    }

    // Проверяем наличие файла в БД
    $file_name = $_FILES['files']['name']['file'];

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'file')
    ->propertyCondition('filename', $file_name);

    $result = $query->execute();

    // Записываем в конфиг: файл с данными импортируется впервые или обновляется
    if(count($result) > 0){
      switch ($form_state['values']['operation_type']){
        case 'import_excel_data':
          $import_config->file_update = 1;
          break;

        case 'update_excel_data':
          $update_config->file_update = 1;
          break;
      }
      
      drupal_set_message('Файл ' . $file_name .' имеется в базе. Он был обновлен данным файлом.', 'status');
    } else {
      switch ($form_state['values']['operation_type']){
        case 'import_excel_data':
          $import_config->file_update = 0;
          break;

        case 'update_excel_data':
          $update_config->file_update = 0;
          break;
      }

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

      switch ($form_state['values']['operation_type']){
        case 'import_excel_data':
          $import_config->fid = $file->fid;
          $import_config->filename = $file->filename;
          break;

        case 'update_excel_data':
          $update_config->fid = $file->fid;
          $update_config->filename = $file->filename;
          break;
      }

      $form_state['values']['file'] = $file; 
    }
    else {
      form_set_error('file', 'Файл не был загружен');
    }

    // Валидируем поле "Папка с фотографиями"
    if(
      (boolean)$form_state['values']['is_importing_images'] &&
      !isset($form_state['values']['folder_with_images_nid'])
    ){
      form_set_error('folder_with_images_nid', 'Выберите папку с изображениями, в которой хранятся фотографии');
    }

    // Валидируем поле "Папка с примерами интерьера"
    if(
      (boolean)$form_state['values']['is_importing_interrior_examples'] &&
      !isset($form_state['values']['folder_with_interrior_examples_images_nid'])
    ){
      form_set_error('folder_with_interrior_examples_images_nid', 'Выберите папку с изображениями, в которой хранятся примеры интерьеров');
    }

    // Валидируем поле "Папка с техническими характеристиками"
    if(
      (boolean)$form_state['values']['is_importing_specifications'] &&
      !isset($form_state['values']['folder_with_specifications_nid'])
    ){
      form_set_error('folder_with_specifications_nid', 'Выберите папку, в которой хранятся файлы с техническими характеристиками товаров.');
    }

    // Устанавливаем конфиги
    switch ($form_state['values']['operation_type']){
      case 'import_excel_data':
        variable_set('hexi_import_config', $import_config);
        break;

      case 'update_excel_data':
        variable_set('hexi_update_config', $update_config);
        break;
    }
  }

  function hexi_config_form_submit($form, &$form_state) {
    // Дополняем конфиг
    switch ($form_state['values']['operation_type']){
      case 'import_excel_data':
        $import_config = variable_get('hexi_import_config');

        $import_config->operation_type = $form_state['values']['operation_type'];
        $import_config->product_type = $form_state['values']['product_type'];
        $import_config->start_row = $form_state['values']['start_row'];
        $import_config->end_row = intval($form_state['values']['end_row']);
        $import_config->is_importing_images = (boolean)$form_state['values']['is_importing_images'];
        $import_config->image_column_index = intval($form_state['values']['image_column_index']);
        $import_config->main_catalogue_category = $form_state['values']['main_catalogue_category'];
        $import_config->is_import_catalogue = (boolean)$form_state['values']['is_import_catalogue'];
        $import_config->catalogue_category_cell_type = $form_state['values']['catalogue_category_cell_type'];
        $import_config->folder_with_images_nid = $form_state['values']['folder_with_images_nid'];
        // $import_config->image_column_index = $form_state['values']['image_column_index'];
        $import_config->is_importing_interrior_examples = (boolean)$form_state['values']['is_importing_interrior_examples'];
        $import_config->folder_with_interrior_examples_images_nid = $form_state['values']['folder_with_interrior_examples_images_nid'];
        $import_config->is_importing_video = (boolean)$form_state['values']['is_importing_video'];
        $import_config->is_importing_specifications = (boolean)$form_state['values']['is_importing_specifications'];
        $import_config->folder_with_specifications_nid = $form_state['values']['folder_with_specifications_nid'];

        variable_set('hexi_import_config', $import_config);
        break;

      case 'update_excel_data':
        $update_config = variable_get('hexi_update_config');

        $update_config->is_import_catalogue_before = (boolean)$form_state['values']['is_import_catalogue_before'];
        $update_config->start_row = $form_state['values']['start_row'];
        $update_config->end_row = intval($form_state['values']['end_row']);
        $update_config->main_catalogue_category = $form_state['values']['main_catalogue_category'];
        $update_config->operation_type = $form_state['values']['operation_type'];
        $update_config->product_type = $form_state['values']['product_type'];
        $update_config->is_importing_images = (boolean)$form_state['values']['is_importing_images'];
        $update_config->image_column_index = intval($form_state['values']['image_column_index']);
        $update_config->is_filename_changed = (boolean)$form_state['values']['is_filename_changed'];

        variable_set('hexi_update_config', $update_config);
        break;
    }
    
    drupal_goto('/hexi-check-config');
  }

  $hexi_config_form = drupal_get_form('hexi_config_form');
  return theme('hexi_config', array(
    'hexi_config_form' => $hexi_config_form,
  ));
}