// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from battle_interfaces:msg/AimVector.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__STRUCT_H_
#define BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AimVector in the package battle_interfaces.
typedef struct battle_interfaces__msg__AimVector
{
  double yaw;
  double pitch;
  double roll;
} battle_interfaces__msg__AimVector;

// Struct for a sequence of battle_interfaces__msg__AimVector.
typedef struct battle_interfaces__msg__AimVector__Sequence
{
  battle_interfaces__msg__AimVector * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} battle_interfaces__msg__AimVector__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__STRUCT_H_
