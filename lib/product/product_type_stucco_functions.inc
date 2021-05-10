<?php 
function fill_product_type_stucco_fields_from_row($product, $row, $import_config){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $coating = $row['cells_data'][1];
  $collection = $row['cells_data'][2];
  $name = $row['cells_data'][3];
  $unique_id = $row['cells_data'][4];
  $description = $row['cells_data'][5];
  $country = $row['cells_data'][6];
  $product_appoint = $row['cells_data'][10];
  $product_appoint_interrior = $row['cells_data'][11];
  $price = intval(preg_replace('/\D/', '', $row['cells_data'][12])) * 100;
  $photos_names = $row['cells_data'][7];
  $photos_folder_nid = $import_config->folder_with_images_nid;
  $interrior_examples_names = $row['cells_data'][8];
  $interrior_examples_folder_nid = $import_config->folder_with_interrior_examples_images_nid;
  $videos_url_str = $row['cells_data'][9];

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
  // Фотографии
  if($import_config->is_importing_images){
    if(!empty($photos_names)){
      $product_images_array = get_imgs_from_string_of_names($photos_names, $photos_folder_nid);
      $product->field_product_photo['und'] = $product_images_array;
    }
  }
  // Примеры интерьеров
  if($import_config->is_importing_interrior_examples){
    if(!empty($interrior_examples_names)){
      $interrior_examples_images_array = get_imgs_from_string_of_names($interrior_examples_names, $interrior_examples_folder_nid);
      $product->field_interriors_examples['und'] = $interrior_examples_images_array;
    }
  }
  // Видеообзор
  if($import_config->is_importing_video){
    if(!empty($videos_url_str)){
      $videos_array = get_videos_array_from_string_of_url($videos_url_str);
      $product->field_video_review['und'] = $videos_array;
    }
  }

  return $product;
}