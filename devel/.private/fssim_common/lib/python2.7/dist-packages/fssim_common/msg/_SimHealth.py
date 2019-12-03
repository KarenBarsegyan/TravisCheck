# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from fssim_common/SimHealth.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import fssim_common.msg

class SimHealth(genpy.Message):
  _md5sum = "2d6de42391271dba371094f7524b84b6"
  _type = "fssim_common/SimHealth"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool request_shutdown 	# If TRUE we request immidiate shutdown
bool vehicle_started	# We send res message to start the vehicle	

TopicsHealth topics_health # List of topics and their health
================================================================================
MSG: fssim_common/TopicsHealth
bool topics_check_passed	# True is all topics passed check
float32 precision			# How much we allow to deviate topics freq from expected
TopicState[] topics_check  	# All topics health
================================================================================
MSG: fssim_common/TopicState
string topic_name
float32 expected_frequency
float32 measured_frequency
bool passed"""
  __slots__ = ['request_shutdown','vehicle_started','topics_health']
  _slot_types = ['bool','bool','fssim_common/TopicsHealth']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       request_shutdown,vehicle_started,topics_health

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SimHealth, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.request_shutdown is None:
        self.request_shutdown = False
      if self.vehicle_started is None:
        self.vehicle_started = False
      if self.topics_health is None:
        self.topics_health = fssim_common.msg.TopicsHealth()
    else:
      self.request_shutdown = False
      self.vehicle_started = False
      self.topics_health = fssim_common.msg.TopicsHealth()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3Bf().pack(_x.request_shutdown, _x.vehicle_started, _x.topics_health.topics_check_passed, _x.topics_health.precision))
      length = len(self.topics_health.topics_check)
      buff.write(_struct_I.pack(length))
      for val1 in self.topics_health.topics_check:
        _x = val1.topic_name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_2fB().pack(_x.expected_frequency, _x.measured_frequency, _x.passed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.topics_health is None:
        self.topics_health = fssim_common.msg.TopicsHealth()
      end = 0
      _x = self
      start = end
      end += 7
      (_x.request_shutdown, _x.vehicle_started, _x.topics_health.topics_check_passed, _x.topics_health.precision,) = _get_struct_3Bf().unpack(str[start:end])
      self.request_shutdown = bool(self.request_shutdown)
      self.vehicle_started = bool(self.vehicle_started)
      self.topics_health.topics_check_passed = bool(self.topics_health.topics_check_passed)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.topics_health.topics_check = []
      for i in range(0, length):
        val1 = fssim_common.msg.TopicState()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.topic_name = str[start:end].decode('utf-8')
        else:
          val1.topic_name = str[start:end]
        _x = val1
        start = end
        end += 9
        (_x.expected_frequency, _x.measured_frequency, _x.passed,) = _get_struct_2fB().unpack(str[start:end])
        val1.passed = bool(val1.passed)
        self.topics_health.topics_check.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3Bf().pack(_x.request_shutdown, _x.vehicle_started, _x.topics_health.topics_check_passed, _x.topics_health.precision))
      length = len(self.topics_health.topics_check)
      buff.write(_struct_I.pack(length))
      for val1 in self.topics_health.topics_check:
        _x = val1.topic_name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_2fB().pack(_x.expected_frequency, _x.measured_frequency, _x.passed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.topics_health is None:
        self.topics_health = fssim_common.msg.TopicsHealth()
      end = 0
      _x = self
      start = end
      end += 7
      (_x.request_shutdown, _x.vehicle_started, _x.topics_health.topics_check_passed, _x.topics_health.precision,) = _get_struct_3Bf().unpack(str[start:end])
      self.request_shutdown = bool(self.request_shutdown)
      self.vehicle_started = bool(self.vehicle_started)
      self.topics_health.topics_check_passed = bool(self.topics_health.topics_check_passed)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.topics_health.topics_check = []
      for i in range(0, length):
        val1 = fssim_common.msg.TopicState()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.topic_name = str[start:end].decode('utf-8')
        else:
          val1.topic_name = str[start:end]
        _x = val1
        start = end
        end += 9
        (_x.expected_frequency, _x.measured_frequency, _x.passed,) = _get_struct_2fB().unpack(str[start:end])
        val1.passed = bool(val1.passed)
        self.topics_health.topics_check.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2fB = None
def _get_struct_2fB():
    global _struct_2fB
    if _struct_2fB is None:
        _struct_2fB = struct.Struct("<2fB")
    return _struct_2fB
_struct_3Bf = None
def _get_struct_3Bf():
    global _struct_3Bf
    if _struct_3Bf is None:
        _struct_3Bf = struct.Struct("<3Bf")
    return _struct_3Bf
