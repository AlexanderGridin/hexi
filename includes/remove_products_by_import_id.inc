<?php
function remove_products_by_import_id(){
  function rm_products_by_import_id_form($form, &$form_state){
    $form['import_id'] = array(
      '#type' => 'textfield', 
      '#title' => 'Введите идентификатор импорта', 
      '#default_value' => '', 
      '#size' => 60, 
      '#maxlength' => 128, 
      '#required' => TRUE,
    );

    $form['is_saving_images'] = array(
      '#type'          => 'radios',
      '#title'         => 'Оставить все файлы, связанные с товарами, на сервере?',
      '#options'       => array(
        '0' => 'Нет',
        '1' => 'Да'
      ),
      '#default_value' => '1',
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Удалить товары",
    );

    return $form;
  }

  function rm_products_by_import_id_form_submit($form, &$form_state){
    $import_id = $form_state['values']['import_id'];
    $is_saving_images = boolval($form_state['values']['is_saving_images']);

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
        $operations[] = array('remove_product_by_node', array($node->nid, $is_saving_images));
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

  $remove_products_by_import_id_form = drupal_get_form('rm_products_by_import_id_form');
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

function remove_product_by_node($node_nid, $is_saving_images, &$context){
  $node = node_load($node_nid);
  $node_title = $node->title;

  if($is_saving_images){
    foreach($node->field_artikul['und'] as $linked_product){
      $product = commerce_product_load($linked_product['product_id']);

      foreach($product->field_product_photo['und'] as $photo){
        file_usage_delete((object)$photo, 'file');
      }

      switch($product->type){
        case "product_tools":
          break;

        case "product_paints":
          break;

        case "stucco":
          foreach($product->field_interriors_examples['und'] as $example){
            file_usage_delete((object)$example, 'file');
          }
          break;

        case "product_carpet":
          break;

        case "product_wallpapers":
          break;
      }

      commerce_product_save($product);
    }
  }

  node_delete($node_nid);

  $context['results']['deleted_products_and_displays']++;
  $context['message'] = 'Удален товар <em>' . $node_title . '</em>';
}

