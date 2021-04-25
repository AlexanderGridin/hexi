<?php 
function data_processing_finished(){
  $hexi_file_data = variable_get('hexi_file_data');

  return theme('data_processing_finished', array(
    'hexi_file_data' => $hexi_file_data
  ));
}