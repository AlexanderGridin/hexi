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
  fill_product_brand_field($product, $brand);
  // -- Коллекция
  fill_product_collection_field($product, $collection);
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