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

class Init_State_dq
{
public:
  explicit Init_State_dq(::interface::msg::State & msg)
  : msg_(msg)
  {}
  ::interface::msg::State dq(::interface::msg::State::_dq_type arg)
  {
    msg_.dq = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_dx
{
public:
  explicit Init_State_dx(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_dq dx(::interface::msg::State::_dx_type arg)
  {
    msg_.dx = std::move(arg);
    return Init_State_dq(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_q
{
public:
  explicit Init_State_q(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_dx q(::interface::msg::State::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_State_dx(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_x
{
public:
  Init_State_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_q x(::interface::msg::State::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_State_q(msg_);
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
  return interface::msg::builder::Init_State_x();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
