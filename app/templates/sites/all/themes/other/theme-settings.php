<?php


/**
 * Implements hook_form_system_theme_settings_alter()
 */
function other_form_system_theme_settings_alter(&$form, &$form_state) {

  // Default path for alt logo
  $mobile_logo_path = theme_get_setting('mobile_logo_path');
  if (file_uri_scheme($mobile_logo_path) == 'public') {
    $mobile_logo_path = file_uri_target($mobile_logo_path);
  }
  
  // Main settings wrapper
  $form['options'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'defaults',
    '#weight' => '-10',
  );
  
  // Default Drupal Settings    
  $form['options']['drupal_default_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Drupal Core Settings'),
	);
	
	  // "Toggle Display" 
		$form['options']['drupal_default_settings']['theme_settings'] = $form['theme_settings'];
		
		// "Unset default Toggle Display settings" 
		unset($form['theme_settings']);
		
		// "Logo Image Settings" 
		$form['options']['drupal_default_settings']['logo'] = $form['logo'];
		
		// "Unset default Logo Image Settings" 
		unset($form['logo']);
		
		// "Shortcut Icon Settings" 
		$form['options']['drupal_default_settings']['favicon'] = $form['favicon'];   
		
		// "Unset default Shortcut Icon Settings" 
		unset($form['favicon']);
  
  // General
  $form['options']['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
  );
  
    // Ajax Loader
    $form['options']['general']['ajax_loader'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ajax Content Window'),
      '#default_value' => theme_get_setting('ajax_loader'),
    );
                
	  $form['options']['general']['mobile_logo_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to logo'),
      '#default_value' => $mobile_logo_path,
      '#disabled' => TRUE,
    );

    $form['options']['general']['mobile_logo'] = array(
      '#type' => 'file',
      '#title' => t('Upload alternate logo for mobile devices'),
    );    
          
  // Post Meta
  $form['options']['meta'] = array(
    '#type' => 'fieldset',
    '#title' => t('Post Meta'),
  );
               
    // Meta Date
    $form['options']['meta']['meta_date'] = array(
      '#type' => 'checkbox',
      '#title' => t('Meta Date'),
      '#default_value' => theme_get_setting('meta_date'),
    );
    
    // Meta Title
    $form['options']['meta']['meta_title'] = array(
      '#type' => 'checkbox',
      '#title' => t('Meta Title'),
      '#default_value' => theme_get_setting('meta_title'),
    );
        
    // Meta Date
    $form['options']['meta']['meta_tags'] = array(
      '#type' => 'checkbox',
      '#title' => t('Meta Tags'),
      '#default_value' => theme_get_setting('meta_tags'),
    );
        
  // CSS
  $form['options']['css'] = array(
    '#type' => 'fieldset',
    '#title' => t('CSS'),
  );
  
    // User CSS
      $form['options']['css']['user_css'] = array(
        '#type' => 'textarea',
        '#title' => t('Add your own CSS'),
        '#default_value' => theme_get_setting('user_css'),
      );     
      
  // Submit Button
  $form['#submit'][] = 'other_settings_submit';     
}


function other_settings_submit($form, &$form_state) {
  // Get the previous value
  $previous = 'public://' . $form['options']['general']['mobile_logo_path']['#default_value'] ;
  
  $file = file_save_upload('mobile_logo');
  if ($file) {
    $parts = pathinfo($file->filename);
    $destination = 'public://' . $parts['basename'];
    $file->status = FILE_STATUS_PERMANENT;
    
    if(file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      $_POST['mobile_logo_path'] = $form_state['values']['mobile_logo_path'] = $destination;
      if ($destination != $previous) {
        return;
      }
    }
  } else {
    // Avoid error when the form is submitted without specifying a new image
    $_POST['mobile_logo_path'] = $form_state['values']['mobile_logo_path'] = $previous;
  }
  
}

?>