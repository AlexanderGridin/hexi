<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/photo_folders_functions');

function add_photos_in_photo_folder(){
  function add_photos_in_photo_folder_form($form, &$form_state){
    $form['file'] = array(
      '#title'         => "Фотографии для загрузки",
      '#description'   => "Максимальный размер загрузки <strong>" . get_upload_max_size() . "</strong>. <br>Максимальное число одновременно загружаемых файлов <strong>" . ini_get("max_file_uploads") . "</strong>.",
      '#type'          => 'file',
      '#attributes' => array('multiple' => 'multiple'),
      '#name' => 'files[]'
    );

    $form['target_folder'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите папку',
      '#options'       => generate_photo_folders_form_options_array(),
      '#required'      => true,
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Загрузить фотографии в папку",
    );
    
    return $form;
  }

  function add_photos_in_photo_folder_form_validate($form, &$form_state){
    //Save multiple files
    $folder_nid = $form_state['values']['target_folder'];
    $folder_node = node_load($folder_nid);
    $folder_title = $folder_node->title;

    $num_files = count($_FILES['files']['name']);
    $upload_max_size = parse_size(ini_get("upload_max_filesize"));
    $folder_path = 'public://hexi_data/images/' . $folder_title;
    $validators = array(
      'file_validate_extensions' => array('png gif jpg jpeg'), 
      'file_validate_size' => array($upload_max_size),
    );

    for($i = 0; $i < $num_files; $i++){
      $file = file_save_upload($i, $validators, $folder_path, FILE_EXISTS_REPLACE);

      if($file){
        $file->status = FILE_STATUS_PERMANENT;
        $file->field_photo_folder_id['und'][0]['value'] = $folder_nid;
        $file->field_hexi_folder['und'][0]['value'] = $folder_title;
        $file->field_img_source_name['und'][0]['value'] = $_FILES['files']['orig_name'][$i];
        file_save($file);
        $form_state['values']['imgs'][$i] = $file;
      }
      else {
        form_set_error('file', 'Файл не был загружен');
      }   
    }
  }

  function add_photos_in_photo_folder_form_submit($form, &$form_state){
    $max_uploads_files = intval(ini_get("max_file_uploads"));
    $total_uploaded_files = is_array($form_state['values']['imgs']) ? count($form_state['values']['imgs']) : NULL;

    if(isset($total_uploaded_files) && $total_uploaded_files <= $max_uploads_files){
      drupal_set_message('Все фотографии были загружены');
    } else {
      drupal_set_message('Что-то пошло не так при загрузке фотографий', 'error');
    }
  }

  /*
  function add_photos_in_photo_folder_form_submit($form, &$form_state){
    dpm($_FILES);
  }
  */
  
  $add_photos_in_photo_folder_form = drupal_get_form('add_photos_in_photo_folder_form');
  return theme('add_photos_in_photo_folder', array(
    'add_photos_in_photo_folder_form' => $add_photos_in_photo_folder_form
  ));
}