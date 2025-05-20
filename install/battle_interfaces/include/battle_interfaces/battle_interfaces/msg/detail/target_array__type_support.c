// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from battle_interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "battle_interfaces/msg/detail/target_array__rosidl_typesupport_introspection_c.h"
#include "battle_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "battle_interfaces/msg/detail/target_array__functions.h"
#include "battle_interfaces/msg/detail/target_array__struct.h"


// Include directives for member types
// Member `targets`
#include "battle_interfaces/msg/target.h"
// Member `targets`
#include "battle_interfaces/msg/detail/target__rosidl_typesupport_introspection_c.h"
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  battle_interfaces__msg__TargetArray__init(message_memory);
}

void battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_fini_function(void * message_memory)
{
  battle_interfaces__msg__TargetArray__fini(message_memory);
}

size_t battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__size_function__TargetArray__targets(
  const void * untyped_member)
{
  const battle_interfaces__msg__Target__Sequence * member =
    (const battle_interfaces__msg__Target__Sequence *)(untyped_member);
  return member->size;
}

const void * battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__get_const_function__TargetArray__targets(
  const void * untyped_member, size_t index)
{
  const battle_interfaces__msg__Target__Sequence * member =
    (const battle_interfaces__msg__Target__Sequence *)(untyped_member);
  return &member->data[index];
}

void * battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__get_function__TargetArray__targets(
  void * untyped_member, size_t index)
{
  battle_interfaces__msg__Target__Sequence * member =
    (battle_interfaces__msg__Target__Sequence *)(untyped_member);
  return &member->data[index];
}

void battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__fetch_function__TargetArray__targets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const battle_interfaces__msg__Target * item =
    ((const battle_interfaces__msg__Target *)
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__get_const_function__TargetArray__targets(untyped_member, index));
  battle_interfaces__msg__Target * value =
    (battle_interfaces__msg__Target *)(untyped_value);
  *value = *item;
}

void battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__assign_function__TargetArray__targets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  battle_interfaces__msg__Target * item =
    ((battle_interfaces__msg__Target *)
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__get_function__TargetArray__targets(untyped_member, index));
  const battle_interfaces__msg__Target * value =
    (const battle_interfaces__msg__Target *)(untyped_value);
  *item = *value;
}

bool battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__resize_function__TargetArray__targets(
  void * untyped_member, size_t size)
{
  battle_interfaces__msg__Target__Sequence * member =
    (battle_interfaces__msg__Target__Sequence *)(untyped_member);
  battle_interfaces__msg__Target__Sequence__fini(member);
  return battle_interfaces__msg__Target__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array[3] = {
  {
    "targets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(battle_interfaces__msg__TargetArray, targets),  // bytes offset in struct
    NULL,  // default value
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__size_function__TargetArray__targets,  // size() function pointer
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__get_const_function__TargetArray__targets,  // get_const(index) function pointer
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__get_function__TargetArray__targets,  // get(index) function pointer
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__fetch_function__TargetArray__targets,  // fetch(index, &value) function pointer
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__assign_function__TargetArray__targets,  // assign(index, value) function pointer
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__resize_function__TargetArray__targets  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(battle_interfaces__msg__TargetArray, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(battle_interfaces__msg__TargetArray, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_members = {
  "battle_interfaces__msg",  // message namespace
  "TargetArray",  // message name
  3,  // number of fields
  sizeof(battle_interfaces__msg__TargetArray),
  battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array,  // message members
  battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_init_function,  // function to initialize message memory (memory has to be allocated)
  battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle = {
  0,
  &battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_battle_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, battle_interfaces, msg, TargetArray)() {
  battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, battle_interfaces, msg, Target)();
  battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle.typesupport_identifier) {
    battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &battle_interfaces__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
