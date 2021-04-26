<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

// 
module_load_include('inc', 'hexi', '/lib/import_data_from_file');
module_load_include('inc', 'hexi', '/lib/product/product_functions');

// 
hexi_print_page_title('Test page');

// log_var(taxonomy_get_vocabulary_by_name('Бренды'));
log_var(generate_taxonomy_vocabularies_form_options());