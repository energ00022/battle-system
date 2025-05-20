// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from battle_interfaces:msg/AimVector.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__FUNCTIONS_H_
#define BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "battle_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "battle_interfaces/msg/detail/aim_vector__struct.h"

/// Initialize msg/AimVector message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * battle_interfaces__msg__AimVector
 * )) before or use
 * battle_interfaces__msg__AimVector__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
bool
battle_interfaces__msg__AimVector__init(battle_interfaces__msg__AimVector * msg);

/// Finalize msg/AimVector message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
void
battle_interfaces__msg__AimVector__fini(battle_interfaces__msg__AimVector * msg);

/// Create msg/AimVector message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * battle_interfaces__msg__AimVector__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
battle_interfaces__msg__AimVector *
battle_interfaces__msg__AimVector__create();

/// Destroy msg/AimVector message.
/**
 * It calls
 * battle_interfaces__msg__AimVector__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
void
battle_interfaces__msg__AimVector__destroy(battle_interfaces__msg__AimVector * msg);

/// Check for msg/AimVector message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
bool
battle_interfaces__msg__AimVector__are_equal(const battle_interfaces__msg__AimVector * lhs, const battle_interfaces__msg__AimVector * rhs);

/// Copy a msg/AimVector message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
bool
battle_interfaces__msg__AimVector__copy(
  const battle_interfaces__msg__AimVector * input,
  battle_interfaces__msg__AimVector * output);

/// Initialize array of msg/AimVector messages.
/**
 * It allocates the memory for the number of elements and calls
 * battle_interfaces__msg__AimVector__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
bool
battle_interfaces__msg__AimVector__Sequence__init(battle_interfaces__msg__AimVector__Sequence * array, size_t size);

/// Finalize array of msg/AimVector messages.
/**
 * It calls
 * battle_interfaces__msg__AimVector__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
void
battle_interfaces__msg__AimVector__Sequence__fini(battle_interfaces__msg__AimVector__Sequence * array);

/// Create array of msg/AimVector messages.
/**
 * It allocates the memory for the array and calls
 * battle_interfaces__msg__AimVector__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
battle_interfaces__msg__AimVector__Sequence *
battle_interfaces__msg__AimVector__Sequence__create(size_t size);

/// Destroy array of msg/AimVector messages.
/**
 * It calls
 * battle_interfaces__msg__AimVector__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
void
battle_interfaces__msg__AimVector__Sequence__destroy(battle_interfaces__msg__AimVector__Sequence * array);

/// Check for msg/AimVector message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
bool
battle_interfaces__msg__AimVector__Sequence__are_equal(const battle_interfaces__msg__AimVector__Sequence * lhs, const battle_interfaces__msg__AimVector__Sequence * rhs);

/// Copy an array of msg/AimVector messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_battle_interfaces
bool
battle_interfaces__msg__AimVector__Sequence__copy(
  const battle_interfaces__msg__AimVector__Sequence * input,
  battle_interfaces__msg__AimVector__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__FUNCTIONS_H_
