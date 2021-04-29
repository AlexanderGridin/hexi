<?php 
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

function is_brand_on_site($brand_name){
  return is_taxonomy_term_in_vocabulary($brand_name, 'product_brands');
}

function add_brand_on_site($brand_name){
  $brands_vocabulary = taxonomy_get_vocabulary_by_name('Бренды');

  return taxonomy_create_term_in_vocabulary($brand_name, $brands_vocabulary->vid);
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

function is_visible_color_on_site($color_name){
  return is_taxonomy_term_in_vocabulary($color_name, 'product_visible_colors');
}

function add_visible_color_on_site($color_name){
  $vocabulary = taxonomy_get_vocabulary_by_name('Видимые цвета');

  return taxonomy_create_term_in_vocabulary($color_name, $vocabulary->vid);
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

function is_appoint_on_site($appoint){
  return is_taxonomy_term_in_vocabulary($appoint, 'product_appointments');
}

function add_appoint_on_site($appoint){
  $appoints_voc = taxonomy_get_vocabulary_by_name('Назначения продукции');

  return taxonomy_create_term_in_vocabulary($appoint, $appoints_voc->vid);
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

function is_appoint_interrior_on_site($appoint){
  return is_taxonomy_term_in_vocabulary($appoint, 'product_appointments_interior');
}

function add_appoint_interrior_on_site($appoint){
  $appoints_voc = taxonomy_get_vocabulary_by_name('Назначения продукции в интерьере');

  return taxonomy_create_term_in_vocabulary($appoint, $appoints_voc->vid);
}