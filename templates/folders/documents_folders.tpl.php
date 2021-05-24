<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/folders_functions');

hexi_print_page_title('Добавить папку с документами');

echo drupal_render($add_documents_folder_form);
echo "<hr>";
echo "<h2 style=\"margin-top: 15px;\">Список доступных папок</h2>";
print_documents_folders_table($available_documents_folders);
print theme('pager');