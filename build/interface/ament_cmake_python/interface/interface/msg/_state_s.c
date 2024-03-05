// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "interface/msg/detail/state__struct.h"
#include "interface/msg/detail/state__functions.h"

bool interface__msg__quat__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * interface__msg__quat__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool interface__msg__state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[27];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("interface.msg._state.State", full_classname_dest, 26) == 0);
  }
  interface__msg__State * ros_message = _ros_message;
  {  // quat
    PyObject * field = PyObject_GetAttrString(_pymsg, "quat");
    if (!field) {
      return false;
    }
    if (!interface__msg__quat__convert_from_py(field, &ros_message->quat)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // ang_x_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "ang_x_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ang_x_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ang_y_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "ang_y_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ang_y_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ang_z_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "ang_z_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ang_z_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interface__msg__state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of State */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interface.msg._state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "State");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interface__msg__State * ros_message = (interface__msg__State *)raw_ros_message;
  {  // quat
    PyObject * field = NULL;
    field = interface__msg__quat__convert_to_py(&ros_message->quat);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "quat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ang_x_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ang_x_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ang_x_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ang_y_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ang_y_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ang_y_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ang_z_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ang_z_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ang_z_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
