<?php
function remove_products_by_import_id(){
  function remove_products_by_import_id_form($form, &$form_state){
    $form['import_id'] = array(
      '#type' => 'textfield', 
      '#title' => 'Введите идентификатор импорта', 
      '#default_value' => '', 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Удалить товары",
    );

    return $form;
  }

  function remove_products_by_import_id_form_submit($form, &$form_state){
    $import_id = $form_state['values']['import_id'];

    // Формируем запрос
    $query = new EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'product_view')
      ->fieldCondition('field_product_import_id', 'value', $import_id, '=')
      ->execute();
    
    // Нужно ли удалять товары?
    if(count($entities) > 0){
      // Формируем массив операций
      foreach($entities['node'] as $node){
        $operations[] = array('remove_product_by_node', array($node->nid));
      }

      $batch = array(
        'operations' => $operations,
        'finished' => 'remove_products_by_import_id_finished',
        'title' => 'Удаление товаров и их отражений',
        'init_message' => 'Подготовка данных',
        'progress_message' => 'Выполнено @current из @total.',
        'error_message' => 'Произошла ошибка.',
        'file' => drupal_get_path('module', 'hexi') . '/includes/remove_products_by_import_id.inc',
      );

      batch_set($batch);
    } else {
      drupal_set_message('Товары с индентификатором импорта <strong>"' . $import_id . '"</strong> отсутствуют', 'warning');
    }
  }

  $remove_products_by_import_id_form = drupal_get_form('remove_products_by_import_id_form');
  return theme('remove_products_by_import_id', array(
    'remove_products_by_import_id_form' => $remove_products_by_import_id_form
  ));
}

function remove_products_by_import_id_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Удалено ' . $results['deleted_products_and_displays'] . ' товаров и их отражений');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}

function remove_product_by_node($node_nid, &$context){
  $node = node_load($node_nid);
  $node_title = $node->title;

  node_delete($node_nid);

  $context['results']['deleted_products_and_displays']++;
  $context['message'] = 'Удален товар <em>' . $node_title . '</em>';
}

