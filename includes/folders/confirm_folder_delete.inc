<?php 
function confirm_folder_delete(){
  $nid = $_GET['nid'];
  $node_for_delete = NULL;

  if(isset($nid)){
    $node_for_delete = node_load($nid);
  }

  function confirm_folder_delete_form($form, &$form_state){
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Удалить папку и все её файлы",
    );
    
    return $form;
  }

  function confirm_folder_delete_form_submit($form, &$form_state){
    $nid = $_GET['nid'];
    $files_type = $_GET['type'];
    $node_for_delete = NULL;

    if(isset($nid)){
      $node_for_delete = node_load($nid);
    }

    $node_for_delete_title = $node_for_delete->title;
    // dpm($node_for_delete);

    // Формируем запрос
    $query = new EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'file')
      ->fieldCondition('field_photo_folder_id', 'value', $node_for_delete->nid, '=')
      ->execute();

    if(count($entities) > 0){
      $files = $entities['file'];
      
      foreach($files as $file){
        $operations[] = array('delete_file', array($file->fid));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'folder_delete_finished',
        'title' => 'Обработка данных',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/folders/confirm_folder_delete.inc',
      );

      node_delete($nid);
      variable_set('folder_for_remove_name', $node_for_delete_title);
      variable_set('folder_for_remove_files_type', $files_type);
      drupal_set_message("Удалена папка с файлами <strong>$node_for_delete_title</strong>");

      batch_set($batch);

      if($files_type == 'images'){
        batch_process('/admin/hexi-config/folders/photo-folders');
      }

      if($files_type == 'documents'){
        batch_process('/admin/hexi-config/folders/documents-folders');
      }
    } else {
      node_delete($nid);
      drupal_rmdir("public://hexi_data/$files_type/$node_for_delete_title");
      drupal_set_message("Удалена папка с файлами <strong>$node_for_delete_title</strong>");

      if($files_type == 'images'){
        drupal_goto('/admin/hexi-config/folders/photo-folders');
      }

      if($files_type == 'documents'){
        drupal_goto('/admin/hexi-config/folders/documents-folders');
      }
    }
  }

  $confirm_folder_delete_form = drupal_get_form('confirm_folder_delete_form');
  return theme('confirm_folder_delete', array(
    'node_for_delete' => $node_for_delete,
    'confirm_folder_delete_form' => $confirm_folder_delete_form
  ));
}

function delete_file($fid, &$context){
  $file = file_load($fid);
  $file_name = $file->filename;
  file_delete($file);
  $context['results']['deleted_files']++;
  $context['message'] = 'Удалена фотография <em><strong>' . $file_name . '</strong></em>';
}

function folder_delete_finished($success, $results, $operations){
  if ($success) {
    $folder_for_remove_name = variable_get('folder_for_remove_name');
    $files_type = variable_get('folder_for_remove_files_type');

    drupal_rmdir("public://hexi_data/$files_type/$folder_for_remove_name");
    drupal_set_message('Удалено ' . $results['deleted_files'] . ' файлов из папки.');

    variable_del('folder_for_remove_name');
    variable_del('folder_for_remove_files_type');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}