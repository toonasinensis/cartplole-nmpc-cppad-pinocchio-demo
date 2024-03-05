// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/Quat.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__QUAT__STRUCT_H_
#define INTERFACE__MSG__DETAIL__QUAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Quat in the package interface.
typedef struct interface__msg__Quat
{
  double x_w;
  double y_w;
  double z_w;
  double w_w;
} interface__msg__Quat;

// Struct for a sequence of interface__msg__Quat.
typedef struct interface__msg__Quat__Sequence
{
  interface__msg__Quat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__Quat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__QUAT__STRUCT_H_
