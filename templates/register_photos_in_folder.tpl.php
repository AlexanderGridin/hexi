<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Зарегистрировать фотогарфии из папки');

echo drupal_render($register_photos_in_folder_form);