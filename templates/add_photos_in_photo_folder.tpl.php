<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Загрузить фотографии в папку');
echo drupal_render($add_photos_in_photo_folder_form);