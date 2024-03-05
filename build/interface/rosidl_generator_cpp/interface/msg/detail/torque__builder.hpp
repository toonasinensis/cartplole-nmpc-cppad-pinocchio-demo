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

class Init_Torque_tau_z_w
{
public:
  explicit Init_Torque_tau_z_w(::interface::msg::Torque & msg)
  : msg_(msg)
  {}
  ::interface::msg::Torque tau_z_w(::interface::msg::Torque::_tau_z_w_type arg)
  {
    msg_.tau_z_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::Torque msg_;
};

class Init_Torque_tau_y_w
{
public:
  explicit Init_Torque_tau_y_w(::interface::msg::Torque & msg)
  : msg_(msg)
  {}
  Init_Torque_tau_z_w tau_y_w(::interface::msg::Torque::_tau_y_w_type arg)
  {
    msg_.tau_y_w = std::move(arg);
    return Init_Torque_tau_z_w(msg_);
  }

private:
  ::interface::msg::Torque msg_;
};

class Init_Torque_tau_x_w
{
public:
  Init_Torque_tau_x_w()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Torque_tau_y_w tau_x_w(::interface::msg::Torque::_tau_x_w_type arg)
  {
    msg_.tau_x_w = std::move(arg);
    return Init_Torque_tau_y_w(msg_);
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
  return interface::msg::builder::Init_Torque_tau_x_w();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__TORQUE__BUILDER_HPP_
