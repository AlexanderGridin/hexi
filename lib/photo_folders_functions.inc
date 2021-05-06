<?php 
function print_photo_folders_table($photo_folders){
  $table_rows = '';
  $counter = 1;

  foreach($photo_folders as $folder){
    $folder_node = node_load($folder->nid);
    $total_photos_in_folder = get_total_photos_in_folder($folder_node->nid);
    $row_class = '';

    if($counter % 2 == 0){
      $row_class = 'even';
    } else {
      $row_class = 'odd';
    }

    $counter++;

    $table_rows .= "
      <tr class=\"$row_class\">
        <td>$folder_node->title</td>
        <td>$folder_node->nid</td>
        <td>$total_photos_in_folder</td>
        <td>Действия</td>
      </tr>
    ";
  }

  $table = "
    <table>
      <thead>
        <tr>
          <th>Название папки</th>
          <th>NID папки</th>
          <th>Количество фотографий в папке</th>
          <th>Действия</th>
        </tr>
      </thead>
      <tbody>
        $table_rows
      </tbody>
    </table>
  ";

  echo $table;
}

function get_total_photos_in_folder($folder_nid){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'file')
    ->fieldCondition('field_photo_folder_id', 'value', $folder_nid, '=')
    ->execute();

  if(count($entities) == 0){
    return 0;
  } else {
    return count($entities['file']);
  }
}

function get_all_photo_folders(){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'photo_folder')
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } else {
    return $entities['node'];
  }
}

function get_photo_folders_per_page($items_per_page){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'photo_folder')
    ->pager($items_per_page)
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } else {
    return $entities['node'];
  }
}

function get_photo_folder_by_name($folder_name){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'photo_folder')
    ->propertyCondition('title', $folder_name)
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } else {
    return $entities['node'];
  }
}

function generate_photo_folders_form_options_array(){
  $options = array();
  $photo_folders = get_all_photo_folders();
  
  foreach($photo_folders as $folder){
    $folder = node_load($folder->nid);
    $options[$folder->nid] =  $folder->title;
  }

  return $options;
}