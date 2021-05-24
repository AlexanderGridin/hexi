<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

// 
module_load_include('inc', 'hexi', '/lib/import_data_from_file');
module_load_include('inc', 'hexi', '/lib/product/product_functions');

// 
hexi_print_page_title('Test page');

dpm(get_img_by_orig_name('5006801_1', '11097'));