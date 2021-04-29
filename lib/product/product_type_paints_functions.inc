<?php 
function fill_product_type_paints_fields_from_row($product, $row){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $subcategory = $row['cells_data'][1];
  $name_and_short_desc = $row['cells_data'][2];
  $unique_id = $row['cells_data'][3];
  $volume = $row['cells_data'][4];
  $base = $row['cells_data'][5];
  $price = floatval($row['cells_data'][6]) * 100;
  $gloss_degree = $row['cells_data'][7];
  $resistance_to_wash = $row['cells_data'][8];
  $product_appoint = $row['cells_data'][9];
  $product_appoint_interrior = $row['cells_data'][10];
  $safe_for_children = $row['cells_data'][11];

  // Устанавливаем соответствие полей
  $product->title = $name_and_short_desc;
  $product->sku = $unique_id;

  // -- Бренд
  fill_product_brand_field($product, $brand);

  // -- Подраздел
  fill_product_type_paint_subcategory_field($product, $subcategory);

  // -- Назначение краски
  $product->field_product_appoint['und'] = get_appoint_field_values_from_string($product_appoint);

  // -- Назначение краски в интерьере
  $product->field_product_appoint_interrior['und'] = get_appoint_interrior_field_values_from_string($product_appoint_interrior);

  // -- Объем
  $product->field_product_volume['und'][0]['value'] = $volume;
  // -- База
  if(!empty($base)){
    $product->field_product_base['und'][0]['value'] = $base;
  } else {
    $product->field_product_base = NULL;
  }
  // -- Стоимость
  $product->commerce_price['und'][0]['amount'] = $price;
  // -- Степень блеска
  if(!empty($gloss_degree)){
    $product->field_product_gloss_degree['und'][0]['value'] = $gloss_degree;
  } else {
    $product->field_product_gloss_degree = NULL;
  }
  // -- Стойкость к мытью
  if(!empty($resistance_to_wash)){
    $product->field_product_resistance_to_wash['und'][0]['value'] = $resistance_to_wash;
  } else {
    $product->field_product_resistance_to_wash = NULL;
  }
  
  // -- Применение в детских лечебных учреждениях
  if(isset($safe_for_children) && !empty($safe_for_children)){
    $product->field_product_safe_for_children['und'][0]['value'] = 1;
  }

  return $product;
}

// Подразделы
function fill_product_type_paint_subcategory_field(&$product, $subcategory){
  $is_subcategory_on_site = is_paint_subcategory_on_site($subcategory);

  if($is_subcategory_on_site){
    $subcategory_term = current(taxonomy_get_term_by_name($subcategory));
    $product->field_product_subcategory['und'][0]['tid'] = $subcategory_term->tid;
  } 
  
  if(!$is_subcategory_on_site && !is_null($is_subcategory_on_site)){
    $new_subcategory_term = add_paint_subcategory_on_site($subcategory);
    $product->field_product_subcategory['und'][0]['tid'] = $new_subcategory_term->tid;
  }
}

function is_paint_subcategory_on_site($subcategory_name){
  return is_taxonomy_term_in_vocabulary($subcategory_name, 'paints_subcategories');
}

function add_paint_subcategory_on_site($subcategory_name){
  $paint_subcategories_vocabulary = taxonomy_get_vocabulary_by_name('Подразделы красок');

  return taxonomy_create_term_in_vocabulary($subcategory_name, $paint_subcategories_vocabulary->vid);
}