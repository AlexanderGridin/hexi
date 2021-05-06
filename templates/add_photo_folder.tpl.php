<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/photo_folders_functions');

hexi_print_page_title('Добавить папку с фотографиями');

echo drupal_render($add_photo_folder_form);
echo "<hr>";
echo "<h2 style=\"margin-top: 15px;\">Список доступных папок</h2>";
print_photo_folders_table($available_photo_folders);
print theme('pager');