<?php
module_load_include('inc', 'hexi', '/lib/hexi_tools');

function clear_catalogue_category(){
  function clear_catalogue_category_form($form, &$form_state){
    $form['main_catalogue_category'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите  категорию каталога для очистки',
      '#description' => 'Все дочерние категории данного раздела каталога будут удалены',
      '#options'       => generate_catalogue_form_options_array('Каталог'),
      '#required'      => true,
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Очистить категорию",
    );
    
    return $form;
  }

  function clear_catalogue_category_form_submit($form, &$form_state){
    $parent = taxonomy_term_load(intval($form_state['values']['main_catalogue_category']));

    $childrens = taxonomy_get_children($parent->tid);

    foreach($childrens as $term){
      $operations[] = array('remove_term_childs', array($term));
    }

    $batch = array(
      'operations' => $operations,
      'finished' => 'remove_term_childs_finished',
      'title' => 'Удаление каталога товаров',
      'init_message' => 'Подготовка данных',
      'progress_message' => 'Выполнено @current из @total.',
      'error_message' => 'Произошла ошибка.',
      'file' => drupal_get_path('module', 'hexi') . '/includes/clear_catalogue_category.inc',
    );

    batch_set($batch);
  }

  $clear_catalogue_category_form = drupal_get_form('clear_catalogue_category_form');
  return theme('clear_catalogue_category', array(
    'clear_catalogue_category_form' => $clear_catalogue_category_form
  ));
}

// 
function remove_term_childs($term, &$context){
  taxonomy_term_delete($term->tid);

  $context['results']['deleted_terms']++;
  $context['message'] = 'Удалена категория каталога <em>' . $term->name . '</em>';
}

function remove_term_childs_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Удалено ' . $results['deleted_terms'] . ' категорий каталога');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}