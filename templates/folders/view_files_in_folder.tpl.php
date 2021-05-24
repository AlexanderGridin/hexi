<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/folders_functions');

hexi_print_page_title('Файлы в папке ' . $folder_node->title);

if($files_type == 'images'){
  print_folder_photos($folder_files);
}

if($files_type == 'documents'){
  print_folder_documents($folder_files);
}