// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/Torque.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__TORQUE__STRUCT_H_
#define INTERFACE__MSG__DETAIL__TORQUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Torque in the package interface.
typedef struct interface__msg__Torque
{
  double tau_x_w;
  double tau_y_w;
  double tau_z_w;
} interface__msg__Torque;

// Struct for a sequence of interface__msg__Torque.
typedef struct interface__msg__Torque__Sequence
{
  interface__msg__Torque * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__Torque__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__TORQUE__STRUCT_H_
