<?php 
/**
 * VARIABLES:
 * - active_config
 * - config_html
 * - config_confirmation_form
 */

module_load_include('inc', 'hexi', '/lib/hexi_tools');

// dpm($active_config);

echo $config_html;
echo drupal_render($config_confirmation_form);
?>