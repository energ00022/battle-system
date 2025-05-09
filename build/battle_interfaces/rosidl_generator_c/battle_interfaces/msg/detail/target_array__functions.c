// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from battle_interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice
#include "battle_interfaces/msg/detail/target_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `targets`
#include "battle_interfaces/msg/detail/target__functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"

bool
battle_interfaces__msg__TargetArray__init(battle_interfaces__msg__TargetArray * msg)
{
  if (!msg) {
    return false;
  }
  // targets
  if (!battle_interfaces__msg__Target__Sequence__init(&msg->targets, 0)) {
    battle_interfaces__msg__TargetArray__fini(msg);
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    battle_interfaces__msg__TargetArray__fini(msg);
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    battle_interfaces__msg__TargetArray__fini(msg);
    return false;
  }
  return true;
}

void
battle_interfaces__msg__TargetArray__fini(battle_interfaces__msg__TargetArray * msg)
{
  if (!msg) {
    return;
  }
  // targets
  battle_interfaces__msg__Target__Sequence__fini(&msg->targets);
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
}

bool
battle_interfaces__msg__TargetArray__are_equal(const battle_interfaces__msg__TargetArray * lhs, const battle_interfaces__msg__TargetArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // targets
  if (!battle_interfaces__msg__Target__Sequence__are_equal(
      &(lhs->targets), &(rhs->targets)))
  {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_id), &(rhs->frame_id)))
  {
    return false;
  }
  return true;
}

bool
battle_interfaces__msg__TargetArray__copy(
  const battle_interfaces__msg__TargetArray * input,
  battle_interfaces__msg__TargetArray * output)
{
  if (!input || !output) {
    return false;
  }
  // targets
  if (!battle_interfaces__msg__Target__Sequence__copy(
      &(input->targets), &(output->targets)))
  {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_id), &(output->frame_id)))
  {
    return false;
  }
  return true;
}

battle_interfaces__msg__TargetArray *
battle_interfaces__msg__TargetArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__msg__TargetArray * msg = (battle_interfaces__msg__TargetArray *)allocator.allocate(sizeof(battle_interfaces__msg__TargetArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(battle_interfaces__msg__TargetArray));
  bool success = battle_interfaces__msg__TargetArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
battle_interfaces__msg__TargetArray__destroy(battle_interfaces__msg__TargetArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    battle_interfaces__msg__TargetArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
battle_interfaces__msg__TargetArray__Sequence__init(battle_interfaces__msg__TargetArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__msg__TargetArray * data = NULL;

  if (size) {
    data = (battle_interfaces__msg__TargetArray *)allocator.zero_allocate(size, sizeof(battle_interfaces__msg__TargetArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = battle_interfaces__msg__TargetArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        battle_interfaces__msg__TargetArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
battle_interfaces__msg__TargetArray__Sequence__fini(battle_interfaces__msg__TargetArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      battle_interfaces__msg__TargetArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

battle_interfaces__msg__TargetArray__Sequence *
battle_interfaces__msg__TargetArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__msg__TargetArray__Sequence * array = (battle_interfaces__msg__TargetArray__Sequence *)allocator.allocate(sizeof(battle_interfaces__msg__TargetArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = battle_interfaces__msg__TargetArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
battle_interfaces__msg__TargetArray__Sequence__destroy(battle_interfaces__msg__TargetArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    battle_interfaces__msg__TargetArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
battle_interfaces__msg__TargetArray__Sequence__are_equal(const battle_interfaces__msg__TargetArray__Sequence * lhs, const battle_interfaces__msg__TargetArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!battle_interfaces__msg__TargetArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
battle_interfaces__msg__TargetArray__Sequence__copy(
  const battle_interfaces__msg__TargetArray__Sequence * input,
  battle_interfaces__msg__TargetArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(battle_interfaces__msg__TargetArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    battle_interfaces__msg__TargetArray * data =
      (battle_interfaces__msg__TargetArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!battle_interfaces__msg__TargetArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          battle_interfaces__msg__TargetArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!battle_interfaces__msg__TargetArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
