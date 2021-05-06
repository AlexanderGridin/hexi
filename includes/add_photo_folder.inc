<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/photo_folders_functions');

function add_photo_folder(){
  function add_photo_folder_form($form, &$form_state){
    /*
    $form['file'] = array(
      '#title'         => "Фотографии для загрузки",
      '#description'   => "Максимальный размер загрузки <strong>" . get_upload_max_size() . ".</strong>",
      '#type'          => 'file',
      '#attributes' => array('multiple' => 'multiple'),
      '#name' => 'files[]'
    );
    */

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
      '#value' => "Добавить папку с фотографиями",
    );
    
    return $form;
  }

  function add_photo_folder_form_submit($form, &$form_state){
    $folder_name = $form_state['values']['folder_name'];
    $folder_path = 'public://hexi_data/images/' . $folder_name;

    /**
     * Проверяем папку на предмет наличия на сайте
     * В качестве сущности, отражающей папку для фото, используется нода типа photo_folder (Папка с фотографиями)
     */

    $folder_from_site = get_photo_folder_by_name($folder_name);

    if(!$folder_from_site){
      drupal_mkdir($folder_path);

      // Создаем ноду
      $node = new stdClass();
      $node->type = 'photo_folder';

      node_object_prepare($node);

      $node->title = $folder_name;
      $node->language = LANGUAGE_NONE;
      node_save($node);

      drupal_set_message('Папка с именем <strong>' . $folder_name . '</strong> была создана');
    } else {
      drupal_set_message('Папка с именем <strong>' . $folder_name . '</strong> уже существует! Пожалуйста, выберите другое имя для папки', 'warning');
    }
  }

  $available_photo_folders = get_all_photo_folders();
  $add_photo_folder_form = drupal_get_form('add_photo_folder_form');
  return theme('add_photo_folder', array(
    'add_photo_folder_form' => $add_photo_folder_form,
    'available_photo_folders' => $available_photo_folders
  ));
}