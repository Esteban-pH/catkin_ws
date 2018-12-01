// Generated by gencpp from file dialogflow_ros/DialogflowContext.msg
// DO NOT EDIT!


#ifndef DIALOGFLOW_ROS_MESSAGE_DIALOGFLOWCONTEXT_H
#define DIALOGFLOW_ROS_MESSAGE_DIALOGFLOWCONTEXT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <dialogflow_ros/DialogflowParameter.h>

namespace dialogflow_ros
{
template <class ContainerAllocator>
struct DialogflowContext_
{
  typedef DialogflowContext_<ContainerAllocator> Type;

  DialogflowContext_()
    : name()
    , lifespan_count(0)
    , parameters()  {
    }
  DialogflowContext_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , lifespan_count(0)
    , parameters(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef int32_t _lifespan_count_type;
  _lifespan_count_type lifespan_count;

   typedef std::vector< ::dialogflow_ros::DialogflowParameter_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::dialogflow_ros::DialogflowParameter_<ContainerAllocator> >::other >  _parameters_type;
  _parameters_type parameters;





  typedef boost::shared_ptr< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> const> ConstPtr;

}; // struct DialogflowContext_

typedef ::dialogflow_ros::DialogflowContext_<std::allocator<void> > DialogflowContext;

typedef boost::shared_ptr< ::dialogflow_ros::DialogflowContext > DialogflowContextPtr;
typedef boost::shared_ptr< ::dialogflow_ros::DialogflowContext const> DialogflowContextConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dialogflow_ros::DialogflowContext_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dialogflow_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'dialogflow_ros': ['/home/esteban/catkin_ws/src/dialogflow_ros/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6be440210c0bcdccbf7b418327271162";
  }

  static const char* value(const ::dialogflow_ros::DialogflowContext_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6be440210c0bcdccULL;
  static const uint64_t static_value2 = 0xbf7b418327271162ULL;
};

template<class ContainerAllocator>
struct DataType< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dialogflow_ros/DialogflowContext";
  }

  static const char* value(const ::dialogflow_ros::DialogflowContext_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
int32 lifespan_count\n\
DialogflowParameter[] parameters\n\
================================================================================\n\
MSG: dialogflow_ros/DialogflowParameter\n\
string name\n\
string value\n\
";
  }

  static const char* value(const ::dialogflow_ros::DialogflowContext_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.lifespan_count);
      stream.next(m.parameters);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DialogflowContext_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dialogflow_ros::DialogflowContext_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dialogflow_ros::DialogflowContext_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "lifespan_count: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lifespan_count);
    s << indent << "parameters[]" << std::endl;
    for (size_t i = 0; i < v.parameters.size(); ++i)
    {
      s << indent << "  parameters[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::dialogflow_ros::DialogflowParameter_<ContainerAllocator> >::stream(s, indent + "    ", v.parameters[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DIALOGFLOW_ROS_MESSAGE_DIALOGFLOWCONTEXT_H
