<?php 
// Группы
function is_tools_group_on_site($group_name){
  $group = taxonomy_get_term_by_name($group_name, 'tools_groups');

  if(count($group) == 1){
    return true;
  }

  if(count($group) == 0){
    return false;
  }
}

function add_tools_group_on_site($group_name){
  $tools_groups_vocabulary = taxonomy_get_vocabulary_by_name('Группы инструментов');

  $group = (object) array(
    'vid' => $tools_groups_vocabulary->vid, 
    'name' => $group_name,
  );

  taxonomy_term_save($group);
  return $group;
}