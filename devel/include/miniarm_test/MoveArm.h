// Generated by gencpp from file miniarm_test/MoveArm.msg
// DO NOT EDIT!


#ifndef MINIARM_TEST_MESSAGE_MOVEARM_H
#define MINIARM_TEST_MESSAGE_MOVEARM_H

#include <ros/service_traits.h>


#include <miniarm_test/MoveArmRequest.h>
#include <miniarm_test/MoveArmResponse.h>


namespace miniarm_test
{

struct MoveArm
{

typedef MoveArmRequest Request;
typedef MoveArmResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveArm
} // namespace miniarm_test


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::miniarm_test::MoveArm > {
  static const char* value()
  {
    return "506c8e1e4563f2c77c2205a6a765a75c";
  }

  static const char* value(const ::miniarm_test::MoveArm&) { return value(); }
};

template<>
struct DataType< ::miniarm_test::MoveArm > {
  static const char* value()
  {
    return "miniarm_test/MoveArm";
  }

  static const char* value(const ::miniarm_test::MoveArm&) { return value(); }
};


// service_traits::MD5Sum< ::miniarm_test::MoveArmRequest> should match
// service_traits::MD5Sum< ::miniarm_test::MoveArm >
template<>
struct MD5Sum< ::miniarm_test::MoveArmRequest>
{
  static const char* value()
  {
    return MD5Sum< ::miniarm_test::MoveArm >::value();
  }
  static const char* value(const ::miniarm_test::MoveArmRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::miniarm_test::MoveArmRequest> should match
// service_traits::DataType< ::miniarm_test::MoveArm >
template<>
struct DataType< ::miniarm_test::MoveArmRequest>
{
  static const char* value()
  {
    return DataType< ::miniarm_test::MoveArm >::value();
  }
  static const char* value(const ::miniarm_test::MoveArmRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::miniarm_test::MoveArmResponse> should match
// service_traits::MD5Sum< ::miniarm_test::MoveArm >
template<>
struct MD5Sum< ::miniarm_test::MoveArmResponse>
{
  static const char* value()
  {
    return MD5Sum< ::miniarm_test::MoveArm >::value();
  }
  static const char* value(const ::miniarm_test::MoveArmResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::miniarm_test::MoveArmResponse> should match
// service_traits::DataType< ::miniarm_test::MoveArm >
template<>
struct DataType< ::miniarm_test::MoveArmResponse>
{
  static const char* value()
  {
    return DataType< ::miniarm_test::MoveArm >::value();
  }
  static const char* value(const ::miniarm_test::MoveArmResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MINIARM_TEST_MESSAGE_MOVEARM_H