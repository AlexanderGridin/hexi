<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');

function clear_taxonomy_vocabulary(){
  function clear_taxonomy_vocabulary_form($form, &$form_state){
    $form['vid'] = array(
      '#type'          => 'radios',
      '#title'         => 'Выберите  словарь таксономии для очистки',
      '#description' => 'Все термины данного словаря таксономии будут удалены',
      '#options'       => generate_taxonomy_vocabularies_form_options(),
      '#required'      => true,
    );

    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => "Очистить словарь таксономии",
    );
    
    return $form;
  }

  function clear_taxonomy_vocabulary_form_submit($form, &$form_state){
    $vocabulary_terms = taxonomy_get_tree(intval($form_state['values']['vid']));
    
    foreach($vocabulary_terms as $term){
      $operations[] = array('remove_term_from_vocabulary', array($term));
    }

    $batch = array(
      'operations' => $operations,
      'finished' => 'remove_term_from_vocabulary_finished',
      'title' => 'Удаление терминов словаря',
      'init_message' => 'Подготовка данных',
      'progress_message' => 'Выполнено @current из @total.',
      'error_message' => 'Произошла ошибка.',
      'file' => drupal_get_path('module', 'hexi') . '/includes/clear_taxonomy_vocabulary.inc',
    );

    batch_set($batch);
  }
  
  $clear_taxonomy_vocabulary_form = drupal_get_form('clear_taxonomy_vocabulary_form');
  $vocabularies_for_clearing_form_options = generate_taxonomy_vocabularies_form_options();
  return theme('clear_taxonomy_vocabulary', array(
    'clear_taxonomy_vocabulary_form' => $clear_taxonomy_vocabulary_form,
    'vocabularies_for_clearing_form_options' => $vocabularies_for_clearing_form_options
  ));
}

function remove_term_from_vocabulary_finished($success, $results, $operations){
  if ($success) {
    drupal_set_message('Удалено ' . $results['deleted_terms'] . ' терминов таксономии');
  }
  else {
    drupal_set_message('Завершено с ошибками.', 'error');
  }
}

// 
function remove_term_from_vocabulary($term, &$context){
  taxonomy_term_delete($term->tid);

  $context['results']['deleted_terms']++;
  $context['message'] = 'Удален термин таксономии <em>' . $term->name . '</em>';
}