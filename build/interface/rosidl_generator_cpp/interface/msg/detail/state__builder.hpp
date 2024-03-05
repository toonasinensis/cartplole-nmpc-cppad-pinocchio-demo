// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_State_yaw_w
{
public:
  explicit Init_State_yaw_w(::interface::msg::State & msg)
  : msg_(msg)
  {}
  ::interface::msg::State yaw_w(::interface::msg::State::_yaw_w_type arg)
  {
    msg_.yaw_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_pitch_w
{
public:
  explicit Init_State_pitch_w(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_yaw_w pitch_w(::interface::msg::State::_pitch_w_type arg)
  {
    msg_.pitch_w = std::move(arg);
    return Init_State_yaw_w(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_roll_w
{
public:
  explicit Init_State_roll_w(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_pitch_w roll_w(::interface::msg::State::_roll_w_type arg)
  {
    msg_.roll_w = std::move(arg);
    return Init_State_pitch_w(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_ang_z_w
{
public:
  explicit Init_State_ang_z_w(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_roll_w ang_z_w(::interface::msg::State::_ang_z_w_type arg)
  {
    msg_.ang_z_w = std::move(arg);
    return Init_State_roll_w(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_ang_y_w
{
public:
  explicit Init_State_ang_y_w(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_ang_z_w ang_y_w(::interface::msg::State::_ang_y_w_type arg)
  {
    msg_.ang_y_w = std::move(arg);
    return Init_State_ang_z_w(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_ang_x_w
{
public:
  explicit Init_State_ang_x_w(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_ang_y_w ang_x_w(::interface::msg::State::_ang_x_w_type arg)
  {
    msg_.ang_x_w = std::move(arg);
    return Init_State_ang_y_w(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_quat
{
public:
  Init_State_quat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_ang_x_w quat(::interface::msg::State::_quat_type arg)
  {
    msg_.quat = std::move(arg);
    return Init_State_ang_x_w(msg_);
  }

private:
  ::interface::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::State>()
{
  return interface::msg::builder::Init_State_quat();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
