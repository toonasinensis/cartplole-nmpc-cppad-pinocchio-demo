# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interface:msg/Torque.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Torque(type):
    """Metaclass of message 'Torque'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interface.msg.Torque')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__torque
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__torque
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__torque
            cls._TYPE_SUPPORT = module.type_support_msg__msg__torque
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__torque

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Torque(metaclass=Metaclass_Torque):
    """Message class 'Torque'."""

    __slots__ = [
        '_tau_x_w',
        '_tau_y_w',
        '_tau_z_w',
    ]

    _fields_and_field_types = {
        'tau_x_w': 'double',
        'tau_y_w': 'double',
        'tau_z_w': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.tau_x_w = kwargs.get('tau_x_w', float())
        self.tau_y_w = kwargs.get('tau_y_w', float())
        self.tau_z_w = kwargs.get('tau_z_w', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.tau_x_w != other.tau_x_w:
            return False
        if self.tau_y_w != other.tau_y_w:
            return False
        if self.tau_z_w != other.tau_z_w:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def tau_x_w(self):
        """Message field 'tau_x_w'."""
        return self._tau_x_w

    @tau_x_w.setter
    def tau_x_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tau_x_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tau_x_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tau_x_w = value

    @builtins.property
    def tau_y_w(self):
        """Message field 'tau_y_w'."""
        return self._tau_y_w

    @tau_y_w.setter
    def tau_y_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tau_y_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tau_y_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tau_y_w = value

    @builtins.property
    def tau_z_w(self):
        """Message field 'tau_z_w'."""
        return self._tau_z_w

    @tau_z_w.setter
    def tau_z_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tau_z_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tau_z_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tau_z_w = value
