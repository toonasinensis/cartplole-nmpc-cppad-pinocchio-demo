// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interface:msg/Quat.idl
// generated code does not contain a copyright notice
#include "interface/msg/detail/quat__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interface__msg__Quat__init(interface__msg__Quat * msg)
{
  if (!msg) {
    return false;
  }
  // x_w
  // y_w
  // z_w
  // w_w
  return true;
}

void
interface__msg__Quat__fini(interface__msg__Quat * msg)
{
  if (!msg) {
    return;
  }
  // x_w
  // y_w
  // z_w
  // w_w
}

bool
interface__msg__Quat__are_equal(const interface__msg__Quat * lhs, const interface__msg__Quat * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_w
  if (lhs->x_w != rhs->x_w) {
    return false;
  }
  // y_w
  if (lhs->y_w != rhs->y_w) {
    return false;
  }
  // z_w
  if (lhs->z_w != rhs->z_w) {
    return false;
  }
  // w_w
  if (lhs->w_w != rhs->w_w) {
    return false;
  }
  return true;
}

bool
interface__msg__Quat__copy(
  const interface__msg__Quat * input,
  interface__msg__Quat * output)
{
  if (!input || !output) {
    return false;
  }
  // x_w
  output->x_w = input->x_w;
  // y_w
  output->y_w = input->y_w;
  // z_w
  output->z_w = input->z_w;
  // w_w
  output->w_w = input->w_w;
  return true;
}

interface__msg__Quat *
interface__msg__Quat__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__Quat * msg = (interface__msg__Quat *)allocator.allocate(sizeof(interface__msg__Quat), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__msg__Quat));
  bool success = interface__msg__Quat__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interface__msg__Quat__destroy(interface__msg__Quat * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interface__msg__Quat__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interface__msg__Quat__Sequence__init(interface__msg__Quat__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__Quat * data = NULL;

  if (size) {
    data = (interface__msg__Quat *)allocator.zero_allocate(size, sizeof(interface__msg__Quat), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__msg__Quat__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__msg__Quat__fini(&data[i - 1]);
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
interface__msg__Quat__Sequence__fini(interface__msg__Quat__Sequence * array)
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
      interface__msg__Quat__fini(&array->data[i]);
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

interface__msg__Quat__Sequence *
interface__msg__Quat__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__Quat__Sequence * array = (interface__msg__Quat__Sequence *)allocator.allocate(sizeof(interface__msg__Quat__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interface__msg__Quat__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interface__msg__Quat__Sequence__destroy(interface__msg__Quat__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interface__msg__Quat__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interface__msg__Quat__Sequence__are_equal(const interface__msg__Quat__Sequence * lhs, const interface__msg__Quat__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interface__msg__Quat__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interface__msg__Quat__Sequence__copy(
  const interface__msg__Quat__Sequence * input,
  interface__msg__Quat__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interface__msg__Quat);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interface__msg__Quat * data =
      (interface__msg__Quat *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interface__msg__Quat__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interface__msg__Quat__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interface__msg__Quat__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
