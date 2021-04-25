<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Очистка категории каталога');
echo drupal_render($clear_catalogue_category_form);