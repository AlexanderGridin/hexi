<?php 
$data = array(
  'bundles' => array(
    'product_tools' => array(
      'type' => 'product_tools',
      'name' => 'Инструменты',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
      'bc_entity_type' => 'commerce_product',
    ),
    'product_paints' => array(
      'type' => 'product_paints',
      'name' => 'Краски',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
      'bc_entity_type' => 'commerce_product',
    ),
    'stucco' => array(
      'type' => 'stucco',
      'name' => 'Декоративная штукатурка',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
      'bc_entity_type' => 'commerce_product',
    ),
    'product_carpet' => array(
      'type' => 'product_carpet',
      'name' => 'Ковры',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
      'bc_entity_type' => 'commerce_product',
    ),
    'product_wallpapers' => array(
      'type' => 'product_wallpapers',
      'name' => 'Обои',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
      'bc_entity_type' => 'commerce_product',
    ),
  ),
  'fields' => array(
    'commerce_price' => array(
      'entity_types' => array(
        0 => 'commerce_product',
      ),
      'translatable' => '0',
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_commerce_price' => array(
                'amount' => 'commerce_price_amount',
                'currency_code' => 'commerce_price_currency_code',
                'data' => 'commerce_price_data',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_commerce_price' => array(
                'amount' => 'commerce_price_amount',
                'currency_code' => 'commerce_price_currency_code',
                'data' => 'commerce_price_data',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'currency_price' => array(
          0 => 'amount',
          1 => 'currency_code',
        ),
      ),
      'field_name' => 'commerce_price',
      'type' => 'commerce_price',
      'module' => 'commerce_price',
      'active' => '1',
      'locked' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'amount' => array(
          'description' => 'The price amount.',
          'type' => 'int',
          'not null' => TRUE,
          'default' => 0,
        ),
        'currency_code' => array(
          'description' => 'The currency code for the price.',
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
        ),
        'data' => array(
          'description' => 'A serialized array of additional price data.',
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
          'serialize' => TRUE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product',
          1 => 'product_wallpapers',
          2 => 'product_paints',
          3 => 'product_tools',
          4 => 'stucco',
          5 => 'product_carpet',
        ),
      ),
    ),
    'field_interriors_examples' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_interriors_examples' => array(
                'fid' => 'field_interriors_examples_fid',
                'alt' => 'field_interriors_examples_alt',
                'title' => 'field_interriors_examples_title',
                'width' => 'field_interriors_examples_width',
                'height' => 'field_interriors_examples_height',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_interriors_examples' => array(
                'fid' => 'field_interriors_examples_fid',
                'alt' => 'field_interriors_examples_alt',
                'title' => 'field_interriors_examples_title',
                'width' => 'field_interriors_examples_width',
                'height' => 'field_interriors_examples_height',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'fid' => array(
          'table' => 'file_managed',
          'columns' => array(
            'fid' => 'fid',
          ),
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_interriors_examples',
      'type' => 'image',
      'module' => 'image',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'fid' => array(
          'description' => 'The {file_managed}.fid being referenced in this field.',
          'type' => 'int',
          'not null' => FALSE,
          'unsigned' => TRUE,
        ),
        'alt' => array(
          'description' => 'Alternative image text, for the image\'s \'alt\' attribute.',
          'type' => 'varchar',
          'length' => 512,
          'not null' => FALSE,
        ),
        'title' => array(
          'description' => 'Image title text, for the image\'s \'title\' attribute.',
          'type' => 'varchar',
          'length' => 1024,
          'not null' => FALSE,
        ),
        'width' => array(
          'description' => 'The width of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
        'height' => array(
          'description' => 'The height of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'stucco',
        ),
      ),
    ),
    'field_product_appoint' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_appointments',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_appoint' => array(
                'tid' => 'field_product_appoint_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_appoint' => array(
                'tid' => 'field_product_appoint_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_appoint',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
          1 => 'stucco',
        ),
      ),
    ),
    'field_product_appoint_interrior' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_appointments_interior',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_appoint_interrior' => array(
                'tid' => 'field_product_appoint_interrior_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_appoint_interrior' => array(
                'tid' => 'field_product_appoint_interrior_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_appoint_interrior',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
          1 => 'stucco',
        ),
      ),
    ),
    'field_product_base' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_base' => array(
                'value' => 'field_product_base_value',
                'format' => 'field_product_base_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_base' => array(
                'value' => 'field_product_base_value',
                'format' => 'field_product_base_format',
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
      'field_name' => 'field_product_base',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
        ),
      ),
    ),
    'field_product_brand' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_brands',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_brand' => array(
                'tid' => 'field_product_brand_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_brand' => array(
                'tid' => 'field_product_brand_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_brand',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_tools',
          1 => 'product_paints',
          2 => 'stucco',
          3 => 'product_carpet',
          4 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_carpet_size' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'carpets_sizes',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_carpet_size' => array(
                'tid' => 'field_product_carpet_size_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_carpet_size' => array(
                'tid' => 'field_product_carpet_size_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_carpet_size',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
        ),
      ),
    ),
    'field_product_coating' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_coating' => array(
                'value' => 'field_product_coating_value',
                'format' => 'field_product_coating_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_coating' => array(
                'value' => 'field_product_coating_value',
                'format' => 'field_product_coating_format',
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
      'field_name' => 'field_product_coating',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'stucco',
        ),
      ),
    ),
    'field_product_collection' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'manufacturer_collections',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_collection' => array(
                'tid' => 'field_product_collection_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_collection' => array(
                'tid' => 'field_product_collection_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_collection',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'stucco',
          1 => 'product_carpet',
          2 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_composition' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_composition' => array(
                'value' => 'field_product_composition_value',
                'format' => 'field_product_composition_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_composition' => array(
                'value' => 'field_product_composition_value',
                'format' => 'field_product_composition_format',
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
      'field_name' => 'field_product_composition',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
        ),
      ),
    ),
    'field_product_country' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_country' => array(
                'value' => 'field_product_country_value',
                'format' => 'field_product_country_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_country' => array(
                'value' => 'field_product_country_value',
                'format' => 'field_product_country_format',
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
      'field_name' => 'field_product_country',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_tools',
          1 => 'stucco',
          2 => 'product_carpet',
          3 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_description' => array(
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
              'field_data_field_product_description' => array(
                'value' => 'field_product_description_value',
                'format' => 'field_product_description_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_description' => array(
                'value' => 'field_product_description_value',
                'format' => 'field_product_description_format',
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
      'field_name' => 'field_product_description',
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
        'commerce_product' => array(
          0 => 'product_tools',
          1 => 'product_paints',
          2 => 'stucco',
        ),
      ),
    ),
    'field_product_design' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_design',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_design' => array(
                'tid' => 'field_product_design_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_design' => array(
                'tid' => 'field_product_design_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_design',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_form' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_form' => array(
                'value' => 'field_product_form_value',
                'format' => 'field_product_form_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_form' => array(
                'value' => 'field_product_form_value',
                'format' => 'field_product_form_format',
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
      'field_name' => 'field_product_form',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
        ),
      ),
    ),
    'field_product_gloss_degree' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_gloss_degree' => array(
                'value' => 'field_product_gloss_degree_value',
                'format' => 'field_product_gloss_degree_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_gloss_degree' => array(
                'value' => 'field_product_gloss_degree_value',
                'format' => 'field_product_gloss_degree_format',
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
      'field_name' => 'field_product_gloss_degree',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
        ),
      ),
    ),
    'field_product_group_sku' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_group_sku' => array(
                'value' => 'field_product_group_sku_value',
                'format' => 'field_product_group_sku_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_group_sku' => array(
                'value' => 'field_product_group_sku_value',
                'format' => 'field_product_group_sku_format',
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
      'field_name' => 'field_product_group_sku',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
        ),
      ),
    ),
    'field_product_import_id' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_import_id' => array(
                'value' => 'field_product_import_id_value',
                'format' => 'field_product_import_id_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_import_id' => array(
                'value' => 'field_product_import_id_value',
                'format' => 'field_product_import_id_format',
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
      'field_name' => 'field_product_import_id',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
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
          0 => 'product_view',
        ),
        'commerce_product' => array(
          0 => 'product_tools',
          1 => 'product_paints',
          2 => 'stucco',
          3 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_length' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_length' => array(
                'value' => 'field_product_length_value',
                'format' => 'field_product_length_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_length' => array(
                'value' => 'field_product_length_value',
                'format' => 'field_product_length_format',
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
      'field_name' => 'field_product_length',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
          1 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_material' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_material' => array(
                'value' => 'field_product_material_value',
                'format' => 'field_product_material_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_material' => array(
                'value' => 'field_product_material_value',
                'format' => 'field_product_material_format',
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
      'field_name' => 'field_product_material',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_photo' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_photo' => array(
                'fid' => 'field_product_photo_fid',
                'alt' => 'field_product_photo_alt',
                'title' => 'field_product_photo_title',
                'width' => 'field_product_photo_width',
                'height' => 'field_product_photo_height',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_photo' => array(
                'fid' => 'field_product_photo_fid',
                'alt' => 'field_product_photo_alt',
                'title' => 'field_product_photo_title',
                'width' => 'field_product_photo_width',
                'height' => 'field_product_photo_height',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'fid' => array(
          'table' => 'file_managed',
          'columns' => array(
            'fid' => 'fid',
          ),
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_photo',
      'type' => 'image',
      'module' => 'image',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'fid' => array(
          'description' => 'The {file_managed}.fid being referenced in this field.',
          'type' => 'int',
          'not null' => FALSE,
          'unsigned' => TRUE,
        ),
        'alt' => array(
          'description' => 'Alternative image text, for the image\'s \'alt\' attribute.',
          'type' => 'varchar',
          'length' => 512,
          'not null' => FALSE,
        ),
        'title' => array(
          'description' => 'Image title text, for the image\'s \'title\' attribute.',
          'type' => 'varchar',
          'length' => 1024,
          'not null' => FALSE,
        ),
        'width' => array(
          'description' => 'The width of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
        'height' => array(
          'description' => 'The height of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'stucco',
        ),
      ),
    ),
    'field_product_rapport' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_rapport' => array(
                'value' => 'field_product_rapport_value',
                'format' => 'field_product_rapport_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_rapport' => array(
                'value' => 'field_product_rapport_value',
                'format' => 'field_product_rapport_format',
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
      'field_name' => 'field_product_rapport',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_resistance_to_wash' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_resistance_to_wash' => array(
                'value' => 'field_product_resistance_to_wash_value',
                'format' => 'field_product_resistance_to_wash_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_resistance_to_wash' => array(
                'value' => 'field_product_resistance_to_wash_value',
                'format' => 'field_product_resistance_to_wash_format',
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
      'field_name' => 'field_product_resistance_to_wash',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
        ),
      ),
    ),
    'field_product_safe_for_children' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => 'Нет',
          1 => 'Да',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_safe_for_children' => array(
                'value' => 'field_product_safe_for_children_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_safe_for_children' => array(
                'value' => 'field_product_safe_for_children_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_safe_for_children',
      'type' => 'list_boolean',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
        ),
      ),
    ),
    'field_product_style' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_styles',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_style' => array(
                'tid' => 'field_product_style_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_style' => array(
                'tid' => 'field_product_style_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_style',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
          1 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_subcategory' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'paints_subcategories',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_subcategory' => array(
                'tid' => 'field_product_subcategory_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_subcategory' => array(
                'tid' => 'field_product_subcategory_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_subcategory',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
        ),
      ),
    ),
    'field_product_visible_color' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'product_visible_colors',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_visible_color' => array(
                'tid' => 'field_product_visible_color_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_visible_color' => array(
                'tid' => 'field_product_visible_color_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_visible_color',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
          1 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_volume' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_volume' => array(
                'value' => 'field_product_volume_value',
                'format' => 'field_product_volume_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_volume' => array(
                'value' => 'field_product_volume_value',
                'format' => 'field_product_volume_format',
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
      'field_name' => 'field_product_volume',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_paints',
        ),
      ),
    ),
    'field_product_wallpaper_type' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'wallpapers_types',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_wallpaper_type' => array(
                'tid' => 'field_product_wallpaper_type_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_wallpaper_type' => array(
                'tid' => 'field_product_wallpaper_type_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_product_wallpaper_type',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_wallpapers',
        ),
      ),
    ),
    'field_product_width' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_product_width' => array(
                'value' => 'field_product_width_value',
                'format' => 'field_product_width_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_product_width' => array(
                'value' => 'field_product_width_value',
                'format' => 'field_product_width_format',
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
      'field_name' => 'field_product_width',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_carpet',
          1 => 'product_wallpapers',
        ),
      ),
    ),
    'field_tools_group' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tools_groups',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_tools_group' => array(
                'tid' => 'field_tools_group_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_tools_group' => array(
                'tid' => 'field_tools_group_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_tools_group',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_tools',
        ),
      ),
    ),
    'field_tools_serial' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_tools_serial' => array(
                'value' => 'field_tools_serial_value',
                'format' => 'field_tools_serial_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_tools_serial' => array(
                'value' => 'field_tools_serial_value',
                'format' => 'field_tools_serial_format',
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
      'field_name' => 'field_tools_serial',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_tools',
        ),
      ),
    ),
    'field_tools_size' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_tools_size' => array(
                'value' => 'field_tools_size_value',
                'format' => 'field_tools_size_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_tools_size' => array(
                'value' => 'field_tools_size_value',
                'format' => 'field_tools_size_format',
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
      'field_name' => 'field_tools_size',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'product_tools',
        ),
      ),
    ),
    'field_video_review' => array(
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
              'field_data_field_video_review' => array(
                'input' => 'field_video_review_input',
                'video_id' => 'field_video_review_video_id',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_video_review' => array(
                'input' => 'field_video_review_input',
                'video_id' => 'field_video_review_video_id',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'video_id' => array(
          0 => 'video_id',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_video_review',
      'type' => 'youtube',
      'module' => 'youtube',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'input' => array(
          'type' => 'varchar',
          'length' => 1024,
          'not null' => FALSE,
        ),
        'video_id' => array(
          'type' => 'varchar',
          'length' => 15,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'commerce_product' => array(
          0 => 'stucco',
        ),
      ),
    ),
  ),
  'instances' => array(
    'commerce_price' => array(
      0 => array(
        'label' => 'Цена',
        'required' => TRUE,
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'type' => 'commerce_price_full',
          'weight' => '9',
          'settings' => array(
            'currency_code' => 'default',
          ),
          'module' => 'commerce_price',
        ),
        'display' => array(
          'full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'add_to_cart_confirmation_view' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'line_item' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_display' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_teaser' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'weight' => '2',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'commerce_price',
          ),
          'node_rss' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_colorbox' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_media_gallery_block' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_revision' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'default' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
        ),
        'description' => '',
        'field_name' => 'commerce_price',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
        'default_value' => NULL,
      ),
      1 => array(
        'label' => 'Цена',
        'required' => TRUE,
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'type' => 'commerce_price_full',
          'weight' => '13',
          'settings' => array(
            'currency_code' => 'default',
          ),
          'module' => 'commerce_price',
        ),
        'display' => array(
          'full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'add_to_cart_confirmation_view' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'line_item' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_display' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_teaser' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'weight' => '3',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'commerce_price',
          ),
          'node_rss' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_colorbox' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_media_gallery_block' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_revision' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'default' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
        ),
        'description' => '',
        'field_name' => 'commerce_price',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
        'default_value' => NULL,
      ),
      2 => array(
        'label' => 'Цена',
        'required' => TRUE,
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'type' => 'commerce_price_full',
          'weight' => '5',
          'settings' => array(
            'currency_code' => 'default',
          ),
          'module' => 'commerce_price',
        ),
        'display' => array(
          'full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'add_to_cart_confirmation_view' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'line_item' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_display' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_teaser' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_prefix_suffix',
            'weight' => '2',
            'settings' => array(
              'calculation' => TRUE,
              'prefix' => 'от ',
              'suffix' => '/кв.м',
              'text_format' => 'full_html',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'commerce_extra_price_formatters',
          ),
          'node_rss' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_colorbox' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_media_gallery_block' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_revision' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'default' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'weight' => '0',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'commerce_price',
          ),
        ),
        'description' => '',
        'field_name' => 'commerce_price',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
        'default_value' => NULL,
      ),
      3 => array(
        'label' => 'Цена',
        'required' => TRUE,
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'type' => 'commerce_price_full',
          'weight' => '0',
          'settings' => array(
            'currency_code' => 'default',
          ),
          'module' => 'commerce_price',
        ),
        'display' => array(
          'full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'add_to_cart_confirmation_view' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'line_item' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_display' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_teaser' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'weight' => '2',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'commerce_price',
          ),
          'node_rss' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_colorbox' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_media_gallery_block' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_revision' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'default' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
        ),
        'description' => '',
        'field_name' => 'commerce_price',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
        'default_value' => NULL,
      ),
      4 => array(
        'label' => 'Цена',
        'required' => TRUE,
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'type' => 'commerce_price_full',
          'weight' => '0',
          'settings' => array(
            'currency_code' => 'default',
          ),
          'module' => 'commerce_price',
        ),
        'display' => array(
          'full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'add_to_cart_confirmation_view' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'line_item' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_display' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_commerce_product_in_cart' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'commerce_line_item_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_full' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_teaser' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'weight' => '2',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'commerce_price',
          ),
          'node_rss' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_colorbox' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_media_gallery_block' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_token' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'node_revision' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
          'default' => array(
            'label' => 'hidden',
            'type' => 'commerce_price_formatted_amount',
            'settings' => array(
              'calculation' => 'calculated_sell_price',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'weight' => 0,
            'module' => 'commerce_price',
          ),
        ),
        'description' => '',
        'field_name' => 'commerce_price',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
        'default_value' => NULL,
      ),
    ),
    'field_interriors_examples' => array(
      0 => array(
        'label' => 'Примеры интерьеров',
        'widget' => array(
          'weight' => '3',
          'type' => 'image_miw',
          'module' => 'multiupload_imagefield_widget',
          'active' => 1,
          'settings' => array(
            'progress_indicator' => 'throbber',
            'preview_image_style' => 'thumbnail',
          ),
        ),
        'settings' => array(
          'file_directory' => 'fields/field_interriors_examples',
          'file_extensions' => 'png gif jpg jpeg',
          'max_filesize' => '',
          'max_resolution' => '',
          'min_resolution' => '',
          'alt_field' => 1,
          'title_field' => 1,
          'default_image' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'image',
            'settings' => array(
              'image_style' => '',
              'image_link' => '',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'image',
            'weight' => 10,
          ),
          'node_teaser' => array(
            'label' => 'above',
            'type' => 'image',
            'weight' => '13',
            'settings' => array(
              'image_style' => '250_200',
              'image_link' => '',
              'field_multiple_limit' => '1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'image',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'field_name' => 'field_interriors_examples',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
    'field_product_appoint' => array(
      0 => array(
        'label' => 'Назначение краски',
        'widget' => array(
          'weight' => '10',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 8,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '11',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Назначение краски',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_appoint',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Назначение материала',
        'widget' => array(
          'weight' => '12',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '6',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '9',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Назначение материала',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_appoint',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
    'field_product_appoint_interrior' => array(
      0 => array(
        'label' => 'Назначение краски в интерьере',
        'widget' => array(
          'weight' => '11',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 9,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '12',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Назначение краски в интерьере',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_appoint_interrior',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Назначение в интерьере',
        'widget' => array(
          'weight' => '13',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '7',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '10',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Назначение в интерьере',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_appoint_interrior',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
    'field_product_base' => array(
      0 => array(
        'label' => 'База',
        'widget' => array(
          'weight' => '9',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 7,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '10',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_base',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
    ),
    'field_product_brand' => array(
      0 => array(
        'label' => 'Бренд',
        'widget' => array(
          'weight' => '4',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 10,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '9',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Бренд',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_brand',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Бренд',
        'widget' => array(
          'weight' => '3',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 1,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '4',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Бренд',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_brand',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
      2 => array(
        'label' => 'Бренд',
        'widget' => array(
          'weight' => '8',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '2',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '5',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Бренд',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_brand',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
      3 => array(
        'label' => 'Бренд',
        'widget' => array(
          'weight' => '37',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 1,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '4',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Бренд',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_brand',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      4 => array(
        'label' => 'Бренд',
        'widget' => array(
          'weight' => '37',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 1,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '4',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Бренд',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_brand',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_carpet_size' => array(
      0 => array(
        'label' => 'Размер',
        'widget' => array(
          'weight' => '40',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 3,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '6',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 1,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Размер',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_carpet_size',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
    ),
    'field_product_coating' => array(
      0 => array(
        'label' => 'Покрытие',
        'widget' => array(
          'weight' => '14',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 8,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '11',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_coating',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
    'field_product_collection' => array(
      0 => array(
        'label' => 'Коллекция',
        'widget' => array(
          'weight' => '9',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '3',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '6',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Коллекция',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_collection',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Коллекция',
        'widget' => array(
          'weight' => '39',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 2,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '5',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Коллекция',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_collection',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      2 => array(
        'label' => 'Коллекция',
        'widget' => array(
          'weight' => '39',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 2,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '5',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Коллекция',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_collection',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_composition' => array(
      0 => array(
        'label' => 'Состав',
        'widget' => array(
          'weight' => '46',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 8,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '10',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_composition',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
    ),
    'field_product_country' => array(
      0 => array(
        'label' => 'Страна',
        'widget' => array(
          'weight' => '11',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 11,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '10',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_country',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Страна',
        'widget' => array(
          'weight' => '11',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '5',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '8',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_country',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
      2 => array(
        'label' => 'Страна',
        'widget' => array(
          'weight' => '44',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 6,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '8',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_country',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      3 => array(
        'label' => 'Страна',
        'widget' => array(
          'weight' => '45',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 5,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '8',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_country',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_description' => array(
      0 => array(
        'label' => 'Описание',
        'widget' => array(
          'weight' => '8',
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
            'weight' => 3,
          ),
          'node_teaser' => array(
            'label' => 'above',
            'type' => 'text_default',
            'weight' => '4',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_description',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Описание',
        'widget' => array(
          'weight' => '12',
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
            'weight' => 2,
          ),
          'node_teaser' => array(
            'label' => 'above',
            'type' => 'text_default',
            'weight' => '5',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_description',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
      2 => array(
        'label' => 'Описание',
        'widget' => array(
          'weight' => '10',
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
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '4',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'node_teaser' => array(
            'label' => 'above',
            'type' => 'text_default',
            'weight' => '7',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_description',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
    'field_product_design' => array(
      0 => array(
        'label' => 'Дизайн',
        'widget' => array(
          'weight' => '49',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 8,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '11',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Дизайн',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_design',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_form' => array(
      0 => array(
        'label' => 'Форма',
        'widget' => array(
          'weight' => '49',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 11,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '13',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_form',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
    ),
    'field_product_gloss_degree' => array(
      0 => array(
        'label' => 'Степень блеска',
        'widget' => array(
          'weight' => '6',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 4,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '7',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_gloss_degree',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
    ),
    'field_product_group_sku' => array(
      0 => array(
        'label' => 'Артикул группы товаров',
        'widget' => array(
          'weight' => '45',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 7,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '9',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_group_sku',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
    ),
    'field_product_import_id' => array(
      0 => array(
        'label' => 'Идентификатор импорта',
        'widget' => array(
          'weight' => '0',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 7,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '7',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_import_id',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Идентификатор импорта',
        'widget' => array(
          'weight' => '1',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 11,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '1',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_import_id',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
      2 => array(
        'label' => 'Идентификатор импорта',
        'widget' => array(
          'weight' => '7',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '1',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '4',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_import_id',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
      3 => array(
        'label' => 'Идентификатор импорта',
        'widget' => array(
          'weight' => '55',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 12,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '15',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_import_id',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_length' => array(
      0 => array(
        'label' => 'Длина',
        'widget' => array(
          'weight' => '48',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 10,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '12',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => 'Значение длины в метрах',
        'default_value' => NULL,
        'field_name' => 'field_product_length',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Длина',
        'widget' => array(
          'weight' => '43',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 4,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '7',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_length',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_material' => array(
      0 => array(
        'label' => 'Материал',
        'widget' => array(
          'weight' => '52',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 10,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '13',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_material',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_photo' => array(
      0 => array(
        'label' => 'Фотографии',
        'widget' => array(
          'weight' => '1',
          'type' => 'image_miw',
          'module' => 'multiupload_imagefield_widget',
          'active' => 1,
          'settings' => array(
            'progress_indicator' => 'throbber',
            'preview_image_style' => 'thumbnail',
          ),
        ),
        'settings' => array(
          'file_directory' => 'fields/field_product_photo',
          'file_extensions' => 'png gif jpg jpeg',
          'max_filesize' => '',
          'max_resolution' => '',
          'min_resolution' => '',
          'alt_field' => 1,
          'title_field' => 1,
          'default_image' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'image',
            'settings' => array(
              'image_style' => '',
              'image_link' => '',
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'image',
            'weight' => 9,
          ),
          'node_teaser' => array(
            'label' => 'above',
            'type' => 'image',
            'weight' => '12',
            'settings' => array(
              'image_style' => '250_200',
              'image_link' => '',
              'field_multiple_limit' => '1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'image',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'field_name' => 'field_product_photo',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
    'field_product_rapport' => array(
      0 => array(
        'label' => 'Раппорт, см',
        'widget' => array(
          'weight' => '53',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 11,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '14',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_rapport',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_resistance_to_wash' => array(
      0 => array(
        'label' => 'Стойкость к мытью',
        'widget' => array(
          'weight' => '7',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 5,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '8',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_resistance_to_wash',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
    ),
    'field_product_safe_for_children' => array(
      0 => array(
        'label' => 'Применение в детских и лечебных учреждениях',
        'widget' => array(
          'weight' => '5',
          'type' => 'options_buttons',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'list',
            'weight' => 3,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'list_default',
            'weight' => '6',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'list',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Применение в детских и лечебных учреждениях',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_safe_for_children',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
    ),
    'field_product_style' => array(
      0 => array(
        'label' => 'Стиль',
        'widget' => array(
          'weight' => '41',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 4,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '7',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Стиль',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_style',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Стиль',
        'widget' => array(
          'weight' => '51',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 9,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '12',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Стиль',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_style',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_subcategory' => array(
      0 => array(
        'label' => 'Подраздел',
        'widget' => array(
          'weight' => '4',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 10,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '13',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Подраздел',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_subcategory',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
    ),
    'field_product_visible_color' => array(
      0 => array(
        'label' => 'Видимый цвет',
        'widget' => array(
          'weight' => '50',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 12,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '14',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Видимый цвет',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_visible_color',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Видимый цвет',
        'widget' => array(
          'weight' => '47',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 6,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'ds_taxonomy_separator',
            'weight' => '9',
            'settings' => array(
              'taxonomy_term_link' => 1,
              'taxonomy_term_separator' => ' / ',
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'ds',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Видимый цвет',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_visible_color',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_volume' => array(
      0 => array(
        'label' => 'Объем, л',
        'widget' => array(
          'weight' => '8',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 6,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '9',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_volume',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_paints',
        'deleted' => '0',
      ),
    ),
    'field_product_wallpaper_type' => array(
      0 => array(
        'label' => 'Тип',
        'widget' => array(
          'weight' => '48',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 7,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '10',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Тип',
        ),
        'default_value' => NULL,
        'field_name' => 'field_product_wallpaper_type',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_product_width' => array(
      0 => array(
        'label' => 'Ширина',
        'widget' => array(
          'weight' => '47',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 9,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '11',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => 'Значение ширины в метрах.',
        'default_value' => NULL,
        'field_name' => 'field_product_width',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_carpet',
        'deleted' => '0',
      ),
      1 => array(
        'label' => 'Ширина',
        'widget' => array(
          'weight' => '41',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 3,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '6',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_product_width',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_wallpapers',
        'deleted' => '0',
      ),
    ),
    'field_tools_group' => array(
      0 => array(
        'label' => 'Группа',
        'widget' => array(
          'weight' => '3',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
            'weight' => 9,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'taxonomy_term_reference_link',
            'weight' => '8',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'taxonomy',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'commerce_cart_settings' => array(
          'attribute_field' => 0,
          'attribute_widget' => 'select',
          'attribute_widget_title' => 'Группа',
        ),
        'default_value' => NULL,
        'field_name' => 'field_tools_group',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
    ),
    'field_tools_serial' => array(
      0 => array(
        'label' => 'Серия',
        'widget' => array(
          'weight' => '5',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 4,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '5',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_tools_serial',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
    ),
    'field_tools_size' => array(
      0 => array(
        'label' => 'Размер, мм',
        'widget' => array(
          'weight' => '6',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
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
            'weight' => 5,
          ),
          'node_teaser' => array(
            'label' => 'inline',
            'type' => 'text_default',
            'weight' => '6',
            'settings' => array(
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'text',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_tools_size',
        'entity_type' => 'commerce_product',
        'bundle' => 'product_tools',
        'deleted' => '0',
      ),
    ),
    'field_video_review' => array(
      0 => array(
        'label' => 'Видеообзор',
        'widget' => array(
          'weight' => '2',
          'type' => 'youtube',
          'module' => 'youtube',
          'active' => 0,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'youtube_video',
            'settings' => array(
              'youtube_size' => '420x315',
              'youtube_width' => NULL,
              'youtube_height' => NULL,
              'youtube_autoplay' => FALSE,
              'youtube_mute' => FALSE,
              'youtube_loop' => FALSE,
              'youtube_controls' => FALSE,
              'youtube_autohide' => FALSE,
              'youtube_iv_load_policy' => FALSE,
              'youtube_playsinline' => FALSE,
              'youtube_allow_autoplay' => FALSE,
              'youtube_allow_fullscreen' => FALSE,
              'field_multiple_limit' => -1,
              'field_multiple_limit_offset' => 0,
              'field_multiple_limit_order' => 0,
            ),
            'module' => 'youtube',
            'weight' => 11,
          ),
          'node_teaser' => array(
            'label' => 'above',
            'type' => 'youtube_video',
            'weight' => '14',
            'settings' => array(
              'youtube_size' => 'responsive',
              'youtube_width' => '',
              'youtube_height' => '',
              'youtube_autoplay' => 0,
              'youtube_mute' => 0,
              'youtube_loop' => 0,
              'youtube_controls' => 0,
              'youtube_autohide' => 0,
              'youtube_iv_load_policy' => 0,
              'youtube_playsinline' => 0,
              'youtube_allow_autoplay' => 0,
              'youtube_allow_fullscreen' => 0,
              'field_multiple_limit' => '-1',
              'field_multiple_limit_offset' => '0',
              'field_multiple_limit_order' => '0',
            ),
            'module' => 'youtube',
          ),
          'add_to_cart_confirmation_view' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'commerce_product_in_cart' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
          'line_item' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_video_review',
        'entity_type' => 'commerce_product',
        'bundle' => 'stucco',
        'deleted' => '0',
      ),
    ),
  ),
);