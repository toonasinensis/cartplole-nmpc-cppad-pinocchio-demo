# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interface:msg/Quat.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Quat(type):
    """Metaclass of message 'Quat'."""

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
                'interface.msg.Quat')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__quat
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__quat
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__quat
            cls._TYPE_SUPPORT = module.type_support_msg__msg__quat
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__quat

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Quat(metaclass=Metaclass_Quat):
    """Message class 'Quat'."""

    __slots__ = [
        '_x_w',
        '_y_w',
        '_z_w',
        '_w_w',
    ]

    _fields_and_field_types = {
        'x_w': 'double',
        'y_w': 'double',
        'z_w': 'double',
        'w_w': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x_w = kwargs.get('x_w', float())
        self.y_w = kwargs.get('y_w', float())
        self.z_w = kwargs.get('z_w', float())
        self.w_w = kwargs.get('w_w', float())

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
        if self.x_w != other.x_w:
            return False
        if self.y_w != other.y_w:
            return False
        if self.z_w != other.z_w:
            return False
        if self.w_w != other.w_w:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x_w(self):
        """Message field 'x_w'."""
        return self._x_w

    @x_w.setter
    def x_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_w = value

    @builtins.property
    def y_w(self):
        """Message field 'y_w'."""
        return self._y_w

    @y_w.setter
    def y_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y_w = value

    @builtins.property
    def z_w(self):
        """Message field 'z_w'."""
        return self._z_w

    @z_w.setter
    def z_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'z_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._z_w = value

    @builtins.property
    def w_w(self):
        """Message field 'w_w'."""
        return self._w_w

    @w_w.setter
    def w_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'w_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'w_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._w_w = value
