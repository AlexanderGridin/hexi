<?php 
// module_load_include('inc', 'hexi', '/lib/hexi_tools');

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
  $is_brand_on_site = is_brand_on_site($brand);

  if($is_brand_on_site){
    $brand_term = current(taxonomy_get_term_by_name($brand));
    $product->field_product_brand['und'][0]['tid'] = $brand_term->tid;
  } 

  if(!$is_brand_on_site && !is_null($is_brand_on_site)){
    $new_brand_term = add_brand_on_site($brand);
    $product->field_product_brand['und'][0]['tid'] = $new_brand_term->tid;
  }

  // -- Подраздел
  $is_subcategory_on_site = is_paint_subcategory_on_site($subcategory);

  if($is_subcategory_on_site){
    $subcategory_term = current(taxonomy_get_term_by_name($subcategory));
    $product->field_product_subcategory['und'][0]['tid'] = $subcategory_term->tid;
  } 
  
  if(!$is_subcategory_on_site && !is_null($is_subcategory_on_site)){
    $new_subcategory_term = add_paint_subcategory_on_site($subcategory);
    $product->field_product_subcategory['und'][0]['tid'] = $new_subcategory_term->tid;
  }

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

// Назначение краски в интерьере
function get_appoint_interrior_field_values_from_string($str){
  // $str = str_replace(' ', '', $str);
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
  $finded_appoints = taxonomy_get_term_by_name($appoint, 'appointments_of_paints_interior');

  if(count($finded_appoints) == 1){
    return true;
  }

  if(count($finded_appoints) == 0){
    return false;
  }
}

function add_appoint_interrior_on_site($appoint){
  $appoints_voc = taxonomy_get_vocabulary_by_name('Назначения красок в интерьере');

  $new_appoint = (object) array(
    'vid' => $appoints_voc->vid, 
    'name' => $appoint,
  );

  taxonomy_term_save($new_appoint);
  return $new_appoint;
}

// Назначение краски
function get_appoint_field_values_from_string($str){
  // $str = str_replace(' ', '', $str);
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
  $finded_appoints = taxonomy_get_term_by_name($appoint, 'appointments_of_paints');

  if(count($finded_appoints) == 1){
    return true;
  }

  if(count($finded_appoints) == 0){
    return false;
  }
}

function add_appoint_on_site($appoint){
  $appoints_voc = taxonomy_get_vocabulary_by_name('Назначения красок');

  $new_appoint = (object) array(
    'vid' => $appoints_voc->vid, 
    'name' => $appoint,
  );

  taxonomy_term_save($new_appoint);
  return $new_appoint;
}

// Подразделы
function is_paint_subcategory_on_site($subcategory_name){
  $finded_subcategories = taxonomy_get_term_by_name($subcategory_name, 'paints_subcategories');

  if(count($finded_subcategories) == 1){
    return true;
  }

  if(count($finded_subcategories) == 0){
    return false;
  }
}

function add_paint_subcategory_on_site($subcategory_name){
  $paint_subcategories_vocabulary = taxonomy_get_vocabulary_by_name('Подразделы красок');

  $new_subcategory = (object) array(
    'vid' => $paint_subcategories_vocabulary->vid, 
    'name' => $subcategory_name,
  );

  taxonomy_term_save($new_subcategory);
  return $new_subcategory;
}