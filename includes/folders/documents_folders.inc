<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/folders_functions');

function documents_folders(){
  variable_del('hexi_files_folder_nid');
  variable_del('hexi_files_folder_files_type_to_load');

  function add_documents_folder_form($form, &$form_state){
    $form['folder_name'] = array(
      '#type' => 'textfield', 
      '#title' => 'Название папки', 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
      '#description'   => "Введите название папки.",
    );
    
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Добавить папку с документами",
    );
    
    return $form;
  }

  function add_documents_folder_form_submit($form, &$form_state){
    $folder_name = $form_state['values']['folder_name'];
    $folder_path = 'public://hexi_data/documents/' . $folder_name;

    /**
     * Проверяем папку на предмет наличия на сайте
     * В качестве сущности, отражающей папку для фото, используется нода типа photo_folder (Папка с фотографиями)
     */

    $folder_from_site = get_documents_folder_by_name($folder_name);

    if(!$folder_from_site){
      drupal_mkdir($folder_path);

      // Создаем ноду
      $node = new stdClass();
      $node->type = 'documents_folder';

      node_object_prepare($node);

      $node->title = $folder_name;
      $node->language = LANGUAGE_NONE;
      node_save($node);

      drupal_set_message('Папка с именем <strong>' . $folder_name . '</strong> была создана');
    } else {
      drupal_set_message('Папка с именем <strong>' . $folder_name . '</strong> уже существует! Пожалуйста, выберите другое имя для папки', 'warning');
    }
  }

  $available_documents_folders = get_documents_folders_per_page(20);
  $add_documents_folder_form = drupal_get_form('add_documents_folder_form');
  return theme('documents_folders', array(
    'add_documents_folder_form' => $add_documents_folder_form,
    'available_documents_folders' => $available_documents_folders
  ));
}