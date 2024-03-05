# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interface:msg/State.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_State(type):
    """Metaclass of message 'State'."""

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
                'interface.msg.State')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__state

            from interface.msg import Quat
            if Quat.__class__._TYPE_SUPPORT is None:
                Quat.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class State(metaclass=Metaclass_State):
    """Message class 'State'."""

    __slots__ = [
        '_quat',
        '_ang_x_w',
        '_ang_y_w',
        '_ang_z_w',
        '_roll_w',
        '_pitch_w',
        '_yaw_w',
    ]

    _fields_and_field_types = {
        'quat': 'interface/Quat',
        'ang_x_w': 'double',
        'ang_y_w': 'double',
        'ang_z_w': 'double',
        'roll_w': 'double',
        'pitch_w': 'double',
        'yaw_w': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['interface', 'msg'], 'Quat'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from interface.msg import Quat
        self.quat = kwargs.get('quat', Quat())
        self.ang_x_w = kwargs.get('ang_x_w', float())
        self.ang_y_w = kwargs.get('ang_y_w', float())
        self.ang_z_w = kwargs.get('ang_z_w', float())
        self.roll_w = kwargs.get('roll_w', float())
        self.pitch_w = kwargs.get('pitch_w', float())
        self.yaw_w = kwargs.get('yaw_w', float())

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
        if self.quat != other.quat:
            return False
        if self.ang_x_w != other.ang_x_w:
            return False
        if self.ang_y_w != other.ang_y_w:
            return False
        if self.ang_z_w != other.ang_z_w:
            return False
        if self.roll_w != other.roll_w:
            return False
        if self.pitch_w != other.pitch_w:
            return False
        if self.yaw_w != other.yaw_w:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def quat(self):
        """Message field 'quat'."""
        return self._quat

    @quat.setter
    def quat(self, value):
        if __debug__:
            from interface.msg import Quat
            assert \
                isinstance(value, Quat), \
                "The 'quat' field must be a sub message of type 'Quat'"
        self._quat = value

    @builtins.property
    def ang_x_w(self):
        """Message field 'ang_x_w'."""
        return self._ang_x_w

    @ang_x_w.setter
    def ang_x_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ang_x_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ang_x_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ang_x_w = value

    @builtins.property
    def ang_y_w(self):
        """Message field 'ang_y_w'."""
        return self._ang_y_w

    @ang_y_w.setter
    def ang_y_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ang_y_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ang_y_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ang_y_w = value

    @builtins.property
    def ang_z_w(self):
        """Message field 'ang_z_w'."""
        return self._ang_z_w

    @ang_z_w.setter
    def ang_z_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ang_z_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ang_z_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ang_z_w = value

    @builtins.property
    def roll_w(self):
        """Message field 'roll_w'."""
        return self._roll_w

    @roll_w.setter
    def roll_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'roll_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._roll_w = value

    @builtins.property
    def pitch_w(self):
        """Message field 'pitch_w'."""
        return self._pitch_w

    @pitch_w.setter
    def pitch_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pitch_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pitch_w = value

    @builtins.property
    def yaw_w(self):
        """Message field 'yaw_w'."""
        return self._yaw_w

    @yaw_w.setter
    def yaw_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'yaw_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._yaw_w = value
