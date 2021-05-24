<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Зарегистрировать файлы в папке');

echo drupal_render($register_files_in_folder_form);