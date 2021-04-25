<?php 
module_load_include('inc', 'hexi', '/lib/hexi_tools');
module_load_include('inc', 'hexi', '/lib/prepare_data_for_processing');

function hexi_check_config(){
  $import_config = variable_get('hexi_import_config');
  $update_config = variable_get('hexi_update_config');
  $active_config = NULL;
  $config_html = '';
  $config_confirmation_form = NULL;

  if(isset($import_config)){
    $active_config = $import_config;
    $config_html = prepare_config_html($import_config);
    $config_confirmation_form = drupal_get_form('import_config_confirmation_form');
  }

  if(isset($update_config)){
    $active_config = $update_config;
    $config_html = prepare_config_html($update_config);
    $config_confirmation_form = drupal_get_form('update_config_confirmation_form');
  }

  return theme('hexi_check_config', array(
    'active_config' => $active_config,
    'config_html' => $config_html,
    'config_confirmation_form' => $config_confirmation_form
  ));
}

//import_config_confirmation_form
function import_config_confirmation_form($form, &$form_state){
  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => "Начать импорт",
  );
  
  return $form;
}

function import_config_confirmation_form_submit($form, &$form_state){
  // drupal_goto('/start-excel-data-proceed');
  prepare_data_for_processing();
}

//update_config_confirmation_form
function update_config_confirmation_form($form, &$form_state){
  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => "Начать обновление товаров",
  );
  
  return $form;
}

function update_config_confirmation_submit($form, &$form_state){
  // drupal_goto('/start-excel-data-proceed');
  prepare_data_for_processing();
}