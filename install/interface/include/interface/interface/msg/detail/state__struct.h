// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__STATE__STRUCT_H_
#define INTERFACE__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/State in the package interface.
typedef struct interface__msg__State
{
  double x;
  double q;
  double dx;
  double dq;
} interface__msg__State;

// Struct for a sequence of interface__msg__State.
typedef struct interface__msg__State__Sequence
{
  interface__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__STATE__STRUCT_H_