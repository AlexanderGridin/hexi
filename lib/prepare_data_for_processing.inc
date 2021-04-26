<?php 
function prepare_data_for_processing(){
  $import_config = variable_get('excel_import_config');
  $update_config = variable_get('excel_update_config');

  $operations[] = array('parse_data_from_file', array());

  $batch = array(
    'operations' => $operations,
    'finished' => 'parse_data_from_file_finished',
    'title' => 'Получение данных из файла',
    'init_message' => 'Загрузка файла',
    'progress_message' => 'Выполнено @current из @total.',
    'error_message' => 'Произошла ошибка.',
    'file' => drupal_get_path('module', 'hexi') . '/lib/parse_data_from_file.inc',
  );

  batch_set($batch);
}