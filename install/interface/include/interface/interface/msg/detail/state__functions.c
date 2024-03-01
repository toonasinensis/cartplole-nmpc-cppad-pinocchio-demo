// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice
#include "interface/msg/detail/state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interface__msg__State__init(interface__msg__State * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // q
  // dx
  // dq
  return true;
}

void
interface__msg__State__fini(interface__msg__State * msg)
{
  if (!msg) {
    return;
  }
  // x
  // q
  // dx
  // dq
}

bool
interface__msg__State__are_equal(const interface__msg__State * lhs, const interface__msg__State * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // q
  if (lhs->q != rhs->q) {
    return false;
  }
  // dx
  if (lhs->dx != rhs->dx) {
    return false;
  }
  // dq
  if (lhs->dq != rhs->dq) {
    return false;
  }
  return true;
}

bool
interface__msg__State__copy(
  const interface__msg__State * input,
  interface__msg__State * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // q
  output->q = input->q;
  // dx
  output->dx = input->dx;
  // dq
  output->dq = input->dq;
  return true;
}

interface__msg__State *
interface__msg__State__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__State * msg = (interface__msg__State *)allocator.allocate(sizeof(interface__msg__State), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__msg__State));
  bool success = interface__msg__State__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interface__msg__State__destroy(interface__msg__State * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interface__msg__State__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interface__msg__State__Sequence__init(interface__msg__State__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__State * data = NULL;

  if (size) {
    data = (interface__msg__State *)allocator.zero_allocate(size, sizeof(interface__msg__State), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__msg__State__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__msg__State__fini(&data[i - 1]);
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
interface__msg__State__Sequence__fini(interface__msg__State__Sequence * array)
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
      interface__msg__State__fini(&array->data[i]);
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

interface__msg__State__Sequence *
interface__msg__State__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__State__Sequence * array = (interface__msg__State__Sequence *)allocator.allocate(sizeof(interface__msg__State__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interface__msg__State__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interface__msg__State__Sequence__destroy(interface__msg__State__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interface__msg__State__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interface__msg__State__Sequence__are_equal(const interface__msg__State__Sequence * lhs, const interface__msg__State__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interface__msg__State__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interface__msg__State__Sequence__copy(
  const interface__msg__State__Sequence * input,
  interface__msg__State__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interface__msg__State);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interface__msg__State * data =
      (interface__msg__State *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interface__msg__State__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interface__msg__State__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interface__msg__State__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
