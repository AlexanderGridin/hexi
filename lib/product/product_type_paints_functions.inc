<?php 
function fill_product_type_paints_fields_from_row($product, $row, $import_config){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $group = $row['cells_data'][1];
  $country = $row['cells_data'][2];
  $name_and_short_desc = $row['cells_data'][3];
  $series = $row['cells_data'][4];
  $unique_id = $row['cells_data'][5];
  $volume = $row['cells_data'][6];
  $other_volumes = $row['cells_data'][7];
  $base = $row['cells_data'][8];
  $price = floatval($row['cells_data'][9]) * 100;
  $gloss_degree = $row['cells_data'][10];
  $resistance_to_wash = $row['cells_data'][11];
  $product_appoint = $row['cells_data'][12];
  $product_appoint_interrior = $row['cells_data'][13];
  $safe_for_children = $row['cells_data'][14];

  $photos_names = $row['cells_data'][15];
  $photos_folder_nid = $import_config->folder_with_images_nid;

  // Устанавливаем соответствие полей
  $product->title = $name_and_short_desc;
  $product->sku = $unique_id;

  // -- Бренд
  fill_product_brand_field($product, $brand);

  // -- Группа
  fill_product_type_paint_subcategory_field($product, $group);

  // -- Страна
  $product->field_product_country['und'][0]['value'] = $country;

  // -- Серия
  fill_product_type_wallpaper_series_field($product, $series);

  // -- Назначение краски
  $product->field_product_appoint['und'] = get_appoint_field_values_from_string($product_appoint);

  // -- Назначение краски в интерьере
  $product->field_product_appoint_interrior['und'] = get_appoint_interrior_field_values_from_string($product_appoint_interrior);

  // -- Объем
  $product->field_product_volume['und'][0]['value'] = $volume;
  // -- Другие объемы
  $product->field_product_other_volumes['und'][0]['value'] = $other_volumes;
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

  // -- Фотографии
  if($import_config->is_importing_images){
    if(!empty($photos_names)){
      $product_images_array = get_imgs_from_string_of_names($photos_names, $photos_folder_nid);
      $product->field_product_photo['und'] = $product_images_array;
    }
  }

  return $product;
}

// Серии
function fill_product_type_wallpaper_series_field(&$product, $series){
  $is_series_on_site = is_wallpaper_series_on_site($series);

  if($is_series_on_site){
    $series_term = current(taxonomy_get_term_by_name($series));
    $product->field_product_wallpaper_series['und'][0]['tid'] = $series_term->tid;
  } 
  
  if(!$is_series_on_site && !is_null($is_series_on_site)){
    $new_series_term = add_wallpaper_series_on_site($series);
    $product->field_product_wallpaper_series['und'][0]['tid'] = $new_series_term->tid;
  }
}

function is_wallpaper_series_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'wallpapers_series');
}

function add_wallpaper_series_on_site($name){
  $wallpaper_series_vocabulary = taxonomy_get_vocabulary_by_name('Серии обоев');

  return taxonomy_create_term_in_vocabulary($name, $wallpaper_series_vocabulary->vid);
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