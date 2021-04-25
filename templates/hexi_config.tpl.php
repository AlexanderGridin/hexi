<?php 
/**
 * VARIABLES:
 * - hexi_config_form
 */

module_load_include('inc', 'hexi', '/lib/hexi_tools');

hexi_print_page_title('Импорт данных из Excel');
echo drupal_render($hexi_config_form);