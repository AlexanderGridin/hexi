<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Загрузить файлы в папку');
echo drupal_render($add_files_in_folder_form);