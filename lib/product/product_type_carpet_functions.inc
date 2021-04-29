<?php 
function fill_product_type_carpet_fields_from_row($product, $row){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $collection = $row['cells_data'][1];
  $composition = $row['cells_data'][2];
  $style = $row['cells_data'][3];
  // $name = $row['cells_data'][4];
  $size = $row['cells_data'][4];
  $group_unique_id = $row['cells_data'][5];
  $unique_id = $row['cells_data'][6];
  $country = $row['cells_data'][7];
  $visible_color = $row['cells_data'][8];
  $width = intval($row['cells_data'][9]) / 100; //получаем ширину в метрах
  $length = intval($row['cells_data'][10]) / 100; //получаем длину в метрах
  $form = $row['cells_data'][11];
  $price = intval($row['cells_data'][12]) * 100;
  $name = "$brand $group_unique_id ($size) коллекция $collection";


  // Устанавливаем соответствие полей
  // -- Название
  $product->title = $name;
  // -- Артикул
  $product->sku = $unique_id;
  // -- Бренд
  fill_product_brand_field($product, $brand);
  // -- Коллекция
  fill_product_collection_field($product, $collection);
  // -- Стиль
  fill_product_style_field($product, $style);
  // -- Размер
  fill_carpet_size_field($product, $size);
  // -- Страна
  $product->field_product_country['und'][0]['value'] = $country;
  // -- Стоимость
  $product->commerce_price['und'][0]['amount'] = $price;
  // -- Артикул группы товаров
  $product->field_product_group_sku['und'][0]['value'] = $group_unique_id;
  // -- Видимый цвет
  $product->field_product_visible_color['und'] = get_visible_colors_field_values_from_string($visible_color);
  // -- Ширина
  $product->field_product_width['und'][0]['value'] = $width;
  // -- Длина
  $product->field_product_length['und'][0]['value'] = $length;
  // -- Форма
  $product->field_product_form['und'][0]['value'] = $form;
  // -- Состав
  $product->field_product_composition['und'][0]['value'] = $composition;

  return $product;
}

// Размер ковра
function fill_carpet_size_field(&$product, $size){
  $is_carpet_size_on_site = is_carpet_size_on_site($size);

  if($is_carpet_size_on_site){
    $size_term = current(taxonomy_get_term_by_name($size));
    $product->field_product_carpet_size['und'][0]['tid'] = $size_term->tid;
  }
  
  if(!$is_carpet_size_on_site && !is_null($is_carpet_size_on_site)){
    $new_size_term = add_carpet_size_on_site($size);
    $product->field_product_carpet_size['und'][0]['tid'] = $new_size_term->tid;
  }

  return $product;
}

function is_carpet_size_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'carpets_sizes');
}

function add_carpet_size_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Размеры ковров');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}