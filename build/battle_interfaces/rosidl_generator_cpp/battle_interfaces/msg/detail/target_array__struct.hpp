// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from battle_interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'targets'
#include "battle_interfaces/msg/detail/target__struct.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__battle_interfaces__msg__TargetArray __attribute__((deprecated))
#else
# define DEPRECATED__battle_interfaces__msg__TargetArray __declspec(deprecated)
#endif

namespace battle_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetArray_
{
  using Type = TargetArray_<ContainerAllocator>;

  explicit TargetArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
    }
  }

  explicit TargetArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    frame_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
    }
  }

  // field types and members
  using _targets_type =
    std::vector<battle_interfaces::msg::Target_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<battle_interfaces::msg::Target_<ContainerAllocator>>>;
  _targets_type targets;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _frame_id_type frame_id;

  // setters for named parameter idiom
  Type & set__targets(
    const std::vector<battle_interfaces::msg::Target_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<battle_interfaces::msg::Target_<ContainerAllocator>>> & _arg)
  {
    this->targets = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    battle_interfaces::msg::TargetArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const battle_interfaces::msg::TargetArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      battle_interfaces::msg::TargetArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      battle_interfaces::msg::TargetArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__battle_interfaces__msg__TargetArray
    std::shared_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__battle_interfaces__msg__TargetArray
    std::shared_ptr<battle_interfaces::msg::TargetArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetArray_ & other) const
  {
    if (this->targets != other.targets) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetArray_

// alias to use template instance with default allocator
using TargetArray =
  battle_interfaces::msg::TargetArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace battle_interfaces

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_HPP_
