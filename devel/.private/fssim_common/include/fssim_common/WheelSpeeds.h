// Generated by gencpp from file fssim_common/WheelSpeeds.msg
// DO NOT EDIT!


#ifndef FSSIM_COMMON_MESSAGE_WHEELSPEEDS_H
#define FSSIM_COMMON_MESSAGE_WHEELSPEEDS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace fssim_common
{
template <class ContainerAllocator>
struct WheelSpeeds_
{
  typedef WheelSpeeds_<ContainerAllocator> Type;

  WheelSpeeds_()
    : header()
    , version(0)
    , rpm_front_left(0)
    , rpm_front_right(0)
    , rpm_rear_left(0)
    , rpm_rear_right(0)  {
    }
  WheelSpeeds_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , version(0)
    , rpm_front_left(0)
    , rpm_front_right(0)
    , rpm_rear_left(0)
    , rpm_rear_right(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _version_type;
  _version_type version;

   typedef int16_t _rpm_front_left_type;
  _rpm_front_left_type rpm_front_left;

   typedef int16_t _rpm_front_right_type;
  _rpm_front_right_type rpm_front_right;

   typedef int16_t _rpm_rear_left_type;
  _rpm_rear_left_type rpm_rear_left;

   typedef int16_t _rpm_rear_right_type;
  _rpm_rear_right_type rpm_rear_right;





  typedef boost::shared_ptr< ::fssim_common::WheelSpeeds_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fssim_common::WheelSpeeds_<ContainerAllocator> const> ConstPtr;

}; // struct WheelSpeeds_

typedef ::fssim_common::WheelSpeeds_<std::allocator<void> > WheelSpeeds;

typedef boost::shared_ptr< ::fssim_common::WheelSpeeds > WheelSpeedsPtr;
typedef boost::shared_ptr< ::fssim_common::WheelSpeeds const> WheelSpeedsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fssim_common::WheelSpeeds_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fssim_common::WheelSpeeds_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fssim_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'fssim_common': ['/home/karenbarsegyan/BRTDriverless/src/fssim/fssim_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fssim_common::WheelSpeeds_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fssim_common::WheelSpeeds_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fssim_common::WheelSpeeds_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
{
  static const char* value()
  {
    return "de6e76c895b1095f899172fc46f64a60";
  }

  static const char* value(const ::fssim_common::WheelSpeeds_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xde6e76c895b1095fULL;
  static const uint64_t static_value2 = 0x899172fc46f64a60ULL;
};

template<class ContainerAllocator>
struct DataType< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fssim_common/WheelSpeeds";
  }

  static const char* value(const ::fssim_common::WheelSpeeds_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Header\n\
std_msgs/Header header\n\
uint8 version\n\
\n\
int16 rpm_front_left\n\
int16 rpm_front_right\n\
int16 rpm_rear_left\n\
int16 rpm_rear_right\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::fssim_common::WheelSpeeds_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.version);
      stream.next(m.rpm_front_left);
      stream.next(m.rpm_front_right);
      stream.next(m.rpm_rear_left);
      stream.next(m.rpm_rear_right);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WheelSpeeds_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fssim_common::WheelSpeeds_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fssim_common::WheelSpeeds_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "version: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.version);
    s << indent << "rpm_front_left: ";
    Printer<int16_t>::stream(s, indent + "  ", v.rpm_front_left);
    s << indent << "rpm_front_right: ";
    Printer<int16_t>::stream(s, indent + "  ", v.rpm_front_right);
    s << indent << "rpm_rear_left: ";
    Printer<int16_t>::stream(s, indent + "  ", v.rpm_rear_left);
    s << indent << "rpm_rear_right: ";
    Printer<int16_t>::stream(s, indent + "  ", v.rpm_rear_right);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FSSIM_COMMON_MESSAGE_WHEELSPEEDS_H