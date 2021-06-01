<?php 
function fill_product_type_wallpapers_fields_from_row($product, $row, $import_config){
  // Идентифицируем поля
  $brand = $row['cells_data'][0];
  $collection = $row['cells_data'][1];
  $unique_id = $row['cells_data'][2];
  $price = intval($row['cells_data'][3]) * 100;
  $width = $row['cells_data'][4];
  $length = $row['cells_data'][5];
  $type = $row['cells_data'][6];
  $rapport = $row['cells_data'][7];
  $design = $row['cells_data'][8];
  $name = $row['cells_data'][9] . " $unique_id коллекция $collection";
  $style = $row['cells_data'][10];
  $material = $row['cells_data'][11];
  $visible_color = $row['cells_data'][12];
  $country = $row['cells_data'][13];

  $photos_names = $row['cells_data'][14];
  $photos_folder_nid = $import_config->folder_with_images_nid;


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
  // -- Страна
  $product->field_product_country['und'][0]['value'] = $country;
  // -- Стоимость
  $product->commerce_price['und'][0]['amount'] = $price;
  // -- Видимый цвет
  $product->field_product_visible_color['und'] = get_visible_colors_field_values_from_string($visible_color);
  // -- Ширина
  $product->field_product_width['und'][0]['value'] = $width;
  // -- Длина
  $product->field_product_length['und'][0]['value'] = $length;
  // -- Материал
  $product->field_product_material['und'][0]['value'] = $material;
  // -- Раппорт
  $product->field_product_rapport['und'][0]['value'] = $rapport;
  // -- Дизайн
  $product->field_product_design['und'] = get_design_field_values_from_string($design);
  // -- Тип
  fill_wallpapers_type_field($product, $type);
  // Фотографии
  if($import_config->is_importing_images){
    if(!empty($photos_names)){
      $product_images_array = get_imgs_from_string_of_names($photos_names, $photos_folder_nid, "; ");
      $product->field_product_photo['und'] = $product_images_array;
    }
  }
  // -- Материал
  fill_wallpapers_material_field($product, $material);

  return $product;
}

// Материал
function fill_wallpapers_material_field(&$product, $maetrial){
  $is_material_on_site = is_wallpaper_material_on_site($maetrial);

  if($is_material_on_site){
    $material_term = current(taxonomy_get_term_by_name($maetrial));
    $product->field_product_material['und'][0]['tid'] = $material_term->tid;
  }
  
  if(!$is_material_on_site && !is_null($is_material_on_site)){
    $new_material_term = add_wallpaper_material_on_site($maetrial);
    $product->field_product_material['und'][0]['tid'] = $new_material_term->tid;
  }

  return $product;
}

function is_wallpaper_material_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'wallpapers_materials');
}

function add_wallpaper_material_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Материалы обоев');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Типы обоев
function fill_wallpapers_type_field(&$product, $type){
  $is_wallpaper_type_on_site = is_wallpaper_type_on_site($type);

  if($is_wallpaper_type_on_site){
    $type_term = current(taxonomy_get_term_by_name($type));
    $product->field_product_wallpaper_type['und'][0]['tid'] = $type_term->tid;
  }
  
  if(!$is_wallpaper_type_on_site && !is_null($is_wallpaper_type_on_site)){
    $new_type_term = add_wallpaper_type_on_site($type);
    $product->field_product_wallpaper_type['und'][0]['tid'] = $new_type_term->tid;
  }

  return $product;
}

function is_wallpaper_type_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'wallpapers_types');
}

function add_wallpaper_type_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Типы обоев');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}