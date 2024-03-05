// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/Quat.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__QUAT__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__QUAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/quat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_Quat_w_w
{
public:
  explicit Init_Quat_w_w(::interface::msg::Quat & msg)
  : msg_(msg)
  {}
  ::interface::msg::Quat w_w(::interface::msg::Quat::_w_w_type arg)
  {
    msg_.w_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::Quat msg_;
};

class Init_Quat_z_w
{
public:
  explicit Init_Quat_z_w(::interface::msg::Quat & msg)
  : msg_(msg)
  {}
  Init_Quat_w_w z_w(::interface::msg::Quat::_z_w_type arg)
  {
    msg_.z_w = std::move(arg);
    return Init_Quat_w_w(msg_);
  }

private:
  ::interface::msg::Quat msg_;
};

class Init_Quat_y_w
{
public:
  explicit Init_Quat_y_w(::interface::msg::Quat & msg)
  : msg_(msg)
  {}
  Init_Quat_z_w y_w(::interface::msg::Quat::_y_w_type arg)
  {
    msg_.y_w = std::move(arg);
    return Init_Quat_z_w(msg_);
  }

private:
  ::interface::msg::Quat msg_;
};

class Init_Quat_x_w
{
public:
  Init_Quat_x_w()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Quat_y_w x_w(::interface::msg::Quat::_x_w_type arg)
  {
    msg_.x_w = std::move(arg);
    return Init_Quat_y_w(msg_);
  }

private:
  ::interface::msg::Quat msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::Quat>()
{
  return interface::msg::builder::Init_Quat_x_w();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__QUAT__BUILDER_HPP_
