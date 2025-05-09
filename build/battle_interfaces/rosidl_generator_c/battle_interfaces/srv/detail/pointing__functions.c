// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from battle_interfaces:srv/Pointing.idl
// generated code does not contain a copyright notice
#include "battle_interfaces/srv/detail/pointing__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `target`
#include "battle_interfaces/msg/detail/target__functions.h"

bool
battle_interfaces__srv__Pointing_Request__init(battle_interfaces__srv__Pointing_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target
  if (!battle_interfaces__msg__Target__init(&msg->target)) {
    battle_interfaces__srv__Pointing_Request__fini(msg);
    return false;
  }
  return true;
}

void
battle_interfaces__srv__Pointing_Request__fini(battle_interfaces__srv__Pointing_Request * msg)
{
  if (!msg) {
    return;
  }
  // target
  battle_interfaces__msg__Target__fini(&msg->target);
}

bool
battle_interfaces__srv__Pointing_Request__are_equal(const battle_interfaces__srv__Pointing_Request * lhs, const battle_interfaces__srv__Pointing_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target
  if (!battle_interfaces__msg__Target__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  return true;
}

bool
battle_interfaces__srv__Pointing_Request__copy(
  const battle_interfaces__srv__Pointing_Request * input,
  battle_interfaces__srv__Pointing_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // target
  if (!battle_interfaces__msg__Target__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  return true;
}

battle_interfaces__srv__Pointing_Request *
battle_interfaces__srv__Pointing_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__srv__Pointing_Request * msg = (battle_interfaces__srv__Pointing_Request *)allocator.allocate(sizeof(battle_interfaces__srv__Pointing_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(battle_interfaces__srv__Pointing_Request));
  bool success = battle_interfaces__srv__Pointing_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
battle_interfaces__srv__Pointing_Request__destroy(battle_interfaces__srv__Pointing_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    battle_interfaces__srv__Pointing_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
battle_interfaces__srv__Pointing_Request__Sequence__init(battle_interfaces__srv__Pointing_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__srv__Pointing_Request * data = NULL;

  if (size) {
    data = (battle_interfaces__srv__Pointing_Request *)allocator.zero_allocate(size, sizeof(battle_interfaces__srv__Pointing_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = battle_interfaces__srv__Pointing_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        battle_interfaces__srv__Pointing_Request__fini(&data[i - 1]);
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
battle_interfaces__srv__Pointing_Request__Sequence__fini(battle_interfaces__srv__Pointing_Request__Sequence * array)
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
      battle_interfaces__srv__Pointing_Request__fini(&array->data[i]);
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

battle_interfaces__srv__Pointing_Request__Sequence *
battle_interfaces__srv__Pointing_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__srv__Pointing_Request__Sequence * array = (battle_interfaces__srv__Pointing_Request__Sequence *)allocator.allocate(sizeof(battle_interfaces__srv__Pointing_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = battle_interfaces__srv__Pointing_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
battle_interfaces__srv__Pointing_Request__Sequence__destroy(battle_interfaces__srv__Pointing_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    battle_interfaces__srv__Pointing_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
battle_interfaces__srv__Pointing_Request__Sequence__are_equal(const battle_interfaces__srv__Pointing_Request__Sequence * lhs, const battle_interfaces__srv__Pointing_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!battle_interfaces__srv__Pointing_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
battle_interfaces__srv__Pointing_Request__Sequence__copy(
  const battle_interfaces__srv__Pointing_Request__Sequence * input,
  battle_interfaces__srv__Pointing_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(battle_interfaces__srv__Pointing_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    battle_interfaces__srv__Pointing_Request * data =
      (battle_interfaces__srv__Pointing_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!battle_interfaces__srv__Pointing_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          battle_interfaces__srv__Pointing_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!battle_interfaces__srv__Pointing_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `remark`
#include "rosidl_runtime_c/string_functions.h"

bool
battle_interfaces__srv__Pointing_Response__init(battle_interfaces__srv__Pointing_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // remark
  if (!rosidl_runtime_c__String__init(&msg->remark)) {
    battle_interfaces__srv__Pointing_Response__fini(msg);
    return false;
  }
  return true;
}

void
battle_interfaces__srv__Pointing_Response__fini(battle_interfaces__srv__Pointing_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // remark
  rosidl_runtime_c__String__fini(&msg->remark);
}

bool
battle_interfaces__srv__Pointing_Response__are_equal(const battle_interfaces__srv__Pointing_Response * lhs, const battle_interfaces__srv__Pointing_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // remark
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->remark), &(rhs->remark)))
  {
    return false;
  }
  return true;
}

bool
battle_interfaces__srv__Pointing_Response__copy(
  const battle_interfaces__srv__Pointing_Response * input,
  battle_interfaces__srv__Pointing_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // remark
  if (!rosidl_runtime_c__String__copy(
      &(input->remark), &(output->remark)))
  {
    return false;
  }
  return true;
}

battle_interfaces__srv__Pointing_Response *
battle_interfaces__srv__Pointing_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__srv__Pointing_Response * msg = (battle_interfaces__srv__Pointing_Response *)allocator.allocate(sizeof(battle_interfaces__srv__Pointing_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(battle_interfaces__srv__Pointing_Response));
  bool success = battle_interfaces__srv__Pointing_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
battle_interfaces__srv__Pointing_Response__destroy(battle_interfaces__srv__Pointing_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    battle_interfaces__srv__Pointing_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
battle_interfaces__srv__Pointing_Response__Sequence__init(battle_interfaces__srv__Pointing_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__srv__Pointing_Response * data = NULL;

  if (size) {
    data = (battle_interfaces__srv__Pointing_Response *)allocator.zero_allocate(size, sizeof(battle_interfaces__srv__Pointing_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = battle_interfaces__srv__Pointing_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        battle_interfaces__srv__Pointing_Response__fini(&data[i - 1]);
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
battle_interfaces__srv__Pointing_Response__Sequence__fini(battle_interfaces__srv__Pointing_Response__Sequence * array)
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
      battle_interfaces__srv__Pointing_Response__fini(&array->data[i]);
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

battle_interfaces__srv__Pointing_Response__Sequence *
battle_interfaces__srv__Pointing_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__srv__Pointing_Response__Sequence * array = (battle_interfaces__srv__Pointing_Response__Sequence *)allocator.allocate(sizeof(battle_interfaces__srv__Pointing_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = battle_interfaces__srv__Pointing_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
battle_interfaces__srv__Pointing_Response__Sequence__destroy(battle_interfaces__srv__Pointing_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    battle_interfaces__srv__Pointing_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
battle_interfaces__srv__Pointing_Response__Sequence__are_equal(const battle_interfaces__srv__Pointing_Response__Sequence * lhs, const battle_interfaces__srv__Pointing_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!battle_interfaces__srv__Pointing_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
battle_interfaces__srv__Pointing_Response__Sequence__copy(
  const battle_interfaces__srv__Pointing_Response__Sequence * input,
  battle_interfaces__srv__Pointing_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(battle_interfaces__srv__Pointing_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    battle_interfaces__srv__Pointing_Response * data =
      (battle_interfaces__srv__Pointing_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!battle_interfaces__srv__Pointing_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          battle_interfaces__srv__Pointing_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!battle_interfaces__srv__Pointing_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
