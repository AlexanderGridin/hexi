<?php 
function confirm_photo_folder_clearing(){
  $nid = $_GET['nid'];
  $node_for_clearing = NULL;

  if(isset($nid)){
    $node_for_clearing = node_load($nid);
  }

  function confirm_photo_folder_clearing_form($form, &$form_state){
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Очистить папку",
    );
    
    return $form;
  }

  function confirm_photo_folder_clearing_form_submit($form, &$form_state){
    $nid = $_GET['nid'];
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
      $photos = $entities['file'];
      
      foreach($photos as $photo){
        $operations[] = array('remove_photo', array($photo->fid));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'photo_folder_clearing_finished',
        'title' => 'Обработка данных',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/confirm_photo_folder_clearing.inc',
      );

      variable_set('folder_for_clearing_name', $node_for_clearing->title);

      batch_set($batch);
      batch_process('/admin/hexi-config/photo-folders');
    }
  }


  $confirm_photo_folder_clearing_form = drupal_get_form('confirm_photo_folder_clearing_form');
  return theme('confirm_photo_folder_clearing', array(
    'node_for_clearing' => $node_for_clearing,
    'confirm_photo_folder_clearing_form' => $confirm_photo_folder_clearing_form
  ));
}

function remove_photo($fid, &$context){
  $file = file_load($fid);
  $file_name = $file->filename;
  file_delete($file);
  $context['results']['deleted_photos']++;
  $context['message'] = 'Удалена фотография <em><strong>' . $file_name . '</strong></em>';
}

function photo_folder_clearing_finished($success, $results, $operations){
  if ($success) {
    $folder_for_clearing_name = variable_get('folder_for_clearing_name');
    drupal_set_message("Очищена папка <strong>$folder_for_clearing_name</strong>");
    drupal_set_message('Удалено ' . $results['deleted_photos'] . ' фотографий.');
    variable_del('folder_for_remove_name');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}