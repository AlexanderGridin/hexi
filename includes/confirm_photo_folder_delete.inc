<?php 
function confirm_photo_folder_delete(){
  $nid = $_GET['nid'];
  $node_for_delete = NULL;

  if(isset($nid)){
    $node_for_delete = node_load($nid);
  }

  function confirm_photo_folder_delete_form($form, &$form_state){
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Удалить папку и все её фотографии",
    );
    
    return $form;
  }

  function confirm_photo_folder_delete_form_submit($form, &$form_state){
    $nid = $_GET['nid'];
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
      $photos = $entities['file'];
      
      foreach($photos as $photo){
        $operations[] = array('remove_photo', array($photo->fid));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'photo_folder_delete_finished',
        'title' => 'Обработка данных',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/confirm_photo_folder_delete.inc',
      );

      node_delete($nid);
      variable_set('folder_for_remove_name', $node_for_delete_title);
      drupal_set_message("Удалена папка с фотографиями <strong>$node_for_delete_title</strong>");

      batch_set($batch);
      batch_process('/admin/hexi-config/photo-folders');
    } else {
      node_delete($nid);
      drupal_rmdir('public://hexi_data/images/' . $node_for_delete_title);
      drupal_set_message("Удалена папка с фотографиями <strong>$node_for_delete_title</strong>");
      drupal_goto('/admin/hexi-config/photo-folders');
    }
  }

  $confirm_photo_folder_delete_form = drupal_get_form('confirm_photo_folder_delete_form');
  return theme('confirm_photo_folder_delete', array(
    'node_for_delete' => $node_for_delete,
    'confirm_photo_folder_delete_form' => $confirm_photo_folder_delete_form
  ));
}

function remove_photo($fid, &$context){
  $file = file_load($fid);
  $file_name = $file->filename;
  file_delete($file);
  $context['results']['deleted_photos']++;
  $context['message'] = 'Удалена фотография <em><strong>' . $file_name . '</strong></em>';
}

function photo_folder_delete_finished($success, $results, $operations){
  if ($success) {
    $folder_for_remove_name = variable_get('folder_for_remove_name');
    drupal_rmdir('public://hexi_data/images/' . $folder_for_remove_name);
    variable_del('folder_for_remove_name');
    drupal_set_message('Удалено ' . $results['deleted_photos'] . ' фотографий из папки.');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}