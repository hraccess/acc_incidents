<?php
/**
 * @file
 * acc_incidents.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function acc_incidents_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create acc_incident content'.
  $permissions['create acc_incident content'] = array(
    'name' => 'create acc_incident content',
    'roles' => array(
      'access editor' => 'access editor',
      'access manager' => 'access manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any acc_incident content'.
  $permissions['delete any acc_incident content'] = array(
    'name' => 'delete any acc_incident content',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own acc_incident content'.
  $permissions['delete own acc_incident content'] = array(
    'name' => 'delete own acc_incident content',
    'roles' => array(
      'access editor' => 'access editor',
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any acc_incident content'.
  $permissions['edit any acc_incident content'] = array(
    'name' => 'edit any acc_incident content',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own acc_incident content'.
  $permissions['edit own acc_incident content'] = array(
    'name' => 'edit own acc_incident content',
    'roles' => array(
      'access editor' => 'access editor',
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
