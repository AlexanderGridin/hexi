<?php 
module_load_include('inc', 'hexi', '/lib/import_data_from_file');

function parse_data_from_file(){
  $module_path = drupal_get_path('module', 'hexi');
  require_once $module_path . '/vendor/phpexcel/PHPExcel.php';
  module_load_include('inc', 'hexi', '/lib/hexi_tools');

  $import_config = variable_get('hexi_import_config');
  $update_config = variable_get('hexi_update_config');

  // Загружаем объект файла из БД
  if(isset($import_config)){
    $file_fid = $import_config->fid;
  }

  if(isset($update_config)){
    $file_fid = $update_config->fid;
  }
  
  $file = file_load($file_fid);
  $file_path = drupal_realpath($file->uri);

  // Загружаем файл Excel и получаем активный лист
  $excel_file = PHPExcel_IOFactory::load($file_path);
  $excel_file->setActiveSheetIndex(0);
  $sheet = $excel_file->getActiveSheet();

  // Получаем границы листа по столблцам и строкам
  $highest_column_string_index = $sheet->getHighestColumn();
  $max_sheet_columns = PHPExcel_Cell::columnIndexFromString($highest_column_string_index);
  $max_sheet_rows = $sheet->getHighestRow();

  // Устанавливаем граничные значения обработки данных в соответствии с конфигом
  if(isset($import_config) || isset($update_config)){
    $start_row = (boolean) $import_config->start_row ? intval($import_config->start_row) : 0;
    $end_row = (boolean) $import_config->end_row ? intval($import_config->end_row) : $max_sheet_rows;
  }

  // Получаем информацию об изображениях, если это предусмотрено конфигом импорта
  if((isset($import_config) && $import_config->is_importing_images) || isset($update_config)){
    $sheet_images = $sheet->getDrawingCollection();

    $images_data = array();

    foreach($sheet_images as $image){
      $data = array(
        'path' => $image->getPath(),
        'coordinates' => $image->getCoordinates(),
        'extention' => $image->getExtension(),
      );

      array_push($images_data, $data);
    }
  }

  // Начинаем считывать данные
  $sheet_rows_data = array();

  for($row = $start_row; $row <= $end_row; $row++){
    $row_data = array(
      'cells_data' => array(),
      'is_merged_cell' => false,
      'image_coordinate' => NULL,
      'image_data' => NULL
    );

    $first_cell = $sheet->getCellByColumnAndRow(0, $row);
    if($first_cell->isMergeRangeValueCell()){
      $row_data['is_merged_cell'] = true;
    }

    // Бежим по колонкам строки
    for($column = 0; $column < $max_sheet_columns; $column++){
      $cell = $sheet->getCellByColumnAndRow($column, $row);
      $cell_value =  $cell->getValue();

      // Считываем информацию из колонок строки
      array_push($row_data['cells_data'], convert_RichText_to_string($cell_value));

      // Записываем ячейку с картинкой, если это предусмотрено конфигом импорта
      if(
        (isset($import_config) || isset($update_config)) && 
        ($import_config->is_importing_images || $update_config->is_importing_images) && 
        (isset($import_config->image_column_index) || isset($update_config->image_column_index)) && 
        ($column == $import_config->image_column_index - 1 || $column == $update_config->image_column_index - 1) && 
        !$row_data['is_merged_cell']
        ){
        $img_coordinate = PHPExcel_Cell::stringFromColumnIndex($column) . $row;
        $row_data['image_coordinate'] = $img_coordinate;

        foreach($images_data as $image){
          if($image["coordinates"] == $img_coordinate){
            $row_data['image_data'] = $image;
          }
        }
      }
    }

    array_push($sheet_rows_data, $row_data);
  }

  variable_set('hexi_file_data', $sheet_rows_data);
}

function parse_data_from_file_finished($success, $results, $operations){
  if($success){
    drupal_goto('/hexi-import-data-from-file');
  }
}