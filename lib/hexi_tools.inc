<?php
// FUNCTIONS
function taxonomy_create_term_in_vocabulary($name, $vid){
  $new_term = (object) array(
    'vid' => $vid, 
    'name' => $name,
  );

  taxonomy_term_save($new_term);

  return $new_term;
}

function is_taxonomy_term_in_vocabulary($term_name, $voc_mashine_name){
  $finded_terms = taxonomy_get_term_by_name($term_name, $voc_mashine_name);

  if(count($finded_terms) == 1){
    return true;
  }

  if(count($finded_terms) == 0){
    return false;
  }
}

function taxonomy_create_vocabulary($name, $mashine_name){
  $vocab = taxonomy_get_vocabulary_by_name($name);

  if(isset($vocab)){
    return;
  } else {
    $new_vocab = (object) array(
      'name' => $name,
      'machine_name' => $mashine_name,
    );  

    taxonomy_vocabulary_save($new_vocab);
  }
}

function prepare_config_html($config){
  $operation_type = get_excel_import_readable_operation_type($config->operation_type);
  $product_type = commerce_product_type_get_name($config->product_type);
  $start_row = $config->start_row;
  $end_row = $config->end_row;
  $main_catalogue_category = get_taxonomy_term_name_by_tid($config->main_catalogue_category);

  if($config->operation_type == 'import_excel_data'){
    $title = 'Проверьте параметры импорта';
    // $image_column_index = $config->image_column_index;
    // $is_importing_catalogue = get_boolean_readable_name($config->is_import_catalogue);

    $config_items = "
      <p><strong>Что необходимо сделать: </strong>$operation_type</p>
      <p><strong>Тип товаров: </strong>$product_type</p>
      <p><strong>Начало обработки файла (номер строки файла Excel): </strong>$start_row</p>
      <p><strong>Конец обработки файла (номер строки файла Excel): </strong>$end_row</p>
      <p><strong>Категория продукции в каталоге: </strong>$main_catalogue_category</p>
    ";

    // Фотографии
    if($config->is_importing_images){
      $is_importing_images = get_boolean_readable_name($config->is_importing_images);
      $config_items .= "<p><strong>Необходимо импортировать изображения?: </strong>$is_importing_images</p>";

      // Получаем название папки с изображениями
      $imgs_folder_node = node_load($config->folder_with_images_nid);
      $imgs_folder_title = $imgs_folder_node->title;
      $config_items .= "<p><strong>Папка с изображениями: </strong>$imgs_folder_title</p>";
    } else {
      $is_importing_images = get_boolean_readable_name($config->is_importing_images);
      $config_items .= "<p><strong>Необходимо импортировать изображения?: </strong>$is_importing_images</p>";
    }
    
    // Примеры интерьера
    if($config->is_importing_interrior_examples){
      $is_importing_interrior_examples = get_boolean_readable_name($config->is_importing_interrior_examples);
      $config_items .= "<p><strong>Необходимо импортировать примеры интерьеров?: </strong>$is_importing_interrior_examples</p>";

      // Получаем название папки с примерами интерьеров
      $interrior_examples_folder_node = node_load($config->folder_with_interrior_examples_images_nid);
      $interrior_examples_folder_title = $interrior_examples_folder_node->title;
      $config_items .= "<p><strong>Папка с примерами интерьеров: </strong>$interrior_examples_folder_title</p>";
    } else {
      $is_importing_interrior_examples = get_boolean_readable_name($config->is_importing_interrior_examples);
      $config_items .= "<p><strong>Необходимо импортировать примеры интерьеров?: </strong>$is_importing_interrior_examples</p>";
    }

    // Итоговая разметка
    $config_html_string = "
      <h2>$title</h2>
      <div style=\"border: 1px solid #ddd; margin: 15px 0; box-shadow: 0 0 10px rgba(0,0,0,.3); padding: 15px;\">
        $config_items
      </div>
      <p>
        <a href=\"/admin/hexi-config\" class=\"bd-button\" style=\"margin-top: 15px;\">Вернуться назад и изменить данные</a>
      </p>
    ";

    /*
      <p><strong>Колонка с названиями изображений: </strong>$image_column_index</p>
      <p><strong>Необходимо импортировать каталог: </strong>$is_importing_catalogue</p>
      <p><strong>Прайс содержит изображения: </strong>$is_importing_images</p>
      <p><strong>Номер ячейки с изображением: </strong>$image_column_index</p>
    */

    return $config_html_string;
  }

  if($config->operation_type == 'update_excel_data'){
    $title = 'Проверьте параметры обновления товаров';
    $is_import_catalogue_before = get_boolean_readable_name($update_config->is_import_catalogue_before);

    $update_str = "
      <h2>$title</h2>
      <div style=\"border: 1px solid #ddd; margin: 15px 0; box-shadow: 0 0 10px rgba(0,0,0,.3); padding: 15px;\">
        <p><strong>Что необходимо сделать: </strong>$operation_type</p>
        <p><strong>Тип товаров: </strong>$product_type</p>
        <p><strong>Начало обработки файла (номер строки файла Excel): </strong>$start_row</p>
        <p><strong>Конец обработки файла (номер строки файла Excel): </strong>$end_row</p>
        <p><strong>Основная категория продукции: </strong>$main_catalogue_category</p>
        <p><strong>Импортировался ли каталог ранее: </strong>$is_import_catalogue_before</p>
      </div>
      <p>
        <a href=\"/admin/hexi-config\" class=\"bd-button\" style=\"margin-top: 15px;\">Вернуться назад и изменить данные</a>
      </p>
    ";

    return $update_str;
  }
}

function hexi_print_page_title($title){
  echo "<h1>$title</h1>";
}

function hexi_print_styled_page_title($title){
  echo "
    <h1 style=\"color: #19A15F; font-size: 24px; line-height: 1.3; margin: 15px auto; text-align: center; font-weight: bold; max-width: 450px; border: 1px solid #19A15F; padding: 15px; box-shadow: 0 0 10px rgba(0,0,0,.3);\">
      $title
    </h1>
  ";
}

function show_total_rows_and_columns_count($total_rows, $total_columns){
  echo '<div class="info">';
  echo 'Total rows: ' . $total_rows . '<br>' . 'Total columns: ' . $total_columns;
  echo '<br>';
  echo '</div>';
}

function debug_data($data_array){
  echo '<div class="item">';
  foreach($data_array as $data_item){
    if(isset($data_item['title'])){
      echo '<p>' . $data_item['title'] . '</p>' . '<hr>';
    }
    
    echo '<pre>';
    var_dump($data_item);
    echo '</pre>';
    echo '<hr>';
  }
  echo '</div>';
}

function parse_product_columns_of_row($sheet, $row, $column, &$product_data_array, $counter){
  switch($column){

    // Название товара
    case 1:
      $product_title_cell = $sheet->getCellByColumnAndRow($column, $row);
      $product_title_cell_value = $product_title_cell->getValue();

      $title_str = fix_spaces_in_string($product_title_cell_value);
      $product_data_array['title'] = $title_str;
      break;

    // Фотография
    case 2:
      $product_data_array['img_cell'] = PHPExcel_Cell::stringFromColumnIndex($column) . $row;
      break;

    // Код товара
    case 3:
      $product_code_cell = $sheet->getCellByColumnAndRow($column, $row);
      $product_code_cell_value = $product_code_cell->getValue();
      
      $code_str = convert_RichText_to_string($product_code_cell_value);

      if(empty($code_str)){
        $product_data_array['code'] = generate_product_sku($counter);
      } else {
        $product_data_array['code'] = $code_str;
      }
      break;

    // Размер
    case 4:
      $product_size_cell = $sheet->getCellByColumnAndRow($column, $row);
      $product_size_cell_value = $product_size_cell->getValue();

      $size_str = '';
      $size_str = convert_RichText_to_string($product_size_cell_value);

      $product_data_array['size'] = $size_str;
      break;

    // Стоимость товара
    case 5:
      $product_price_cell = $sheet->getCellByColumnAndRow($column, $row);
      $product_data_array['price'] = intval(round($product_price_cell->getValue(), 0));
      break;
  }
}

function convert_RichText_to_string($cell_value){
  if($cell_value instanceof PHPExcel_RichText){
    $string = '';
    $string_elemets = $cell_value->getRichTextElements();

    foreach($string_elemets as $element){
      $string .= $element->getText();
    }

    $string = fix_spaces_in_string($string);
    return $string;
  } else {
    return fix_spaces_in_string($cell_value);
  }
}

function fix_spaces_in_string($string){
  $string = trim($string);
  $string = preg_replace('/\s+/', ' ', $string);
  return $string;
}

function parse_imgs_for_products_data($sheet_images_collection, &$products_data){
  $imgs_itterator = 0;

  foreach($sheet_images_collection as $image){
    $img_coords = $image->getCoordinates();
    $product_title;
    $product_img_cell;
    $product_code;

    foreach($products_data as &$product){
      if(array_search($img_coords, $product)){
        $product_title = $product['title'];
        $product_img_cell = $product['img_cell'];
        $product_code = $product['code'];

        $zipReader = fopen($image->getPath(), 'r');
        $imageContents = '';
        while (!feof($zipReader)) {
          $imageContents .= fread($zipReader, 1024);
        }
        fclose($zipReader);

        $extension = $image->getExtension();
        $myFileName = 'imgs/img_' .  ++$imgs_itterator  . '.' . $extension;
        $product['img_path'] = $myFileName;

        if(!file_exists($myFileName)){
          file_put_contents($myFileName, $imageContents);
        }
      }
    }

    // echo '<div class="item">' . $product_title . ': ' . $img_coords . '<span class="parent">' . $product_img . '.....' . $product_code . '</span></div>';
  }
}

function save_data_file($file_name, $data_array){
  $file = fopen($file_name, 'w');
  $file_text = serialize($data_array);
  file_put_contents($file_name, $file_text);
  fclose($file);
}

function get_data_from_data_file($file_name){
  $file_content = file_get_contents($file_name);
  $data_array = unserialize($file_content);
  return $data_array;
}

function show_products($products_data_array){
  echo '<div class="items">';
  echo '<div class="items__header"><h2>Товары</h2></div>';

  echo '<div class="items__content">';
  foreach($products_data_array as $product){
    echo '<div class="item">';

    echo '<p><strong>Название товара:</strong> ' . $product['title'] . '</p>';
    echo '<p><strong>Ячейка с изображением:</strong> ' . $product['img_cell'] . '</p>';
    echo '<p><strong>Путь к изображению:</strong> ' . $product['img_path'] . '</p>';
    echo '<p><strong>Изображение:</strong> ' . '<img src="' . $product['img_path'] . '">' . '</p>';
    echo '<p><strong>Код товара:</strong> ' . $product['code'] . '</p>';
    echo '<p><strong>Размер:</strong> ' . $product['size'] . '</p>';
    echo '<p><strong>Стоимость:</strong> ' . $product['price'] . '</p>';
    echo '<p class="parent"><strong>Категория каталога:</strong> ' . $product['category'] . '</p>';

    echo '</div>';
  }
  echo '</div>';

  echo '</div>';
}

function show_catalogue($catalogue_data_array){
    echo '<div class="items">';
    echo '<div class="items__header"><h2>Товары</h2></div>';

    echo '<div class="items__content">';
      foreach($catalogue_data_array as $category){
        if(!isset($category['parent_term'])){
          echo '<div class="item item-parent">';

          echo '<p><strong>Название категории:</strong> ' . $category['title'] . '</p>';

          echo '</div>';
        } else {
          echo '<div class="item item-child">';

          echo '<p><strong>Название категории:</strong> ' . $category['title'] . '</p>';
          echo '<p class="parent"><strong>Родительская категория:</strong> ' . $category['parent_term'] . '</p>';

          echo '</div>';
        }
        
      }
    echo '</div>';

    echo '</div>';
}

function generate_product_sku($seed){
  $current_time = time();
  $cutted_time = mb_strimwidth(strval($current_time), -5, 5);
  $product_sku = $seed . $cutted_time;

  return $product_sku;
}

function log_var($var){
  echo '<pre>';
  var_dump($var);
  echo '</pre>';
  echo '<hr>';
}

function print_paragraph($text, $color, $text_color = 'black'){
  echo '<p style="background-color:' . $color . '; padding: 7px; color:'. $text_color . '">' . $text . '</p>';
}

function taxonomy_get_vocabulary_by_name($vocabulary_name = NULL){
  if($vocabulary_name){
    $vocabularies = taxonomy_get_vocabularies();

    foreach($vocabularies as $vocabulary){
      if($vocabulary->name == $vocabulary_name){
        return $vocabulary;
        break;
      }
    }
  }
}

function get_product_types_form_options_array(){
  $product_types = commerce_product_types();
  $options = array();

  foreach($product_types as $type){
    $options[$type['type']] = $type['name'] . ' <em>(' . $type['type'] . ')</em>';
  }

  return $options;
}

function generate_catalogue_parents_form_options_array($vocab_name){
  $options = array();
  $vocabulary = taxonomy_get_vocabulary_by_name($vocab_name);
  $vocabulary_parent_terms = taxonomy_get_tree($vocabulary->vid, 0, 1, TRUE);

  foreach($vocabulary_parent_terms as $term){
    $childrens = taxonomy_get_children($term->tid);

    if(count($childrens) > 0){
      $options[$term->tid] = $term->name;
    }
  }

  return $options;
}

function generate_taxonomy_vocabularies_form_options(){
  $options = array();
  $vocabularies = taxonomy_get_vocabularies();

  foreach($vocabularies as $vocab){
    $vocab_terms = taxonomy_get_tree($vocab->vid);

    if(
      count($vocab_terms) > 0 && 
      ($vocab->name != 'Gallery collections' && $vocab->name != 'Теги' && $vocab->name != 'Каталог' && $vocab->name != 'Каталог продукции')
    ){
      $options[$vocab->vid] = $vocab->name;
    }
  }

  return $options;
}

function generate_catalogue_form_options_array($vocab_name){
  $options = array();
  $vocabulary = taxonomy_get_vocabulary_by_name($vocab_name);
  $vocabulary_parent_terms = taxonomy_get_tree($vocabulary->vid);
  
  foreach($vocabulary_parent_terms as $term){
    $options[$term->tid] =  str_repeat('-', $term->depth) . ' ' . $term->name;
  }

  return $options;
}

function get_selected_checkbox($values){
  $selected_value = NULL;

  foreach($values as $value){
    if(!empty($value)){
      $selected_value = $value;
    }
  }

  return $selected_value;
}

function get_excel_import_readable_operation_type($operation_type){
  switch($operation_type){
    case 'import_excel_data':
      return 'Импорт данных';
      break;
    
    case 'update_excel_data':
      return 'Обновление данных';
      break;
  }
}

function get_boolean_readable_name($boolean){
  return $boolean ? 'Да' : 'Нет';
}

function get_catalogue_category_cell_type_name($type){
  switch($type){
    case 'merged_cell':
      return 'Объединенная ячейка';
      break;

    case 'empty_cell':
      return 'Пустая ячейка';
      break;
  }
}

function get_taxonomy_term_name_by_tid($tid){
  $term = taxonomy_term_load($tid);
  return $term->name;
}

function get_upload_max_size(){
  $ini_upload_max_size = parse_size(ini_get("upload_max_filesize"));

  return format_size($ini_upload_max_size);
}

function get_image_contents_from_zip($path){
  $zipReader = fopen($path, 'r');
  $imageContents = '';
  while (!feof($zipReader)) {
    $imageContents .= fread($zipReader, 1024);
  }
  fclose($zipReader);

  return $imageContents;
}

function is_product_mashine_name($product_type_mashine_name = NULL){
  $available_product_types = commerce_product_types();

  if(array_key_exists($product_type_mashine_name, $available_product_types)){
    return TRUE;
  }
}

function delete_variable_from_db($name){
  $db_variable = variable_get($name);

  if(isset($db_variable)){
    variable_del($name);
  }
}


// BOOKS
function books_parse_product_columns_of_row($sheet, $row, $column, &$product_data_array){
  switch($column){
    case 0:
      $code_cell_value = intval(get_cell_value_by_column_and_row($column, $row, $sheet));

      $product_data_array['code'] = $code_cell_value;
      break;

    case 1:
      $code_of_analogue_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      if(!empty($code_of_analogue_cell_value)){
        $product_data_array['code_of_analogue'] = intval($code_of_analogue_cell_value);
      }
      break;

    case 2:
      $title_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['title'] = $title_cell_value;
      break;

    case 3:
      $publishing_house_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['publishing_house'] = $publishing_house_cell_value;
      break;

    case 4:
      $isbn_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['isbn'] = $isbn_cell_value;
      break;

    case 5:
      $year_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['year'] = $year_cell_value;
      break;

    case 6:
      $pages_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['pages'] = intval($pages_cell_value);
      break;

    case 7:
      $binding_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['binding'] = $binding_cell_value;
      break;

    case 8:
      $std_field_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['std'] = $std_field_value;
      break;
    
    case 10:
      $availability_in_publishing_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['availability_in_publishing'] = $availability_in_publishing_cell_value;
      break;
    
    case 11:
      $federal_list_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['federal_list'] = $federal_list_cell_value;
      break;

    case 12:
      $complect_sell_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['complect_sell'] = $complect_sell_cell_value;
      break;

    case 13:
      $special_offer_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['special_offer'] = $special_offer_cell_value;
      break;

    case 14:
      $price_cell_value = get_cell_value_by_column_and_row($column, $row, $sheet);

      $product_data_array['price'] = intval($price_cell_value);
      break;
  }
}

function get_cell_value_by_column_and_row($column, $row, $sheet){
  $cell = $sheet->getCellByColumnAndRow($column, $row);
  $cell_value = $cell->getValue();

  return convert_RichText_to_string($cell_value);
}