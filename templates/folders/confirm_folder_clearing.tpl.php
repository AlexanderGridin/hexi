<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

if(isset($node_for_clearing)){
  hexi_print_page_title("Вы уверены что хотите очистить папку с файлами <strong>$node_for_clearing->title</strong>?");
  echo "
    <p>Данное действие удалит все файлы, которые находятся в данной папке.</p>
    <p><strong>Данное действие необратимо!</strong></p>
  ";

  echo drupal_render($confirm_folder_clearing_form);
} else {
  hexi_print_page_title('Страница подтверждения очистки папки с файлами');
}