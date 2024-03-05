// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__STATE__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'quat'
#include "interface/msg/detail/quat__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__State __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : quat(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ang_x_w = 0.0;
      this->ang_y_w = 0.0;
      this->ang_z_w = 0.0;
      this->roll_w = 0.0;
      this->pitch_w = 0.0;
      this->yaw_w = 0.0;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : quat(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ang_x_w = 0.0;
      this->ang_y_w = 0.0;
      this->ang_z_w = 0.0;
      this->roll_w = 0.0;
      this->pitch_w = 0.0;
      this->yaw_w = 0.0;
    }
  }

  // field types and members
  using _quat_type =
    interface::msg::Quat_<ContainerAllocator>;
  _quat_type quat;
  using _ang_x_w_type =
    double;
  _ang_x_w_type ang_x_w;
  using _ang_y_w_type =
    double;
  _ang_y_w_type ang_y_w;
  using _ang_z_w_type =
    double;
  _ang_z_w_type ang_z_w;
  using _roll_w_type =
    double;
  _roll_w_type roll_w;
  using _pitch_w_type =
    double;
  _pitch_w_type pitch_w;
  using _yaw_w_type =
    double;
  _yaw_w_type yaw_w;

  // setters for named parameter idiom
  Type & set__quat(
    const interface::msg::Quat_<ContainerAllocator> & _arg)
  {
    this->quat = _arg;
    return *this;
  }
  Type & set__ang_x_w(
    const double & _arg)
  {
    this->ang_x_w = _arg;
    return *this;
  }
  Type & set__ang_y_w(
    const double & _arg)
  {
    this->ang_y_w = _arg;
    return *this;
  }
  Type & set__ang_z_w(
    const double & _arg)
  {
    this->ang_z_w = _arg;
    return *this;
  }
  Type & set__roll_w(
    const double & _arg)
  {
    this->roll_w = _arg;
    return *this;
  }
  Type & set__pitch_w(
    const double & _arg)
  {
    this->pitch_w = _arg;
    return *this;
  }
  Type & set__yaw_w(
    const double & _arg)
  {
    this->yaw_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__State
    std::shared_ptr<interface::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__State
    std::shared_ptr<interface::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->quat != other.quat) {
      return false;
    }
    if (this->ang_x_w != other.ang_x_w) {
      return false;
    }
    if (this->ang_y_w != other.ang_y_w) {
      return false;
    }
    if (this->ang_z_w != other.ang_z_w) {
      return false;
    }
    if (this->roll_w != other.roll_w) {
      return false;
    }
    if (this->pitch_w != other.pitch_w) {
      return false;
    }
    if (this->yaw_w != other.yaw_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  interface::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__STATE__STRUCT_HPP_
