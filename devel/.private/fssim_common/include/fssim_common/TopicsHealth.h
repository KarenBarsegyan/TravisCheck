// Generated by gencpp from file fssim_common/TopicsHealth.msg
// DO NOT EDIT!


#ifndef FSSIM_COMMON_MESSAGE_TOPICSHEALTH_H
#define FSSIM_COMMON_MESSAGE_TOPICSHEALTH_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <fssim_common/TopicState.h>

namespace fssim_common
{
template <class ContainerAllocator>
struct TopicsHealth_
{
  typedef TopicsHealth_<ContainerAllocator> Type;

  TopicsHealth_()
    : topics_check_passed(false)
    , precision(0.0)
    , topics_check()  {
    }
  TopicsHealth_(const ContainerAllocator& _alloc)
    : topics_check_passed(false)
    , precision(0.0)
    , topics_check(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _topics_check_passed_type;
  _topics_check_passed_type topics_check_passed;

   typedef float _precision_type;
  _precision_type precision;

   typedef std::vector< ::fssim_common::TopicState_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::fssim_common::TopicState_<ContainerAllocator> >::other >  _topics_check_type;
  _topics_check_type topics_check;





  typedef boost::shared_ptr< ::fssim_common::TopicsHealth_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fssim_common::TopicsHealth_<ContainerAllocator> const> ConstPtr;

}; // struct TopicsHealth_

typedef ::fssim_common::TopicsHealth_<std::allocator<void> > TopicsHealth;

typedef boost::shared_ptr< ::fssim_common::TopicsHealth > TopicsHealthPtr;
typedef boost::shared_ptr< ::fssim_common::TopicsHealth const> TopicsHealthConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fssim_common::TopicsHealth_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fssim_common::TopicsHealth_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fssim_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'fssim_common': ['/home/karenbarsegyan/BRTDriverless/src/fssim/fssim_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fssim_common::TopicsHealth_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fssim_common::TopicsHealth_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fssim_common::TopicsHealth_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fssim_common::TopicsHealth_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fssim_common::TopicsHealth_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fssim_common::TopicsHealth_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fssim_common::TopicsHealth_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2e4a29cd88c13c0624f8c9a144bda96c";
  }

  static const char* value(const ::fssim_common::TopicsHealth_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2e4a29cd88c13c06ULL;
  static const uint64_t static_value2 = 0x24f8c9a144bda96cULL;
};

template<class ContainerAllocator>
struct DataType< ::fssim_common::TopicsHealth_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fssim_common/TopicsHealth";
  }

  static const char* value(const ::fssim_common::TopicsHealth_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fssim_common::TopicsHealth_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool topics_check_passed	# True is all topics passed check\n\
float32 precision			# How much we allow to deviate topics freq from expected\n\
TopicState[] topics_check  	# All topics health\n\
================================================================================\n\
MSG: fssim_common/TopicState\n\
string topic_name\n\
float32 expected_frequency\n\
float32 measured_frequency\n\
bool passed\n\
";
  }

  static const char* value(const ::fssim_common::TopicsHealth_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fssim_common::TopicsHealth_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.topics_check_passed);
      stream.next(m.precision);
      stream.next(m.topics_check);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TopicsHealth_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fssim_common::TopicsHealth_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fssim_common::TopicsHealth_<ContainerAllocator>& v)
  {
    s << indent << "topics_check_passed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.topics_check_passed);
    s << indent << "precision: ";
    Printer<float>::stream(s, indent + "  ", v.precision);
    s << indent << "topics_check[]" << std::endl;
    for (size_t i = 0; i < v.topics_check.size(); ++i)
    {
      s << indent << "  topics_check[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::fssim_common::TopicState_<ContainerAllocator> >::stream(s, indent + "    ", v.topics_check[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // FSSIM_COMMON_MESSAGE_TOPICSHEALTH_H