<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Проверить артикулы товаров на дублирование в БД');

echo drupal_render($check_products_sku_for_duplicates_form);