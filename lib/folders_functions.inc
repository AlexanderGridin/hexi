<?php 
function print_documents_folders_table($folders){
  $table_rows = '';
  $counter = 1;

  foreach($folders as $folder){
    $folder_node = node_load($folder->nid);
    $folder_node_title = "<a href=\"/view-files-in-folder?nid=$folder->nid&type=documents\">$folder_node->title</a>";
    $total_files_in_folder = get_total_files_in_folder($folder_node->nid);
    $row_class = '';

    if($counter % 2 == 0){
      $row_class = 'even';
    } else {
      $row_class = 'odd';
    }

    $counter++;

    $actions_list = "
      <li>
        <a href=\"/confirm-folder-delete?nid=$folder_node->nid&type=documents\">Удалить папку</a>
      </li>
      <li>
        <a href=\"/admin/hexi-config/folders/add-files-in-folder\">Добавить документы в папку</a>
      </li>
    ";

    if($total_files_in_folder > 0){
      $actions_list = "
        <li><a href=\"/view-files-in-folder?nid=$folder->nid&type=documents\">Посмотреть документы</a></li>
        <li><a href=\"/confirm-folder-clearing?nid=$folder->nid&type=documents\">Очистить папку</a></li>
      " . $actions_list;
    }

    $table_rows .= "
      <tr class=\"$row_class\">
        <td>$folder_node_title</td>
        <td>$folder_node->nid</td>
        <td>$total_files_in_folder</td>
        <td>
          <ul>
            $actions_list
          </ul>
        </td>
      </tr>
    ";
  }

  $table = "
    <table>
      <thead>
        <tr>
          <th>Название папки</th>
          <th>NID папки</th>
          <th>Документов в папке</th>
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

function print_photo_folders_table($photo_folders){
  $table_rows = '';
  $counter = 1;

  foreach($photo_folders as $folder){
    $folder_node = node_load($folder->nid);
    $folder_node_title = "<a href=\"/view-files-in-folder?nid=$folder->nid&type=images\">$folder_node->title</a>";
    $total_photos_in_folder = get_total_files_in_folder($folder_node->nid);
    $row_class = '';

    if($counter % 2 == 0){
      $row_class = 'even';
    } else {
      $row_class = 'odd';
    }

    $counter++;

    $actions_list = "
      <li>
        <a href=\"/confirm-folder-delete?nid=$folder_node->nid&type=images\">Удалить папку</a>
      </li>
      <li>
        <a href=\"/admin/hexi-config/folders/add-files-in-folder\">Добавить фотографии в папку</a>
      </li>
    ";

    if($total_photos_in_folder > 0){
      $actions_list = "
        <li><a href=\"/view-files-in-folder?nid=$folder->nid&type=images\">Посмотреть фотографии</a></li>
        <li><a href=\"/confirm-folder-clearing?nid=$folder->nid&type=images\">Очистить папку</a></li>
      " . $actions_list;
    }

    $table_rows .= "
      <tr class=\"$row_class\">
        <td>$folder_node_title</td>
        <td>$folder_node->nid</td>
        <td>$total_photos_in_folder</td>
        <td>
          <ul>
            $actions_list
          </ul>
        </td>
      </tr>
    ";
  }

  $table = "
    <table>
      <thead>
        <tr>
          <th>Название папки</th>
          <th>NID папки</th>
          <th>Фотографий в папке</th>
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

function get_total_files_in_folder($folder_nid){
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

function get_documents_folders_per_page($items_per_page){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'documents_folder')
    ->pager($items_per_page)
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

function get_documents_folder_by_name($folder_name){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'documents_folder')
    ->propertyCondition('title', $folder_name)
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

function generate_documents_folders_form_options_array(){
  $options = array();
  $photo_folders = get_all_documents_folders();
  
  foreach($photo_folders as $folder){
    $folder = node_load($folder->nid);
    $options[$folder->nid] =  $folder->title;
  }

  return $options;
}

function get_all_documents_folders(){
  // Формируем запрос
  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'documents_folder')
    ->execute();

  if(count($entities) == 0){
    return NULL;
  } else {
    return $entities['node'];
  }
}

// 
function print_folder_documents($documents){
  if(!isset($documents)){
    echo 'В папке отсутствуют документы...';
    return;
  }

  $documents_html = '';
  $current_documents_folder_nid = $_GET['nid'];

  foreach($documents as $document){
    $document = file_load($document->fid);
    $document_orig_name = $document->field_img_source_name['und'][0]['value'];
    $download_link = l("Скачать/посмотреть файл", file_create_url($document->uri), array(
      'query' => array('download' => '1'),
      'attributes' => array('target'=>'_blank')
    ));

    $documents_item_html = "
      <div class=\"photos-list__item\">
        <div class=\"photos-list__item-title\">
          <h3>$document_orig_name</h3>
        </div>
        <div class=\"photos-list__item-actions\">
          <p>
            <a href=\"/file/$document->fid/delete?destination=view-files-in-folder\">Удалить файл</a>
          </p>
          <p>
            $download_link
          </p>
        </div>
      </div>
    ";

    $documents_html .= $documents_item_html;
  }

  echo "
    <div class=\"photos-list\">
      $documents_html
    </div>
    <div class=\"page-actions\">
      <a href=\"admin/hexi-config/folders/documents-folders\" class=\"bd-button\">Вернуться к списку папок с документами</a>
    </div>
  ";
}

function print_folder_photos($photos){
  if(!isset($photos)){
    echo 'В папке отсутствуют фотографии...';
    return;
  }

  $photos_html = '';
  $current_photos_folder_nid = $_GET['nid'];

  foreach($photos as $photo){
    $photo = file_load($photo->fid);
    $photo_styled_uri = image_style_url('250_200', $photo->uri);
    $photo_orig_name = $photo->field_img_source_name['und'][0]['value'];

    $photo_item_html = "
      <div class=\"photos-list__item\">
        <div class=\"photos-list__item-img\">
          <img src=\"$photo_styled_uri\" alt=\"$photo_orig_name\">
        </div>
        <div class=\"photos-list__item-title\">
          <h3>$photo_orig_name</h3>
        </div>
        <div class=\"photos-list__item-actions\">
          <a href=\"/file/$photo->fid/delete?destination=view-files-in-folder\">Удалить файл</a>
        </div>
      </div>
    ";

    $photos_html .= $photo_item_html;
  }

  echo "
    <div class=\"photos-list\">
      $photos_html
    </div>
    <div class=\"page-actions\">
      <a href=\"admin/hexi-config/folders/photo-folders\" class=\"bd-button\">Вернуться к списку папок с фотографиями</a>
    </div>
  ";
}