<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/photo_folders_functions');

hexi_print_page_title('Добавить папку с фотографиями');

echo drupal_render($add_photo_folder_form);

if(isset($available_photo_folders)){
  dpm($available_photo_folders);
}

print_photo_folders_table($available_photo_folders);
print theme('pager');