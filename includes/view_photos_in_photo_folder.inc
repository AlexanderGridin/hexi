<?php 
function view_photos_in_photo_folder(){
  $nid = variable_get('hexi_photo_folder_nid');
  
  if(!isset($nid)){
    $nid = $_GET['nid'];
  }

  $folder_node = NULL;
  $folder_photos = NULL;

  if(isset($nid)){
    $folder_node = node_load($nid);
    $folder_photos = get_photos_by_folder_nid($nid);
    variable_set('hexi_photo_folder_nid', $nid);
  }

  

  return theme('view_photos_in_photo_folder', array(
    'folder_node' => $folder_node,
    'folder_photos' => $folder_photos
  ));
}

function get_photos_by_folder_nid($folder_nid){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'file')
    ->fieldCondition('field_photo_folder_id', 'value', $folder_nid, '=')
    ->pager(50)
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } else {
    return $entities['file'];
  }
}