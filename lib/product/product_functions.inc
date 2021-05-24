<?php 
function get_videos_array_from_string_of_url($str){
  $urls_array = explode(' ', $str);
  $videos_array = array();

  foreach($urls_array as $url){
    $video = array();
    $exploded_url = explode('&', $url);
    $video['input'] = $exploded_url[0];
    $exploded_url = explode('=', $exploded_url[0]);
    $video['video_id'] = $exploded_url[1];

    array_push($videos_array, $video);
  }

  if(count($videos_array) > 0){
    return $videos_array;
  } else {
    return NULL;
  }
}

function get_imgs_from_string_of_names($str, $photos_folder_nid, $separator = ' '){
  $files = array();
  $names = explode($separator, $str);

  if(count($names) > 0){
    foreach($names as $name){
      array_push($files, (array)get_img_by_orig_name($name, $photos_folder_nid));
    }

    return $files;
  } else {
    return NULL;
  }
}

function get_img_by_orig_name($name, $photos_folder_nid){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'file')
    ->fieldCondition('field_img_source_name', 'value', $name, 'CONTAINS')
    ->fieldCondition('field_photo_folder_id', 'value', $photos_folder_nid, '=')
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } 
  
  if(count($entities) == 1){
    $file = NULL;

    foreach($entities['file'] as $preloaded_file){
      $file = file_load($preloaded_file->fid);
      $exploded_file_source_name = explode('.', $file->field_img_source_name['und'][0]['value']);

      if($exploded_file_source_name[0] == $name){
        return $file;
      }
    }
  }
}

function get_documents_from_string_of_names($str, $folder_nid, $separator = ' '){
  $files = array();
  $names = explode($separator, $str);

  if(count($names) > 0){
    foreach($names as $name){
      array_push($files, (array)get_document_by_orig_name($name, $folder_nid));
    }

    return $files;
  } else {
    return NULL;
  }
}

function get_document_by_orig_name($name, $folder_nid){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'file')
    ->fieldCondition('field_img_source_name', 'value', $name, 'CONTAINS')
    ->fieldCondition('field_photo_folder_id', 'value', $folder_nid, '=')
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } 
  
  if(count($entities) == 1){
    $file = NULL;

    foreach($entities['file'] as $preloaded_file){
      $file = file_load($preloaded_file->fid);
      $exploded_file_source_name = explode('.', $file->field_img_source_name['und'][0]['value']);

      if($exploded_file_source_name[0] == $name){
        $file->display = '1';
        $file->description = '';

        return $file;
      }
    }
  }
}

// Дизайн
function get_design_field_values_from_string($str){
  if(!empty($str)){
    $design_names = explode('/', $str);
    $values = array();

    foreach($design_names as $design){
      $is_design_on_site = is_design_on_site($design);

      if($is_design_on_site){
        $design_term = current(taxonomy_get_term_by_name($design));
        array_push($values, array(
          'tid' => $design_term->tid,
        ));
      }

      if(!$is_design_on_site && !is_null($is_design_on_site)){
        $new_design = add_design_on_site($design);
        array_push($values, array(
          'tid' => $new_design->tid,
        ));
      }
    }

    return $values;
  }
}

function is_design_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'product_design');
}

function add_design_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Дизайны');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Cтили продукции
function fill_product_style_field(&$product, $style){
  $is_product_style_on_site = is_product_style_on_site($style);

  if($is_product_style_on_site){
    $style_term = current(taxonomy_get_term_by_name($style));
    $product->field_product_style['und'][0]['tid'] = $style_term->tid;
  }
  
  if(!$is_product_style_on_site && !is_null($is_product_style_on_site)){
    $new_style_term = add_product_style_on_site($style);
    $product->field_product_style['und'][0]['tid'] = $new_style_term->tid;
  }

  return $product;
}

function is_product_style_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'product_styles');
}

function add_product_style_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Стили продукции');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Коллекции
function fill_product_collection_field(&$product, $collection){
  $is_collection_on_site = is_collection_on_site($collection);

  if($is_collection_on_site){
    $collection_term = current(taxonomy_get_term_by_name($collection));
    $product->field_product_collection['und'][0]['tid'] = $collection_term->tid;
  }
  
  if(!$is_collection_on_site && !is_null($is_collection_on_site)){
    $new_collection_term = add_collection_on_site($collection);
    $product->field_product_collection['und'][0]['tid'] = $new_collection_term->tid;
  }

  return $product;
}

function is_collection_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'manufacturer_collections');
}

function add_collection_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Коллекции производителей');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Бренды
function fill_product_brand_field(&$product, $brand){
  $is_brand_on_site = is_brand_on_site($brand);

  if($is_brand_on_site){
    $brand_term = current(taxonomy_get_term_by_name($brand));
    $product->field_product_brand['und'][0]['tid'] = $brand_term->tid;
  } 

  if(!$is_brand_on_site && !is_null($is_brand_on_site)){
    $new_brand_term = add_brand_on_site($brand);
    $product->field_product_brand['und'][0]['tid'] = $new_brand_term->tid;
  }

  return $product;
}

function is_brand_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'product_brands');
}

function add_brand_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Бренды');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Видимые цвета
function get_visible_colors_field_values_from_string($str){
  if(!empty($str)){
    $colors_names = explode('/', $str);
    $values = array();

    foreach($colors_names as $color){
      $is_visible_color_on_site = is_visible_color_on_site($color);

      if($is_visible_color_on_site){
        $visible_color_term = current(taxonomy_get_term_by_name($color));
        array_push($values, array(
          'tid' => $visible_color_term->tid,
        ));
      }

      if(!$is_visible_color_on_site && !is_null($is_visible_color_on_site)){
        $new_color = add_visible_color_on_site($color);
        array_push($values, array(
          'tid' => $new_color->tid,
        ));
      }
    }

    return $values;
  }
}

function is_visible_color_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'product_visible_colors');
}

function add_visible_color_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Видимые цвета');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Назначения продукции
function get_appoint_field_values_from_string($str){
  if(!empty($str)){
    $appoint_names = explode('/', $str);
    $values = array();

    foreach($appoint_names as $appoint){
      $is_appoint_on_site = is_appoint_on_site($appoint);

      if($is_appoint_on_site){
        $appoint_term = current(taxonomy_get_term_by_name($appoint));
        array_push($values, array(
          'tid' => $appoint_term->tid,
        ));
      }

      if(!$is_appoint_on_site && !is_null($is_appoint_on_site)){
        $new_appoint = add_appoint_on_site($appoint);
        array_push($values, array(
          'tid' => $new_appoint->tid,
        ));
      }
    }

    return $values;
  }
}

function is_appoint_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'product_appointments');
}

function add_appoint_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Назначения продукции');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}

// Назначения продукции в интерьере
function get_appoint_interrior_field_values_from_string($str){
  if(!empty($str)){
    $appoint_names = explode('/', $str);
    $values = array();

    foreach($appoint_names as $appoint){
      $is_appoint_on_site = is_appoint_interrior_on_site($appoint);

      if($is_appoint_on_site){
        $appoint_term = current(taxonomy_get_term_by_name($appoint));
        array_push($values, array(
          'tid' => $appoint_term->tid,
        ));
      }

      if(!$is_appoint_on_site && !is_null($is_appoint_on_site)){
        $new_appoint = add_appoint_interrior_on_site($appoint);
        array_push($values, array(
          'tid' => $new_appoint->tid,
        ));
      }
    }

    return $values;
  }
}

function is_appoint_interrior_on_site($name){
  return is_taxonomy_term_in_vocabulary($name, 'product_appointments_interior');
}

function add_appoint_interrior_on_site($name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Назначения продукции в интерьере');

  return taxonomy_create_term_in_vocabulary($name, $vocabulary->vid);
}