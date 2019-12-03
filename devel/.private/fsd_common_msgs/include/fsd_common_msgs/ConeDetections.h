// Generated by gencpp from file fsd_common_msgs/ConeDetections.msg
// DO NOT EDIT!


#ifndef FSD_COMMON_MSGS_MESSAGE_CONEDETECTIONS_H
#define FSD_COMMON_MSGS_MESSAGE_CONEDETECTIONS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <fsd_common_msgs/Cone.h>

namespace fsd_common_msgs
{
template <class ContainerAllocator>
struct ConeDetections_
{
  typedef ConeDetections_<ContainerAllocator> Type;

  ConeDetections_()
    : header()
    , cone_detections()  {
    }
  ConeDetections_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , cone_detections(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::fsd_common_msgs::Cone_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::fsd_common_msgs::Cone_<ContainerAllocator> >::other >  _cone_detections_type;
  _cone_detections_type cone_detections;





  typedef boost::shared_ptr< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> const> ConstPtr;

}; // struct ConeDetections_

typedef ::fsd_common_msgs::ConeDetections_<std::allocator<void> > ConeDetections;

typedef boost::shared_ptr< ::fsd_common_msgs::ConeDetections > ConeDetectionsPtr;
typedef boost::shared_ptr< ::fsd_common_msgs::ConeDetections const> ConeDetectionsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fsd_common_msgs::ConeDetections_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
{
  static const char* value()
  {
    return "905dd9eb6d37422f728e412e2f15b0eb";
  }

  static const char* value(const ::fsd_common_msgs::ConeDetections_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x905dd9eb6d37422fULL;
  static const uint64_t static_value2 = 0x728e412e2f15b0ebULL;
};

template<class ContainerAllocator>
struct DataType< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fsd_common_msgs/ConeDetections";
  }

  static const char* value(const ::fsd_common_msgs::ConeDetections_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n\
\n\
fsd_common_msgs/Cone[] cone_detections\n\
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
\n\
================================================================================\n\
MSG: fsd_common_msgs/Cone\n\
geometry_msgs/Point position  # coordinate of cone in [x, y]\n\
std_msgs/String color           # color of cone, 'b' = blue, 'y' = yellow, 'o' = orange\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: std_msgs/String\n\
string data\n\
";
  }

  static const char* value(const ::fsd_common_msgs::ConeDetections_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.cone_detections);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ConeDetections_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fsd_common_msgs::ConeDetections_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fsd_common_msgs::ConeDetections_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "cone_detections[]" << std::endl;
    for (size_t i = 0; i < v.cone_detections.size(); ++i)
    {
      s << indent << "  cone_detections[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::fsd_common_msgs::Cone_<ContainerAllocator> >::stream(s, indent + "    ", v.cone_detections[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // FSD_COMMON_MSGS_MESSAGE_CONEDETECTIONS_H