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
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->q = 0.0;
      this->dx = 0.0;
      this->dq = 0.0;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->q = 0.0;
      this->dx = 0.0;
      this->dq = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _q_type =
    double;
  _q_type q;
  using _dx_type =
    double;
  _dx_type dx;
  using _dq_type =
    double;
  _dq_type dq;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__q(
    const double & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__dx(
    const double & _arg)
  {
    this->dx = _arg;
    return *this;
  }
  Type & set__dq(
    const double & _arg)
  {
    this->dq = _arg;
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
    if (this->x != other.x) {
      return false;
    }
    if (this->q != other.q) {
      return false;
    }
    if (this->dx != other.dx) {
      return false;
    }
    if (this->dq != other.dq) {
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
