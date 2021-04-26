<?php 
// Бренды
function is_brand_on_site($brand_name){
  $brand = taxonomy_get_term_by_name($brand_name, 'product_brands');

  if(count($brand) == 1){
    return true;
  }

  if(count($brand) == 0){
    return false;
  }
}

function add_brand_on_site($brand_name){
  $brands_vocabulary = taxonomy_get_vocabulary_by_name('Бренды');

  $brand = (object) array(
    'vid' => $brands_vocabulary->vid, 
    'name' => $brand_name,
  );

  taxonomy_term_save($brand);
  return $brand;
}