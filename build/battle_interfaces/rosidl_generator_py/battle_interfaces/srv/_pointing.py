# generated from rosidl_generator_py/resource/_idl.py.em
# with input from battle_interfaces:srv/Pointing.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Pointing_Request(type):
    """Metaclass of message 'Pointing_Request'."""

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
            module = import_type_support('battle_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'battle_interfaces.srv.Pointing_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__pointing__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__pointing__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__pointing__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__pointing__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__pointing__request

            from battle_interfaces.msg import Target
            if Target.__class__._TYPE_SUPPORT is None:
                Target.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Pointing_Request(metaclass=Metaclass_Pointing_Request):
    """Message class 'Pointing_Request'."""

    __slots__ = [
        '_target',
    ]

    _fields_and_field_types = {
        'target': 'battle_interfaces/Target',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['battle_interfaces', 'msg'], 'Target'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from battle_interfaces.msg import Target
        self.target = kwargs.get('target', Target())

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
        if self.target != other.target:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target(self):
        """Message field 'target'."""
        return self._target

    @target.setter
    def target(self, value):
        if __debug__:
            from battle_interfaces.msg import Target
            assert \
                isinstance(value, Target), \
                "The 'target' field must be a sub message of type 'Target'"
        self._target = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Pointing_Response(type):
    """Metaclass of message 'Pointing_Response'."""

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
            module = import_type_support('battle_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'battle_interfaces.srv.Pointing_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__pointing__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__pointing__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__pointing__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__pointing__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__pointing__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Pointing_Response(metaclass=Metaclass_Pointing_Response):
    """Message class 'Pointing_Response'."""

    __slots__ = [
        '_accepted',
        '_remark',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'remark': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        self.remark = kwargs.get('remark', str())

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
        if self.accepted != other.accepted:
            return False
        if self.remark != other.remark:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def remark(self):
        """Message field 'remark'."""
        return self._remark

    @remark.setter
    def remark(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'remark' field must be of type 'str'"
        self._remark = value


class Metaclass_Pointing(type):
    """Metaclass of service 'Pointing'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('battle_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'battle_interfaces.srv.Pointing')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__pointing

            from battle_interfaces.srv import _pointing
            if _pointing.Metaclass_Pointing_Request._TYPE_SUPPORT is None:
                _pointing.Metaclass_Pointing_Request.__import_type_support__()
            if _pointing.Metaclass_Pointing_Response._TYPE_SUPPORT is None:
                _pointing.Metaclass_Pointing_Response.__import_type_support__()


class Pointing(metaclass=Metaclass_Pointing):
    from battle_interfaces.srv._pointing import Pointing_Request as Request
    from battle_interfaces.srv._pointing import Pointing_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
