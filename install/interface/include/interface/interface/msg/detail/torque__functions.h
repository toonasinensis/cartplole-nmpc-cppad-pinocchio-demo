// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interface:msg/Torque.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__TORQUE__FUNCTIONS_H_
#define INTERFACE__MSG__DETAIL__TORQUE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interface/msg/rosidl_generator_c__visibility_control.h"

#include "interface/msg/detail/torque__struct.h"

/// Initialize msg/Torque message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interface__msg__Torque
 * )) before or use
 * interface__msg__Torque__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__Torque__init(interface__msg__Torque * msg);

/// Finalize msg/Torque message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__Torque__fini(interface__msg__Torque * msg);

/// Create msg/Torque message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interface__msg__Torque__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
interface__msg__Torque *
interface__msg__Torque__create();

/// Destroy msg/Torque message.
/**
 * It calls
 * interface__msg__Torque__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__Torque__destroy(interface__msg__Torque * msg);

/// Check for msg/Torque message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__Torque__are_equal(const interface__msg__Torque * lhs, const interface__msg__Torque * rhs);

/// Copy a msg/Torque message.
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
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__Torque__copy(
  const interface__msg__Torque * input,
  interface__msg__Torque * output);

/// Initialize array of msg/Torque messages.
/**
 * It allocates the memory for the number of elements and calls
 * interface__msg__Torque__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__Torque__Sequence__init(interface__msg__Torque__Sequence * array, size_t size);

/// Finalize array of msg/Torque messages.
/**
 * It calls
 * interface__msg__Torque__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__Torque__Sequence__fini(interface__msg__Torque__Sequence * array);

/// Create array of msg/Torque messages.
/**
 * It allocates the memory for the array and calls
 * interface__msg__Torque__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
interface__msg__Torque__Sequence *
interface__msg__Torque__Sequence__create(size_t size);

/// Destroy array of msg/Torque messages.
/**
 * It calls
 * interface__msg__Torque__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__Torque__Sequence__destroy(interface__msg__Torque__Sequence * array);

/// Check for msg/Torque message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__Torque__Sequence__are_equal(const interface__msg__Torque__Sequence * lhs, const interface__msg__Torque__Sequence * rhs);

/// Copy an array of msg/Torque messages.
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
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__Torque__Sequence__copy(
  const interface__msg__Torque__Sequence * input,
  interface__msg__Torque__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__TORQUE__FUNCTIONS_H_
