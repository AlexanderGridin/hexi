<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/product/product_functions');
module_load_include('inc', 'hexi', '/lib/product/product_type_tools_functions');
module_load_include('inc', 'hexi', '/lib/product/product_type_paints_functions');
module_load_include('inc', 'hexi', '/lib/product/product_type_stucco_functions');
module_load_include('inc', 'hexi', '/lib/product/product_type_carpet_functions');
module_load_include('inc', 'hexi', '/lib/product/product_type_wallpapers_functions');

// Инициализация импорта
function import_parsed_data(){
  $import_config = variable_get('hexi_import_config');
  $file_data = variable_get('hexi_file_data');

  foreach($file_data as $row){
    $operations[] = array('import_data', array($import_config, $row));
  }

  $batch = array(
    'operations' => $operations,
    'finished' => 'import_parsed_data_finished',
    'title' => 'Обработка данных',
    'init_message' => 'Подготовка данных',
    'progress_message' => 'Выполнено @current из @total.',
    'error_message' => 'Произошла ошибка.',
    'file' => drupal_get_path('module', 'hexi') . '/lib/import_parsed_data.inc',
  );

  batch_set($batch);
  batch_process('/hexi-data-processing-finished');
}

// Единичная операция импорта
function import_data($import_config, $row, &$context){
  // Создаем товары и их ноды
  if(!empty($row['cells_data'][0])){
    create_product($import_config, $row);
    create_product_display($import_config, $row);

    $context['results']['proceeded_products']++;
  }

  $context['results']['proceeded_rows']++;
  $context['message'] = 'Обработана строка <em><strong>' . $context['results']['proceeded_rows'] . '</strong></em>';
}

// Окончание импорта
function import_parsed_data_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Обработано ' . $results['proceeded_rows'] . ' строк');
    drupal_set_message('Из них ' . $results['proceeded_products'] . ' товаров');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}

// Создание товара
function create_product($import_config, $row){
  $import_id = 'hexi_import_' . $import_config->filename;
  $currency_code = 'RUB';

  // Подготавливаем объект товара для заполнения
  $product = commerce_product_new();

  // Заполняем поля в зависимости от типа товара
  if($import_config->product_type == 'product_tools'){
    $product = fill_product_type_tools_fields_from_row($product, $row, $import_config);
  }

  if($import_config->product_type == 'product_paints'){
    $product = fill_product_type_paints_fields_from_row($product, $row);
  }

  if($import_config->product_type == 'stucco'){
    $product = fill_product_type_stucco_fields_from_row($product, $row, $import_config);
  }
  
  if($import_config->product_type == 'product_carpet'){
    $product = fill_product_type_carpet_fields_from_row($product, $row);
  }

  if($import_config->product_type == 'product_wallpapers'){
    $product = fill_product_type_wallpapers_fields_from_row($product, $row);
  }

  // Заполняем общие поля
  $product->type = $import_config->product_type;
  $product->field_product_import_id['und'][0]['value'] = $import_id;
  $product->commerce_price['und'][0]['currency_code'] = $currency_code;

  // Сохраняем товар
  commerce_product_save($product);
}

// Создание ноды товара
function create_product_display($import_config, $row){
  $product = NULL;

  // Получаем товар в зависимости от типа товара в конфиге
  switch($import_config->product_type){
    case 'product_tools':
      $product = commerce_product_load_by_sku($row['cells_data'][3]);
      break;

    case 'product_paints':
      $product = commerce_product_load_by_sku($row['cells_data'][3]);
      break;

    case 'stucco':
      $product = commerce_product_load_by_sku($row['cells_data'][4]);
      break;

    case 'product_carpet':
      $product = commerce_product_load_by_sku($row['cells_data'][6]);
      break;

    case 'product_wallpapers':
      $product = commerce_product_load_by_sku($row['cells_data'][2]);
      break;
  }

  // Если товар есть на сайте и это не ковер - создаем ноду, содержащую ссылку только на один товар
  if(isset($product) && $import_config->product_type != 'product_carpet'){
    create_display_for_single_product($product, $import_config);
  }

  // Если товар есть на сайте и это ковер - разбираемся с этой ситуацией
  if(isset($product) && $import_config->product_type == 'product_carpet'){
    handle_display_for_groupped_product($product, $import_config);
  }
}

function handle_display_for_groupped_product($product, $import_config){
  $import_id = 'hexi_import_' . $import_config->filename;
  $node_type = 'product_view';
  $products_group_sku = $product->field_product_group_sku['und'][0]['value'];
  $is_products_group_node_on_site = is_products_group_node_on_site($product);

  if($is_products_group_node_on_site){
    $product_node = get_products_group_display_by_products_group_id($products_group_sku);
    $product_reference = array(
      'product_id' => $product->product_id
    );

    array_push($product_node->field_artikul['und'], $product_reference);
    node_save($product_node);
  }

  if(!$is_products_group_node_on_site){
    $product_reference = array(
      'product_id' => $product->product_id
    );

    // Генерируем отражение товара
    $node = new stdClass();
    $node->type = $node_type;
    $category = new stdClass();

    node_object_prepare($node);

    // Получаем категорию каталога
    $category->tid = $import_config->main_catalogue_category;

    // Получаем название товара
    $product_title = $product->title;

    // Заполняем поля
    $node->title = $product_title;
    $node->field_artikul['und'][0] = $product_reference;
    $node->field_products_group_sku['und'][0]['value'] = $product->field_product_group_sku['und'][0]['value'];
    $node->field_product_category['und'][0]['tid'] = $category->tid;
    $node->field_product_import_id['und'][0]['value'] = $import_id;
    $node->language = LANGUAGE_NONE;

    // Сохраняем отражение товара
    node_save($node);
  }
}

function is_products_group_node_on_site($product){
  $products_group_sku = $product->field_product_group_sku['und'][0]['value'];

  // Запрашиваем ноду товара
  $query = new EntityFieldQuery();
  $product_display = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'product_view')
    ->fieldCondition('field_products_group_sku', 'value', $products_group_sku, '=')
    ->execute();

  if(count($product_display) > 0 && count($product_display['node'] == 1)){
    return true;
  }

  if(count($product_display) == 0){
    return false;
  }
}

function get_products_group_display_by_products_group_id($products_group_id){
  // Запрашиваем ноду товара
  $query = new EntityFieldQuery();
  $product_display = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'product_view')
    ->fieldCondition('field_products_group_sku', 'value', $products_group_id, '=')
    ->execute();

  if(count($product_display) > 0 && count($product_display['node'] == 1)){
    $product_display = current($product_display['node']);
    $product_display = node_load($product_display->nid);
    return $product_display;
  } else {
    return NULL;
  }
}

function create_display_for_single_product($product, $import_config){
  $production = false;
  $import_id = 'hexi_import_' . $import_config->filename;
  $node_type = 'product_view';

  // Генерируем отражение товара
  $node = new stdClass();
  $node->type = $node_type;
  $category = new stdClass();

  node_object_prepare($node);

  // Получаем категорию каталога
  $category->tid = $import_config->main_catalogue_category;

  // Получаем название товара
  $product_title = $product->title;

  // Устанавливаем блок с дополнительной информацией
  if($production){
    switch($import_config->product_type){
      case 'product_tools':
        break;

      case 'product_paints':

        break;

      case 'stucco':
          $node->field_color_texture_info['und'][0]['moddelta'] = 'block:32';
        break;

      case 'product_carpet':

        break;

      case 'product_wallpapers':

        break;
    }
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

