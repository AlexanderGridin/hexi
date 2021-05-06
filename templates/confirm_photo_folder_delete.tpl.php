<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

if(isset($node_for_delete)){
  hexi_print_page_title("Вы уверены что хотите удалить папку с фотографиями <strong>$node_for_delete->title</strong>?");
  echo "
    <p>Данное действие удалит папку и все фотографии, которые в ней находятся.</p>
    <p><strong>Данное действие необратимо!</strong></p>
  ";

  echo drupal_render($confirm_photo_folder_delete_form);
} else {
  hexi_print_page_title('Страница подтверждения удаления папки с фотографиями');
}