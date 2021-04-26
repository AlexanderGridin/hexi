<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Удалить товары по идентификатору импорта');

echo drupal_render($remove_products_by_import_id_form);