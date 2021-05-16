<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

// 
module_load_include('inc', 'hexi', '/lib/import_data_from_file');
module_load_include('inc', 'hexi', '/lib/product/product_functions');

// 
hexi_print_page_title('Test page');

// log_var(taxonomy_get_vocabulary_by_name('Бренды'));
// log_var(generate_taxonomy_vocabularies_form_options());

// $query = new EntityFieldQuery();
// $product_display = $query->entityCondition('entity_type', 'node')
//   ->entityCondition('bundle', 'product_view')
//   ->fieldCondition('field_artikul', 'product_id', '2829_1', 'CONTAINS')
//   ->execute();

// dpm($product_display);

/*
$node = node_load('3115');
dpm($node);

if(count($node->field_artikul) == 0){
  $ref = array(
    'product_id' => 3184
  );

  $node->field_artikul['und'][0] = $ref;
  node_save($node);
}

if(count($node->field_artikul) == 1){
  $ref = array(
    'product_id' => 3185
  );

  array_push($node->field_artikul['und'], $ref);
  node_save($node);
}

dpm($node);
*/

// $str = 'DB06DS04_1 DB06DS04_2 DB06DS04_3 DB06DS04_4 DB06DS04_5';
// dpm(get_imgs_from_string_of_names($str));

// $str = 'https://www.youtube.com/watch?v=teRQbQS3uaM&feature=youtu.be https://www.youtube.com/watch?v=0PbWHpu76GU&feature=youtu.be';
// $str = 'https://www.youtube.com/watch?v=OPy4jIVmmcI https://www.youtube.com/watch?v=wkglhaL5jp8';
// get_videos_array_from_string_of_url($str);
// get_img_by_orig_name('215_1', '7597');