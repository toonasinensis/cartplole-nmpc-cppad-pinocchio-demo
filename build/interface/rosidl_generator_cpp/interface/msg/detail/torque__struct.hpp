// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/Torque.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__TORQUE__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__TORQUE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interface__msg__Torque __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__Torque __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Torque_
{
  using Type = Torque_<ContainerAllocator>;

  explicit Torque_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tau_x_w = 0.0;
      this->tau_y_w = 0.0;
      this->tau_z_w = 0.0;
    }
  }

  explicit Torque_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tau_x_w = 0.0;
      this->tau_y_w = 0.0;
      this->tau_z_w = 0.0;
    }
  }

  // field types and members
  using _tau_x_w_type =
    double;
  _tau_x_w_type tau_x_w;
  using _tau_y_w_type =
    double;
  _tau_y_w_type tau_y_w;
  using _tau_z_w_type =
    double;
  _tau_z_w_type tau_z_w;

  // setters for named parameter idiom
  Type & set__tau_x_w(
    const double & _arg)
  {
    this->tau_x_w = _arg;
    return *this;
  }
  Type & set__tau_y_w(
    const double & _arg)
  {
    this->tau_y_w = _arg;
    return *this;
  }
  Type & set__tau_z_w(
    const double & _arg)
  {
    this->tau_z_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::Torque_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::Torque_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::Torque_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::Torque_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::Torque_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::Torque_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::Torque_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::Torque_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::Torque_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::Torque_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__Torque
    std::shared_ptr<interface::msg::Torque_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__Torque
    std::shared_ptr<interface::msg::Torque_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Torque_ & other) const
  {
    if (this->tau_x_w != other.tau_x_w) {
      return false;
    }
    if (this->tau_y_w != other.tau_y_w) {
      return false;
    }
    if (this->tau_z_w != other.tau_z_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const Torque_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Torque_

// alias to use template instance with default allocator
using Torque =
  interface::msg::Torque_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__TORQUE__STRUCT_HPP_
