<?php 
// Бренды
function is_brand_on_site($brand_name){
  return is_taxonomy_term_in_vocabulary($brand_name, 'product_brands');
}

function add_brand_on_site($brand_name){
  $brands_vocabulary = taxonomy_get_vocabulary_by_name('Бренды');

  return taxonomy_create_term_in_vocabulary($brand_name, $brands_vocabulary->vid);
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