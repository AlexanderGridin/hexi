<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/folders_functions');

function register_files_in_folder(){
  function register_files_in_folder_form($form, &$form_state){
    $form['files_type'] = array(
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
      '#title'         => 'Выберите папку',
      '#options'       => generate_photo_folders_form_options_array(),
      '#states' => array(
        'visible' => array(
          ':input[name="files_type"]' => array(
            'value' => 'images',
          ),
        ),
      ),
    );

    $form['target_documents_folder'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите папку',
      '#options'       => generate_documents_folders_form_options_array(),
      '#states' => array(
        'visible' => array(
          ':input[name="files_type"]' => array(
            'value' => 'documents',
          ),
        ),
      ),
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Зарегистрировать файлы в папке",
    );

    return $form;
  }

  function register_files_in_folder_form_submit($form, &$form_state){
    // dpm($form_state['values']);
    $folder = NULL;
    $files = NULL;
    $folder_path = "";
    $files_type = $form_state['values']['files_type'];
    $target_documents_folder = $form_state['values']['target_documents_folder'];
    $target_images_folder = $form_state['values']['target_images_folder'];

    if(isset($target_images_folder)){
      $folder = node_load($form_state['values']['target_images_folder']);
      $folder_path = "public://hexi_data/$files_type/$folder->title";
      $files = file_scan_directory($folder_path, '/(.png|.jpg|.jpeg)/');
    }

    if(isset($target_documents_folder)){
      $folder = node_load($form_state['values']['target_documents_folder']);
      $folder_path = "public://hexi_data/$files_type/$folder->title";
      $files = file_scan_directory($folder_path, '/(.pdf)/');
    }

    if(count($files) > 0){
      // Формируем массив операций
      foreach($files as $file){
        $operations[] = array('register_file', array($file, $folder));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'register_files_in_folder_finished',
        'title' => 'Регистрация изображений из папки',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/folders/register_files_in_folder.inc',
      );

      batch_set($batch);
    } else {
      drupal_set_message('Папка <strong>"' . $folder->title . '"</strong> пуста', 'warning');
    }
    
  }

  $register_files_in_folder_form = drupal_get_form('register_files_in_folder_form');
  return theme('register_files_in_folder', array(
    'register_files_in_folder_form' => $register_files_in_folder_form
  ));
}

function register_files_in_folder_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Зарегистрировано ' . $results['registered_files'] . ' файлов');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}

function register_file($file, $folder, &$context){
  $file->field_img_source_name['und'][0]['value'] = trim($file->name);
  $file->field_hexi_folder['und'][0]['value'] = $folder->title;
  $file->field_photo_folder_id['und'][0]['value'] = $folder->nid;
  $file->uid = 1;

  file_save($file);

  $context['results']['registered_files']++;
  $context['message'] = 'Зарегистрирован файл <em>' . $file->filename . '</em>';
}