// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/Torque.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__TORQUE__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__TORQUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/torque__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_Torque_u
{
public:
  Init_Torque_u()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::msg::Torque u(::interface::msg::Torque::_u_type arg)
  {
    msg_.u = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::Torque msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::Torque>()
{
  return interface::msg::builder::Init_Torque_u();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__TORQUE__BUILDER_HPP_
