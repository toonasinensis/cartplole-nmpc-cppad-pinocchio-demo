// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:msg/Quat.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__QUAT__TRAITS_HPP_
#define INTERFACE__MSG__DETAIL__QUAT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interface/msg/detail/quat__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Quat & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_w
  {
    out << "x_w: ";
    rosidl_generator_traits::value_to_yaml(msg.x_w, out);
    out << ", ";
  }

  // member: y_w
  {
    out << "y_w: ";
    rosidl_generator_traits::value_to_yaml(msg.y_w, out);
    out << ", ";
  }

  // member: z_w
  {
    out << "z_w: ";
    rosidl_generator_traits::value_to_yaml(msg.z_w, out);
    out << ", ";
  }

  // member: w_w
  {
    out << "w_w: ";
    rosidl_generator_traits::value_to_yaml(msg.w_w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Quat & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_w: ";
    rosidl_generator_traits::value_to_yaml(msg.x_w, out);
    out << "\n";
  }

  // member: y_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_w: ";
    rosidl_generator_traits::value_to_yaml(msg.y_w, out);
    out << "\n";
  }

  // member: z_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_w: ";
    rosidl_generator_traits::value_to_yaml(msg.z_w, out);
    out << "\n";
  }

  // member: w_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w_w: ";
    rosidl_generator_traits::value_to_yaml(msg.w_w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Quat & msg, bool use_flow_style = false)
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
  const interface::msg::Quat & msg,
  std::ostream & out, size_t indentation = 0)
{
  interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const interface::msg::Quat & msg)
{
  return interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interface::msg::Quat>()
{
  return "interface::msg::Quat";
}

template<>
inline const char * name<interface::msg::Quat>()
{
  return "interface/msg/Quat";
}

template<>
struct has_fixed_size<interface::msg::Quat>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::msg::Quat>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::msg::Quat>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__MSG__DETAIL__QUAT__TRAITS_HPP_
