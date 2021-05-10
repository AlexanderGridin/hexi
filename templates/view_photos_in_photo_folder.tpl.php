<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Фотографии в папке ' . $folder_node->title);
// dpm($folder_photos);
print_folder_photos($folder_photos);

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
          <a href=\"/file/$photo->fid/delete?destination=view-photos-in-photo-folder\">Удалить файл</a>
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
      <a href=\"admin/hexi-config/photo-folders\" class=\"bd-button\">Вернуться к списку папок</a>
    </div>
  ";
}