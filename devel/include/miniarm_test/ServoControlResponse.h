// Generated by gencpp from file miniarm_test/ServoControlResponse.msg
// DO NOT EDIT!


#ifndef MINIARM_TEST_MESSAGE_SERVOCONTROLRESPONSE_H
#define MINIARM_TEST_MESSAGE_SERVOCONTROLRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace miniarm_test
{
template <class ContainerAllocator>
struct ServoControlResponse_
{
  typedef ServoControlResponse_<ContainerAllocator> Type;

  ServoControlResponse_()
    : success(false)
    , message()  {
    }
  ServoControlResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , message(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type;
  _message_type message;





  typedef boost::shared_ptr< ::miniarm_test::ServoControlResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::miniarm_test::ServoControlResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ServoControlResponse_

typedef ::miniarm_test::ServoControlResponse_<std::allocator<void> > ServoControlResponse;

typedef boost::shared_ptr< ::miniarm_test::ServoControlResponse > ServoControlResponsePtr;
typedef boost::shared_ptr< ::miniarm_test::ServoControlResponse const> ServoControlResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::miniarm_test::ServoControlResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::miniarm_test::ServoControlResponse_<ContainerAllocator1> & lhs, const ::miniarm_test::ServoControlResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success &&
    lhs.message == rhs.message;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::miniarm_test::ServoControlResponse_<ContainerAllocator1> & lhs, const ::miniarm_test::ServoControlResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace miniarm_test

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::miniarm_test::ServoControlResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::miniarm_test::ServoControlResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::miniarm_test::ServoControlResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "937c9679a518e3a18d831e57125ea522";
  }

  static const char* value(const ::miniarm_test::ServoControlResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x937c9679a518e3a1ULL;
  static const uint64_t static_value2 = 0x8d831e57125ea522ULL;
};

template<class ContainerAllocator>
struct DataType< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "miniarm_test/ServoControlResponse";
  }

  static const char* value(const ::miniarm_test::ServoControlResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n"
"string message\n"
"\n"
;
  }

  static const char* value(const ::miniarm_test::ServoControlResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ServoControlResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::miniarm_test::ServoControlResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::miniarm_test::ServoControlResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MINIARM_TEST_MESSAGE_SERVOCONTROLRESPONSE_H
