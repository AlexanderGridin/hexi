<?php 
$data = array(
  'bundles' => array(
    'photo_folder' => (object) array(
      'type' => 'photo_folder',
      'name' => 'Папка с фотографиями',
      'base' => 'node_content',
      'module' => 'node',
      'description' => '',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Название',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'disabled' => '0',
      'orig_type' => 'photo_folder',
      'disabled_changed' => FALSE,
      'bc_entity_type' => 'node',
    ),
  ),
  'fields' => array(
    'field_photo_folder_content' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_photo_folder_content' => array(
                'value' => 'field_photo_folder_content_value',
                'format' => 'field_photo_folder_content_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_photo_folder_content' => array(
                'value' => 'field_photo_folder_content_value',
                'format' => 'field_photo_folder_content_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_photo_folder_content',
      'type' => 'text_long',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'photo_folder',
        ),
      ),
    ),
  ),
  'instances' => array(
    'field_photo_folder_content' => array(
      0 => array(
        'label' => 'Содержимое',
        'widget' => array(
          'weight' => '1',
          'type' => 'text_textarea',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'rows' => '15',
          ),
        ),
        'settings' => array(
          'text_processing' => '1',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
            'weight' => 0,
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_photo_folder_content',
        'entity_type' => 'node',
        'bundle' => 'photo_folder',
        'deleted' => '0',
      ),
    ),
  ),
);