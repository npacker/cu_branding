<?php

/**
 * Implements hook_form().
 */
function cubranding_form() {
  $form = array();

  $form['cuheader_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'CU Header',
    '#collapsible' => FALSE,
  );

  $form['cuheader_fieldset']['cuheader_color_scheme'] = array(
    '#type' => 'select',
    '#title' => 'Color Scheme',
    '#description' => 'The selected color scheme should be reflected in the header image.',
    '#options' => array(
      0 => 'White',
      1 => 'Light Gray',
      2 => 'Dark Gray',
      3 => 'Black',
    ),
    '#default_value' => variable_get('cuheader_color_scheme', 1),
  );

  $form['cuheader_fieldset']['cuheader_image'] = array(
    '#type' => 'managed_file',
    '#title' => 'Header Image',
    '#description' => 'Click "Browse..." to upload an image.',
    '#default_value' => variable_get('cuheader_image_fid', ''),
    '#upload_location' => 'public://',
    '#upload_validators' => array(
      'file_validate_is_image' => array(),
      'file_validate_extensions' => array('png'),
      'file_validate_image_resolution' => array('1000x120', 0),
    ),
  );

  $form['cufooter_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'CU Footer',
    '#collapsible' => FALSE,
  );

  $form['cufooter_fieldset']['cufooter_address'] = array(
    '#type' => 'textfield',
    '#title' => 'Address',
    '#default_value' => html_entity_decode(variable_get('cufooter_address'), ENT_QUOTES, 'UTF-8'),
    '#size' => 30,
    '#maxlength' => 255,
  );

  $form['cufooter_fieldset']['cufooter_zip'] = array(
    '#type' => 'textfield',
    '#title' => 'Zip',
    '#default_value' => html_entity_decode(variable_get('cufooter_zip'), ENT_QUOTES, 'UTF-8'),
    '#size' => 8,
    '#maxlength' => 255 ,
  );

  $form['cufooter_fieldset']['cufooter_phone'] = array(
    '#type' => 'textfield',
    '#title' => 'Phone',
    '#default_value' => html_entity_decode(variable_get('cufooter_phone'), ENT_QUOTES, 'UTF-8'),
    '#size' => 14,
    '#maxlength' => 255,
  );

  $form['cufooter_fieldset']['cufooter_email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',
    '#default_value' => html_entity_decode(variable_get('cufooter_email'), ENT_QUOTES, 'UTF-8'),
    '#size' => 30,
    '#maxlength' => 255,
  );
	
	$form['cufooter_fieldset']['cufooter_login_link'] = array(
		'#type' => 'checkbox',
		'#title' => 'Enable login link',
		'#default_value' => variable_get('cufooter_login_link', 0),
		'#return_value' => 1,
	);

  $form['#validate'][] = 'cubranding_form_validate';
  $form['#submit'][] = 'cubranding_form_submit';

  return system_settings_form($form);
}

/**
 * Form validate handler.
 */
function cubranding_form_validate($form, &$form_state) {
  $form_state['values']['cufooter_address'] = check_plain($form_state['values']['cufooter_address']);
  $form_state['values']['cufooter_zip'] = check_plain($form_state['values']['cufooter_zip']);
  $form_state['values']['cufooter_phone'] = check_plain($form_state['values']['cufooter_phone']);
  $form_state['values']['cufooter_email'] = check_plain($form_state['values']['cufooter_email']);
}

/**
 * Form submit handler.
 */
function cubranding_form_submit($form, &$form_state) {
  $new_image = $form_state['values']['cuheader_image'];
  $old_image = variable_get('cuheader_image_fid');

  if (cuheader_new_image_set($new_image)) {
    if (isset($old_image)) {
      if ($old_image != $new_image) {
        cuheader_image_delete($old_image);
        cuheader_image_save($new_image);
      }
    } else {
      cuheader_image_save($new_image);
    }
  } else {
    if (isset($old_image)) {
      cuheader_image_delete($old_image);
    }
  }

  unset($form_state['values']['cuheader_image']);
}

function cuheader_new_image_set($fid) {
  return is_numeric($fid) && !empty($fid);
}

function cuheader_image_save($fid) {
  $image = file_load($fid);

  if ($image) {
    $image->status = FILE_STATUS_PERMANENT;

    file_save($image);

    variable_set('cuheader_image_fid', $image->fid);

    $block = block_load('cubranding', 'cuheader_block');

    file_usage_add($image, 'cubranding', 'block', $block->bid);

    drupal_set_message('The uploaded image was saved successfully.');
  } else {
    drupal_set_message('There was an error while saving the image. The image was not saved.', 'error');
  }
}

function cuheader_image_delete($fid) {
  $image = file_load($fid);

  if ($image) {
    file_usage_delete($image, 'cubranding');

    variable_del('cuheader_image_fid');

    if (file_delete($image, TRUE)) {
      drupal_set_message('The previous image was deleted successfully.');
    } else {
      drupal_set_message('There was an error while delting the image. The image was not deleted.', 'error');
    }
  } else {
    drupal_set_message('There was an error while delting the image. The image was not deleted.', 'error');
  }
}
