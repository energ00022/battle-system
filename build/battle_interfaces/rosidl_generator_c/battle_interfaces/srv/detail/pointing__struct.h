// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from battle_interfaces:srv/Pointing.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__SRV__DETAIL__POINTING__STRUCT_H_
#define BATTLE_INTERFACES__SRV__DETAIL__POINTING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target'
#include "battle_interfaces/msg/detail/target__struct.h"

/// Struct defined in srv/Pointing in the package battle_interfaces.
typedef struct battle_interfaces__srv__Pointing_Request
{
  battle_interfaces__msg__Target target;
} battle_interfaces__srv__Pointing_Request;

// Struct for a sequence of battle_interfaces__srv__Pointing_Request.
typedef struct battle_interfaces__srv__Pointing_Request__Sequence
{
  battle_interfaces__srv__Pointing_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} battle_interfaces__srv__Pointing_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'remark'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Pointing in the package battle_interfaces.
typedef struct battle_interfaces__srv__Pointing_Response
{
  bool accepted;
  rosidl_runtime_c__String remark;
} battle_interfaces__srv__Pointing_Response;

// Struct for a sequence of battle_interfaces__srv__Pointing_Response.
typedef struct battle_interfaces__srv__Pointing_Response__Sequence
{
  battle_interfaces__srv__Pointing_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} battle_interfaces__srv__Pointing_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BATTLE_INTERFACES__SRV__DETAIL__POINTING__STRUCT_H_
