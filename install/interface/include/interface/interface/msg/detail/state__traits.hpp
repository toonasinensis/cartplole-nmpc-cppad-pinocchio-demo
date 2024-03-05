// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__STATE__TRAITS_HPP_
#define INTERFACE__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interface/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'quat'
#include "interface/msg/detail/quat__traits.hpp"

namespace interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: quat
  {
    out << "quat: ";
    to_flow_style_yaml(msg.quat, out);
    out << ", ";
  }

  // member: ang_x_w
  {
    out << "ang_x_w: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_x_w, out);
    out << ", ";
  }

  // member: ang_y_w
  {
    out << "ang_y_w: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_y_w, out);
    out << ", ";
  }

  // member: ang_z_w
  {
    out << "ang_z_w: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_z_w, out);
    out << ", ";
  }

  // member: roll_w
  {
    out << "roll_w: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_w, out);
    out << ", ";
  }

  // member: pitch_w
  {
    out << "pitch_w: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_w, out);
    out << ", ";
  }

  // member: yaw_w
  {
    out << "yaw_w: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: quat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quat:\n";
    to_block_style_yaml(msg.quat, out, indentation + 2);
  }

  // member: ang_x_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ang_x_w: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_x_w, out);
    out << "\n";
  }

  // member: ang_y_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ang_y_w: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_y_w, out);
    out << "\n";
  }

  // member: ang_z_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ang_z_w: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_z_w, out);
    out << "\n";
  }

  // member: roll_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_w: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_w, out);
    out << "\n";
  }

  // member: pitch_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_w: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_w, out);
    out << "\n";
  }

  // member: yaw_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_w: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interface

namespace rosidl_generator_traits
{

[[deprecated("use interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interface::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const interface::msg::State & msg)
{
  return interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interface::msg::State>()
{
  return "interface::msg::State";
}

template<>
inline const char * name<interface::msg::State>()
{
  return "interface/msg/State";
}

template<>
struct has_fixed_size<interface::msg::State>
  : std::integral_constant<bool, has_fixed_size<interface::msg::Quat>::value> {};

template<>
struct has_bounded_size<interface::msg::State>
  : std::integral_constant<bool, has_bounded_size<interface::msg::Quat>::value> {};

template<>
struct is_message<interface::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__MSG__DETAIL__STATE__TRAITS_HPP_
