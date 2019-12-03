// Generated by gencpp from file fsd_common_msgs/Mission.msg
// DO NOT EDIT!


#ifndef FSD_COMMON_MSGS_MESSAGE_MISSION_H
#define FSD_COMMON_MSGS_MESSAGE_MISSION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace fsd_common_msgs
{
template <class ContainerAllocator>
struct Mission_
{
  typedef Mission_<ContainerAllocator> Type;

  Mission_()
    : header()
    , mission()
    , finished(false)  {
    }
  Mission_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , mission(_alloc)
    , finished(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _mission_type;
  _mission_type mission;

   typedef uint8_t _finished_type;
  _finished_type finished;





  typedef boost::shared_ptr< ::fsd_common_msgs::Mission_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fsd_common_msgs::Mission_<ContainerAllocator> const> ConstPtr;

}; // struct Mission_

typedef ::fsd_common_msgs::Mission_<std::allocator<void> > Mission;

typedef boost::shared_ptr< ::fsd_common_msgs::Mission > MissionPtr;
typedef boost::shared_ptr< ::fsd_common_msgs::Mission const> MissionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fsd_common_msgs::Mission_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fsd_common_msgs::Mission_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fsd_common_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'fsd_common_msgs': ['/home/karenbarsegyan/BRTDriverless/src/0_fsd_common/fsd_common_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fsd_common_msgs::Mission_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fsd_common_msgs::Mission_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsd_common_msgs::Mission_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsd_common_msgs::Mission_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsd_common_msgs::Mission_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsd_common_msgs::Mission_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fsd_common_msgs::Mission_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aa152a842fbf6b840a20d415a574e050";
  }

  static const char* value(const ::fsd_common_msgs::Mission_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaa152a842fbf6b84ULL;
  static const uint64_t static_value2 = 0x0a20d415a574e050ULL;
};

template<class ContainerAllocator>
struct DataType< ::fsd_common_msgs::Mission_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fsd_common_msgs/Mission";
  }

  static const char* value(const ::fsd_common_msgs::Mission_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fsd_common_msgs::Mission_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Header\n\
std_msgs/Header header\n\
string mission\n\
bool finished\n\
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

  static const char* value(const ::fsd_common_msgs::Mission_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fsd_common_msgs::Mission_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.mission);
      stream.next(m.finished);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Mission_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fsd_common_msgs::Mission_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fsd_common_msgs::Mission_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "mission: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.mission);
    s << indent << "finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.finished);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FSD_COMMON_MSGS_MESSAGE_MISSION_H