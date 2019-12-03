// Generated by gencpp from file fsd_common_msgs/CarState.msg
// DO NOT EDIT!


#ifndef FSD_COMMON_MSGS_MESSAGE_CARSTATE_H
#define FSD_COMMON_MSGS_MESSAGE_CARSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose2D.h>
#include <fsd_common_msgs/CarStateDt.h>

namespace fsd_common_msgs
{
template <class ContainerAllocator>
struct CarState_
{
  typedef CarState_<ContainerAllocator> Type;

  CarState_()
    : header()
    , car_state()
    , car_state_dt()  {
    }
  CarState_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , car_state(_alloc)
    , car_state_dt(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Pose2D_<ContainerAllocator>  _car_state_type;
  _car_state_type car_state;

   typedef  ::fsd_common_msgs::CarStateDt_<ContainerAllocator>  _car_state_dt_type;
  _car_state_dt_type car_state_dt;





  typedef boost::shared_ptr< ::fsd_common_msgs::CarState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fsd_common_msgs::CarState_<ContainerAllocator> const> ConstPtr;

}; // struct CarState_

typedef ::fsd_common_msgs::CarState_<std::allocator<void> > CarState;

typedef boost::shared_ptr< ::fsd_common_msgs::CarState > CarStatePtr;
typedef boost::shared_ptr< ::fsd_common_msgs::CarState const> CarStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fsd_common_msgs::CarState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fsd_common_msgs::CarState_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::fsd_common_msgs::CarState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fsd_common_msgs::CarState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsd_common_msgs::CarState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsd_common_msgs::CarState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsd_common_msgs::CarState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsd_common_msgs::CarState_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fsd_common_msgs::CarState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "be929b6a6d1d1d2c80065a8e530992fd";
  }

  static const char* value(const ::fsd_common_msgs::CarState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbe929b6a6d1d1d2cULL;
  static const uint64_t static_value2 = 0x80065a8e530992fdULL;
};

template<class ContainerAllocator>
struct DataType< ::fsd_common_msgs::CarState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fsd_common_msgs/CarState";
  }

  static const char* value(const ::fsd_common_msgs::CarState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fsd_common_msgs::CarState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n\
\n\
geometry_msgs/Pose2D car_state    			# Position in x, y, theta\n\
fsd_common_msgs/CarStateDt car_state_dt		# Velocities\n\
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
MSG: geometry_msgs/Pose2D\n\
# Deprecated\n\
# Please use the full 3D pose.\n\
\n\
# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.\n\
\n\
# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.\n\
\n\
\n\
# This expresses a position and orientation on a 2D manifold.\n\
\n\
float64 x\n\
float64 y\n\
float64 theta\n\
\n\
================================================================================\n\
MSG: fsd_common_msgs/CarStateDt\n\
std_msgs/Header header\n\
\n\
geometry_msgs/Pose2D car_state_dt   # Velocity in x, y, theta\n\
";
  }

  static const char* value(const ::fsd_common_msgs::CarState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fsd_common_msgs::CarState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.car_state);
      stream.next(m.car_state_dt);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CarState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fsd_common_msgs::CarState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fsd_common_msgs::CarState_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "car_state: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose2D_<ContainerAllocator> >::stream(s, indent + "  ", v.car_state);
    s << indent << "car_state_dt: ";
    s << std::endl;
    Printer< ::fsd_common_msgs::CarStateDt_<ContainerAllocator> >::stream(s, indent + "  ", v.car_state_dt);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FSD_COMMON_MSGS_MESSAGE_CARSTATE_H
