<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/product/product_functions');
module_load_include('inc', 'hexi', '/lib/product/product_type_tools_functions');

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
  batch_process('/hexi-data-processing-finished');
}

// Единичная операция импорта
function import_processing($import_config, $row, &$context){
  // Создаем товары и их ноды
  if(!empty($row['cells_data'][0])){
    create_product($import_config, $row);
    // create_product_display($import_config, $row);

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

// 
function create_product($import_config, $row){
  $import_id = 'hexi_import_' . $import_config->filename;
  $currency_code = 'RUB';
  $product_price = 0;

  // Подготавливаем объект товара для заполнения
  $product = commerce_product_new();

  /* -------------------------------- */
  /* Заполняем поля в зависимости от типа товара
  /* -------------------------------- */
  if($import_config->product_type == 'product_tools'){
    // Идентифицируем поля
    $brand = $row['cells_data'][0];
    $group = $row['cells_data'][1];
    $series = $row['cells_data'][2];
    $unique_id = $row['cells_data'][3];
    $name = $row['cells_data'][4];
    $description = $row['cells_data'][5];
    $country = $row['cells_data'][6];
    $size = $row['cells_data'][7];
    $price = floatval($row['cells_data'][8]);

    // Обрабатываем стоимость товара
    $product_price = $price * 100;

    // Устанавливаем соответствие полей
    $product->title = $name;
    $product->sku = $unique_id;

    // Бренд
    $is_brand_on_site = is_brand_on_site($brand);

    if($is_brand_on_site){
      $brand_term = current(taxonomy_get_term_by_name($brand));
      $product->field_product_brand['und'][0]['tid'] = $brand_term->tid;
    } 

    if(!$is_brand_on_site && !is_null($is_brand_on_site)){
      $new_brand_term = add_brand_on_site($brand);
      $product->field_product_brand['und'][0]['tid'] = $new_brand_term->tid;
    }

    // Группа
    $is_tools_group_on_site = is_tools_group_on_site($group);

    if($is_tools_group_on_site){
      $group_term = current(taxonomy_get_term_by_name($group));
      $product->field_tools_group['und'][0]['tid'] = $group_term->tid;
    } 
    
    if(!$is_tools_group_on_site && !is_null($is_tools_group_on_site)){
      $new_group_term = add_tools_group_on_site($group);
      $product->field_tools_group['und'][0]['tid'] = $new_group_term->tid;
    }

    // Серия
    $product->field_tools_serial['und'][0]['value'] = $series;
    // Описание
    $product->field_product_description['und'][0]['value'] = $description;
    // Страна
    $product->field_tools_country['und'][0]['value'] = $country;
    // Размер
    $product->field_tools_size['und'][0]['value'] = $size;
  }

  // Заполняем общие поля
  $product->field_product_import_id['und'][0]['value'] = $import_id;
  $product->type = $import_config->product_type;
  $product->commerce_price['und'][0]['amount'] = $product_price;
  $product->commerce_price['und'][0]['currency_code'] = $currency_code;

  // Сохраняем товар
  commerce_product_save($product);
}

/*
function create_product_display($import_config, $row, $context){
  $import_id = 'vesta_excel_import_' . $import_config->filename;
  $node_type = 'product_view';
  $product = commerce_product_load_by_sku($row['cells_data'][0]);

  if($product){
    // Генерируем отражение товара
    $node = new stdClass();
    $node->type = $node_type;
    $category = new stdClass();

    node_object_prepare($node);

    // Получаем категорию каталога
    if(isset($context['results']['product_category_tid'])){
      $category->tid = $context['results']['product_category_tid'];
    } else {
      $category->tid = $import_config->main_catalogue_category;
    }

    // Получаем название товара в зависимости от типа товара
    if($import_config->product_type == 'sport_equipment'){
      $product_title = $row['cells_data'][2];
    }

    if($import_config->product_type == 'preschool_furniture'){
      $product_title = $row['cells_data'][1];
    }

    if($import_config->product_type == 'school_furniture'){
      // Обрабатываем название товара
      $product_exploded_title = explode('.', $row['cells_data'][1]);

      if(count($product_exploded_title) > 1){
        $product_title = $product_exploded_title[0];
      } else {
        $product_title = $row['cells_data'][1];
      }
    }

    if($import_config->product_type == 'literature'){
      $product_title = $row['cells_data'][1];
    }

    // Заполняем поля
    $node->title = $product_title;
    $node->field_artikul['und'][0]['product_id'] = $product->product_id;
    $node->field_product_category['und'][0]['tid'] = $category->tid;
    $node->field_product_import_id['und'][0]['value'] = $import_id;
    $node->language = LANGUAGE_NONE;

    // Сохраняем отражение товара
    node_save($node);
  }
}
*/

