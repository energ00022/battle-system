// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from battle_interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Target in the package battle_interfaces.
typedef struct battle_interfaces__msg__Target
{
  /// унікальний ID цілі (‑1 якщо невідомо)
  int32_t id;
  double x;
  double y;
  double z;
  /// 0.0–1.0  (ймовірність, що це справжня ціль)
  float confidence;
  /// відносно якої системи координат
  rosidl_runtime_c__String frame_id;
} battle_interfaces__msg__Target;

// Struct for a sequence of battle_interfaces__msg__Target.
typedef struct battle_interfaces__msg__Target__Sequence
{
  battle_interfaces__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} battle_interfaces__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
