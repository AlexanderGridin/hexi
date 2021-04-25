<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

// Инициализация импорта
function import_data_from_file(){
  $import_config = variable_get('hexi_import_config');
  $file_data = variable_get('hexi_file_data');

  foreach($file_data as $row){
    $operations[] = array('import_processing', array($import_config, $row));
  }

  $batch = array(
    'operations' => $operations,
    'finished' => 'import_finished',
    'title' => 'Обработка данных',
    'init_message' => 'Подготовка данных',
    'progress_message' => 'Выполнено @current из @total.',
    'error_message' => 'Произошла ошибка.',
    'file' => drupal_get_path('module', 'hexi') . '/lib/import_data_from_file.inc',
  );

  batch_set($batch);
  batch_process('/data-processing-finished');
}

// Единичная операция импорта
function import_processing($import_config, $row, &$context){
  // Создаем товары и их ноды
  if(!$row['is_merged_cell'] && !empty($row['cells_data'][0])){
    create_product($import_config, $row, $context);
    create_product_display($import_config, $row, $context);

    $context['results']['proceeded_products']++;
  }

  $context['results']['proceeded_rows']++;
  $context['message'] = 'Обработана строка <em><strong>' . $context['results']['proceeded_rows'] . '</strong></em>';
}

// Окончание импорта
function import_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Обработано ' . $results['proceeded_rows'] . ' строк');
    drupal_set_message('Из них ' . $results['proceeded_products'] . ' товаров');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}