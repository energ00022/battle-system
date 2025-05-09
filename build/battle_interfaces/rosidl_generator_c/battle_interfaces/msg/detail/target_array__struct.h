// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from battle_interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_H_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'targets'
#include "battle_interfaces/msg/detail/target__struct.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TargetArray in the package battle_interfaces.
typedef struct battle_interfaces__msg__TargetArray
{
  battle_interfaces__msg__Target__Sequence targets;
  builtin_interfaces__msg__Time stamp;
  rosidl_runtime_c__String frame_id;
} battle_interfaces__msg__TargetArray;

// Struct for a sequence of battle_interfaces__msg__TargetArray.
typedef struct battle_interfaces__msg__TargetArray__Sequence
{
  battle_interfaces__msg__TargetArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} battle_interfaces__msg__TargetArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_H_
