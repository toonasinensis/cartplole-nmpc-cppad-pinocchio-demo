// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/Quat.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__QUAT__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__QUAT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interface__msg__Quat __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__Quat __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Quat_
{
  using Type = Quat_<ContainerAllocator>;

  explicit Quat_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_w = 0.0;
      this->y_w = 0.0;
      this->z_w = 0.0;
      this->w_w = 0.0;
    }
  }

  explicit Quat_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_w = 0.0;
      this->y_w = 0.0;
      this->z_w = 0.0;
      this->w_w = 0.0;
    }
  }

  // field types and members
  using _x_w_type =
    double;
  _x_w_type x_w;
  using _y_w_type =
    double;
  _y_w_type y_w;
  using _z_w_type =
    double;
  _z_w_type z_w;
  using _w_w_type =
    double;
  _w_w_type w_w;

  // setters for named parameter idiom
  Type & set__x_w(
    const double & _arg)
  {
    this->x_w = _arg;
    return *this;
  }
  Type & set__y_w(
    const double & _arg)
  {
    this->y_w = _arg;
    return *this;
  }
  Type & set__z_w(
    const double & _arg)
  {
    this->z_w = _arg;
    return *this;
  }
  Type & set__w_w(
    const double & _arg)
  {
    this->w_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::Quat_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::Quat_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::Quat_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::Quat_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::Quat_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::Quat_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::Quat_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::Quat_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::Quat_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::Quat_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__Quat
    std::shared_ptr<interface::msg::Quat_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__Quat
    std::shared_ptr<interface::msg::Quat_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Quat_ & other) const
  {
    if (this->x_w != other.x_w) {
      return false;
    }
    if (this->y_w != other.y_w) {
      return false;
    }
    if (this->z_w != other.z_w) {
      return false;
    }
    if (this->w_w != other.w_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const Quat_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Quat_

// alias to use template instance with default allocator
using Quat =
  interface::msg::Quat_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__QUAT__STRUCT_HPP_
