<?php 
// Группы
function is_tools_group_on_site($group_name){
  $group = taxonomy_get_term_by_name($group_name, 'tools_groups');

  if(count($group) == 1){
    return true;
  }

  if(count($group) == 0){
    return false;
  }
}

function add_tools_group_on_site($group_name){
  $tools_groups_vocabulary = taxonomy_get_vocabulary_by_name('Группы инструментов');

  $group = (object) array(
    'vid' => $tools_groups_vocabulary->vid, 
    'name' => $group_name,
  );

  taxonomy_term_save($group);
  return $group;
}

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
  $is_brand_on_site = is_brand_on_site($brand);

  if($is_brand_on_site){
    $brand_term = current(taxonomy_get_term_by_name($brand));
    $product->field_product_brand['und'][0]['tid'] = $brand_term->tid;
  } 

  if(!$is_brand_on_site && !is_null($is_brand_on_site)){
    $new_brand_term = add_brand_on_site($brand);
    $product->field_product_brand['und'][0]['tid'] = $new_brand_term->tid;
  }

  // -- Группа
  $is_tools_group_on_site = is_tools_group_on_site($group);

  if($is_tools_group_on_site){
    $group_term = current(taxonomy_get_term_by_name($group));
    $product->field_tools_group['und'][0]['tid'] = $group_term->tid;
  } 
  
  if(!$is_tools_group_on_site && !is_null($is_tools_group_on_site)){
    $new_group_term = add_tools_group_on_site($group);
    $product->field_tools_group['und'][0]['tid'] = $new_group_term->tid;
  }

  // -- Серия
  $product->field_tools_serial['und'][0]['value'] = $series;
  // -- Описание
  $product->field_product_description['und'][0]['value'] = $description;
  // -- Страна
  $product->field_tools_country['und'][0]['value'] = $country;
  // -- Размер
  $product->field_tools_size['und'][0]['value'] = $size;
  // -- Стоимость
  $product->commerce_price['und'][0]['amount'] = $price;

  return $product;
}