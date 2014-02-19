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

  // Exported permission: 'clear acc_incident_types feeds'.
  $permissions['clear acc_incident_types feeds'] = array(
    'name' => 'clear acc_incident_types feeds',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear acc_incidents feeds'.
  $permissions['clear acc_incidents feeds'] = array(
    'name' => 'clear acc_incidents feeds',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'feeds',
  );

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

  // Exported permission: 'delete terms in acc_incident_types'.
  $permissions['delete terms in acc_incident_types'] = array(
    'name' => 'delete terms in acc_incident_types',
    'roles' => array(
      'access manager' => 'access manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in acc_type_of_aid_workers'.
  $permissions['delete terms in acc_type_of_aid_workers'] = array(
    'name' => 'delete terms in acc_type_of_aid_workers',
    'roles' => array(
      'access manager' => 'access manager',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'edit terms in acc_incident_types'.
  $permissions['edit terms in acc_incident_types'] = array(
    'name' => 'edit terms in acc_incident_types',
    'roles' => array(
      'access manager' => 'access manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in acc_type_of_aid_workers'.
  $permissions['edit terms in acc_type_of_aid_workers'] = array(
    'name' => 'edit terms in acc_type_of_aid_workers',
    'roles' => array(
      'access manager' => 'access manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'import acc_incident_types feeds'.
  $permissions['import acc_incident_types feeds'] = array(
    'name' => 'import acc_incident_types feeds',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import acc_incidents feeds'.
  $permissions['import acc_incidents feeds'] = array(
    'name' => 'import acc_incidents feeds',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock acc_incident_types feeds'.
  $permissions['unlock acc_incident_types feeds'] = array(
    'name' => 'unlock acc_incident_types feeds',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock acc_incidents feeds'.
  $permissions['unlock acc_incidents feeds'] = array(
    'name' => 'unlock acc_incidents feeds',
    'roles' => array(
      'access manager' => 'access manager',
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'feeds',
  );

  return $permissions;
}
