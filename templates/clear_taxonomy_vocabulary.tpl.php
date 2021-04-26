<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

if(count($vocabularies_for_clearing_form_options) > 0){
  hexi_print_page_title('Очистить словарь таксономии');
  echo drupal_render($clear_taxonomy_vocabulary_form);
} else {
  hexi_print_page_title('Отсутствуют словари для очистки');
}
