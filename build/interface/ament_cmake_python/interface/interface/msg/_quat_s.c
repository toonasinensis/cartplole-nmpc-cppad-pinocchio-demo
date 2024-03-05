// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interface:msg/Quat.idl
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
#include "interface/msg/detail/quat__struct.h"
#include "interface/msg/detail/quat__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool interface__msg__quat__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[25];
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
    assert(strncmp("interface.msg._quat.Quat", full_classname_dest, 24) == 0);
  }
  interface__msg__Quat * ros_message = _ros_message;
  {  // x_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // w_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "w_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->w_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interface__msg__quat__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Quat */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interface.msg._quat");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Quat");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interface__msg__Quat * ros_message = (interface__msg__Quat *)raw_ros_message;
  {  // x_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // w_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->w_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "w_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
