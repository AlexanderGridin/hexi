<?php 
function view_files_in_folder(){
  $nid = variable_get('hexi_files_folder_nid');
  $files_type = variable_get('hexi_files_folder_files_type_to_load');
  
  if(!isset($nid) && isset($_GET)){
    $nid = $_GET['nid'];
    variable_set('hexi_files_folder_nid', $nid);
  }

  if(!isset($files_type) && isset($_GET['type'])){
    $files_type = $_GET['type'];
    variable_set('hexi_files_folder_files_type_to_load', $files_type);
  }

  $folder_node = NULL;
  $folder_files = NULL;

  if(isset($nid)){
    $folder_node = node_load($nid);
    $folder_files = get_files_by_folder_nid($nid);
  }

  return theme('view_files_in_folder', array(
    'folder_node' => $folder_node,
    'folder_files' => $folder_files,
    'files_type' => $files_type
  ));
}

function get_files_by_folder_nid($folder_nid){
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