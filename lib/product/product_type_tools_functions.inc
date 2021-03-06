<?php 
function fill_product_type_tools_fields_from_row($product, $row){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $group = $row['cells_data'][1];
  $series = $row['cells_data'][2];
  $unique_id = $row['cells_data'][3];
  $name = $row['cells_data'][4];
  $description = $row['cells_data'][5];
  $country = $row['cells_data'][6];
  $size = $row['cells_data'][7];
  $price = floatval($row['cells_data'][8]) * 100;

  // Устанавливаем соответствие полей
  $product->title = '(' . $unique_id . ')' . ' - ' . $name;
  $product->sku = $unique_id;

  // -- Бренд
  fill_product_brand_field($product, $brand);
  // -- Группа
  fill_product_type_tools_group_field($product, $group);
  // -- Серия
  $product->field_tools_serial['und'][0]['value'] = $series;
  // -- Описание
  $product->field_product_description['und'][0]['value'] = $description;
  // -- Страна
  $product->field_product_country['und'][0]['value'] = $country;
  // -- Размер
  $product->field_tools_size['und'][0]['value'] = $size;
  // -- Стоимость
  $product->commerce_price['und'][0]['amount'] = $price;

  return $product;
}

// Группы
function fill_product_type_tools_group_field(&$product, $group){
  $is_tools_group_on_site = is_tools_group_on_site($group);

  if($is_tools_group_on_site){
    $group_term = current(taxonomy_get_term_by_name($group));
    $product->field_tools_group['und'][0]['tid'] = $group_term->tid;
  } 
  
  if(!$is_tools_group_on_site && !is_null($is_tools_group_on_site)){
    $new_group_term = add_tools_group_on_site($group);
    $product->field_tools_group['und'][0]['tid'] = $new_group_term->tid;
  }
}

function is_tools_group_on_site($group_name){
  return is_taxonomy_term_in_vocabulary($group_name, 'tools_groups');
}

function add_tools_group_on_site($group_name){
  $tools_groups_vocabulary = taxonomy_get_vocabulary_by_name('Группы инструментов');

  return taxonomy_create_term_in_vocabulary($group_name, $tools_groups_vocabulary->vid);
}