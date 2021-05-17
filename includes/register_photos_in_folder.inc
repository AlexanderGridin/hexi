<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/photo_folders_functions');

function register_photos_in_folder(){
  function register_photos_in_folder_form($form, &$form_state){
    $form['folder'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите папку',
      '#options'       => generate_photo_folders_form_options_array(),
      '#required'      => true,
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Зарегистрировать фотогарфии из папки",
    );

    return $form;
  }

  function register_photos_in_folder_form_submit($form, &$form_state){
    $folder = node_load($form_state['values']['folder']);
    $folder_path = "public://hexi_data/images/$folder->title";

    $files = file_scan_directory($folder_path, '/(.png|.jpg|.jpeg)/');

    if(count($files) > 0){
      // Формируем массив операций
      foreach($files as $file){
        $operations[] = array('register_file', array($file, $folder));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'register_photos_in_folder_finished',
        'title' => 'Регистрация изображений из папки',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/register_photos_in_folder.inc',
      );

      batch_set($batch);
    } else {
      drupal_set_message('Папка <strong>"' . $folder->title . '"</strong> пуста', 'warning');
    }
    
  }

  $register_photos_in_folder_form = drupal_get_form('register_photos_in_folder_form');
  return theme('register_photos_in_folder', array(
    'register_photos_in_folder_form' => $register_photos_in_folder_form
  ));
}

function register_photos_in_folder_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Зарегистрировано ' . $results['registered_photos'] . ' файлов');
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

  $context['results']['registered_photos']++;
  $context['message'] = 'Зарегистрирован файл <em>' . $file->filename . '</em>';
}