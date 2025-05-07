// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from battle_interfaces:msg/AimVector.idl
// generated code does not contain a copyright notice
#include "battle_interfaces/msg/detail/aim_vector__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
battle_interfaces__msg__AimVector__init(battle_interfaces__msg__AimVector * msg)
{
  if (!msg) {
    return false;
  }
  // yaw
  // pitch
  // roll
  return true;
}

void
battle_interfaces__msg__AimVector__fini(battle_interfaces__msg__AimVector * msg)
{
  if (!msg) {
    return;
  }
  // yaw
  // pitch
  // roll
}

bool
battle_interfaces__msg__AimVector__are_equal(const battle_interfaces__msg__AimVector * lhs, const battle_interfaces__msg__AimVector * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  return true;
}

bool
battle_interfaces__msg__AimVector__copy(
  const battle_interfaces__msg__AimVector * input,
  battle_interfaces__msg__AimVector * output)
{
  if (!input || !output) {
    return false;
  }
  // yaw
  output->yaw = input->yaw;
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  return true;
}

battle_interfaces__msg__AimVector *
battle_interfaces__msg__AimVector__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__msg__AimVector * msg = (battle_interfaces__msg__AimVector *)allocator.allocate(sizeof(battle_interfaces__msg__AimVector), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(battle_interfaces__msg__AimVector));
  bool success = battle_interfaces__msg__AimVector__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
battle_interfaces__msg__AimVector__destroy(battle_interfaces__msg__AimVector * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    battle_interfaces__msg__AimVector__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
battle_interfaces__msg__AimVector__Sequence__init(battle_interfaces__msg__AimVector__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__msg__AimVector * data = NULL;

  if (size) {
    data = (battle_interfaces__msg__AimVector *)allocator.zero_allocate(size, sizeof(battle_interfaces__msg__AimVector), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = battle_interfaces__msg__AimVector__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        battle_interfaces__msg__AimVector__fini(&data[i - 1]);
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
battle_interfaces__msg__AimVector__Sequence__fini(battle_interfaces__msg__AimVector__Sequence * array)
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
      battle_interfaces__msg__AimVector__fini(&array->data[i]);
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

battle_interfaces__msg__AimVector__Sequence *
battle_interfaces__msg__AimVector__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  battle_interfaces__msg__AimVector__Sequence * array = (battle_interfaces__msg__AimVector__Sequence *)allocator.allocate(sizeof(battle_interfaces__msg__AimVector__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = battle_interfaces__msg__AimVector__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
battle_interfaces__msg__AimVector__Sequence__destroy(battle_interfaces__msg__AimVector__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    battle_interfaces__msg__AimVector__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
battle_interfaces__msg__AimVector__Sequence__are_equal(const battle_interfaces__msg__AimVector__Sequence * lhs, const battle_interfaces__msg__AimVector__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!battle_interfaces__msg__AimVector__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
battle_interfaces__msg__AimVector__Sequence__copy(
  const battle_interfaces__msg__AimVector__Sequence * input,
  battle_interfaces__msg__AimVector__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(battle_interfaces__msg__AimVector);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    battle_interfaces__msg__AimVector * data =
      (battle_interfaces__msg__AimVector *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!battle_interfaces__msg__AimVector__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          battle_interfaces__msg__AimVector__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!battle_interfaces__msg__AimVector__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
