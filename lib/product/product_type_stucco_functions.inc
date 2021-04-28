<?php 
function fill_product_type_stucco_fields_from_row($product, $row){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $coating = $row['cells_data'][1];
  $collection = $row['cells_data'][2];
  $name = $row['cells_data'][3];
  $unique_id = $row['cells_data'][4];
  $description = $row['cells_data'][5];
  $country = $row['cells_data'][6];
  $product_appoint = $row['cells_data'][20];
  $product_appoint_interrior = $row['cells_data'][21];
  $price = intval(preg_replace('/\D/', '', $row['cells_data'][22])) * 100;

  // Устанавливаем соответствие полей
  // -- Название
  $product->title = $name;
  // -- Артикул
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

  // -- Коллекция
  $is_collection_on_site = is_collection_on_site($collection);

  if($is_collection_on_site){
    $collection_term = current(taxonomy_get_term_by_name($collection));
    $product->field_product_collection['und'][0]['tid'] = $collection_term->tid;
  }
  
  if(!$is_collection_on_site && !is_null($is_collection_on_site)){
    $new_collection_term = add_collection_on_site($collection);
    $product->field_product_collection['und'][0]['tid'] = $new_collection_term->tid;
  }

  // -- Назначение материала
  $product->field_product_appoint['und'] = get_appoint_field_values_from_string($product_appoint);
  // -- Назначение в интерьере
  $product->field_product_appoint_interrior['und'] = get_appoint_interrior_field_values_from_string($product_appoint_interrior);
  // -- Описание
  $product->field_product_description['und'][0]['value'] = $description;
  // -- Страна
  $product->field_product_country['und'][0]['value'] = $country;
  // -- Стоимость
  $product->commerce_price['und'][0]['amount'] = $price;
  // -- Покрытие
  $product->field_product_coating['und'][0]['value'] = $coating;

  return $product;
}