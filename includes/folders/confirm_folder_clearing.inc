<?php 
function confirm_folder_clearing(){
  $nid = $_GET['nid'];
  $node_for_clearing = NULL;

  if(isset($nid)){
    $node_for_clearing = node_load($nid);
  }

  function confirm_folder_clearing_form($form, &$form_state){
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Очистить папку",
    );
    
    return $form;
  }

  function confirm_folder_clearing_form_submit($form, &$form_state){
    $nid = $_GET['nid'];
    $files_type = $_GET['type'];
    $node_for_clearing = NULL;

    if(isset($nid)){
      $node_for_clearing = node_load($nid);
    }

    // Формируем запрос
    $query = new EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'file')
      ->fieldCondition('field_photo_folder_id', 'value', $node_for_clearing->nid, '=')
      ->execute();

    if(count($entities) > 0){
      $files = $entities['file'];
      
      foreach($files as $file){
        $operations[] = array('remove_file', array($file->fid));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'folder_clearing_finished',
        'title' => 'Обработка данных',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/folders/confirm_folder_clearing.inc',
      );

      variable_set('folder_for_clearing_name', $node_for_clearing->title);
      variable_set('folder_for_clearing_files_type', $files_type);

      batch_set($batch);

      if($files_type == 'images'){
        batch_process('/admin/hexi-config/folders/photo-folders');
      }

      if($files_type == 'documents'){
        batch_process('/admin/hexi-config/folders/documents-folders');
      }
    }
  }

  $confirm_folder_clearing_form = drupal_get_form('confirm_folder_clearing_form');
  return theme('confirm_folder_clearing', array(
    'node_for_clearing' => $node_for_clearing,
    'confirm_folder_clearing_form' => $confirm_folder_clearing_form
  ));
}

function remove_file($fid, &$context){
  $file = file_load($fid);
  $file_name = $file->filename;
  file_delete($file, TRUE);
  $context['results']['deleted_files']++;
  $context['message'] = 'Удален файл <em><strong>' . $file_name . '</strong></em>';
}

function folder_clearing_finished($success, $results, $operations){
  if ($success) {
    $folder_for_clearing_name = variable_get('folder_for_clearing_name');
    $type = variable_get('folder_for_clearing_files_type');

    drupal_set_message("Очищена папка <strong>$folder_for_clearing_name</strong>");
    drupal_set_message('Удалено ' . $results['deleted_files'] . ' файлов.');

    variable_del('folder_for_remove_name');
    variable_del('folder_for_clearing_files_type');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}