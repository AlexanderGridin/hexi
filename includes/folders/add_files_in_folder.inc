<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/folders_functions');

function add_files_in_folder(){
  function add_files_in_folder_form($form, &$form_state){
    $form['file'] = array(
      '#title'         => "Фотографии для загрузки",
      '#description'   => "Максимальный размер загрузки <strong>" . get_upload_max_size() . "</strong>. <br>Максимальное число одновременно загружаемых файлов <strong>" . ini_get("max_file_uploads") . "</strong>.",
      '#type'          => 'file',
      '#attributes' => array('multiple' => 'multiple'),
      '#name' => 'files[]'
    );

    $form['file_type'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите тип файлов',
      '#options'       => array(
        'images' => 'Фотографии',
        'documents' => 'Документы'
      ),
      '#required'      => true,
    );

    $form['target_images_folder'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите папку в которую хотите загрузить фотогарфии',
      '#options'       => generate_photo_folders_form_options_array(),
      '#states' => array(
        'visible' => array(
          ':input[name="file_type"]' => array(
            'value' => 'images',
          ),
        ),
      ),
    );

    $form['target_documents_folder'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите папку в которую хотите загрузить документы',
      '#options'       => generate_documents_folders_form_options_array(),
      '#states' => array(
        'visible' => array(
          ':input[name="file_type"]' => array(
            'value' => 'documents',
          ),
        ),
      ),
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Загрузить файлы в папку",
    );
    
    return $form;
  }

  function add_files_in_folder_form_validate($form, &$form_state){
    $files_type = $form_state['values']['file_type'];
    $target_images_folder_nid = $form_state['values']['target_images_folder'];
    $target_documents_folder_nid = $form_state['values']['target_documents_folder'];
    $folder_nid = NULL;
    $validators = NULL;

    // Валидируем выбор папки для загрузки файлов
    if($files_type == 'images' && !isset($target_images_folder_nid)){
      form_set_error('target_image_folder', 'Выберите папку в которую необходимо загрузить фотогарфии');
    }

    if($files_type == 'documents' && !isset($target_documents_folder_nid)){
      form_set_error('target_document_folder', 'Выберите папку в которую необходимо загрузить документы');
    }

    // 
    if($files_type == 'images'){
      $folder_nid = $form_state['values']['target_images_folder'];
      $validators = array(
        'file_validate_extensions' => array('png gif jpg jpeg'), 
        'file_validate_size' => array($upload_max_size),
      );
    }

    if($files_type == 'documents'){
      $folder_nid = $form_state['values']['target_documents_folder'];
      $validators = array(
        'file_validate_extensions' => array('pdf'), 
        'file_validate_size' => array($upload_max_size),
      );
    }

    //Save multiple files
    $folder_node = node_load($folder_nid);
    $folder_title = $folder_node->title;
    $num_files = count($_FILES['files']['name']);
    $upload_max_size = parse_size(ini_get("upload_max_filesize"));
    $folder_path = "public://hexi_data/$files_type/$folder_title";

    for($i = 0; $i < $num_files; $i++){
      $file = file_save_upload($i, $validators, $folder_path, FILE_EXISTS_REPLACE);

      if($file){
        $file->status = FILE_STATUS_PERMANENT;
        $file->field_photo_folder_id['und'][0]['value'] = $folder_nid;
        $file->field_hexi_folder['und'][0]['value'] = $folder_title;
        $file->field_img_source_name['und'][0]['value'] = $_FILES['files']['orig_name'][$i];
        file_save($file);
        $form_state['values']['files'][$i] = $file;
      }
      else {
        form_set_error('file', 'Файл не был загружен');
      }   
    }
  }

  function add_files_in_folder_form_submit($form, &$form_state){
    $max_uploads_files = intval(ini_get("max_file_uploads"));
    $total_uploaded_files = is_array($form_state['values']['files']) ? count($form_state['values']['files']) : NULL;

    if(isset($total_uploaded_files) && $total_uploaded_files <= $max_uploads_files){
      drupal_set_message('Все файлы были загружены');
    } else {
      drupal_set_message('Что-то пошло не так при загрузке фотографий', 'error');
    }
  }
  
  $add_files_in_folder_form = drupal_get_form('add_files_in_folder_form');
  return theme('add_files_in_folder', array(
    'add_files_in_folder_form' => $add_files_in_folder_form
  ));
}