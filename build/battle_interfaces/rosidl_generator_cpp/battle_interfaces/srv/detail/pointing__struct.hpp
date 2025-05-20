// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from battle_interfaces:srv/Pointing.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__SRV__DETAIL__POINTING__STRUCT_HPP_
#define BATTLE_INTERFACES__SRV__DETAIL__POINTING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target'
#include "battle_interfaces/msg/detail/target__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__battle_interfaces__srv__Pointing_Request __attribute__((deprecated))
#else
# define DEPRECATED__battle_interfaces__srv__Pointing_Request __declspec(deprecated)
#endif

namespace battle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Pointing_Request_
{
  using Type = Pointing_Request_<ContainerAllocator>;

  explicit Pointing_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_init)
  {
    (void)_init;
  }

  explicit Pointing_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _target_type =
    battle_interfaces::msg::Target_<ContainerAllocator>;
  _target_type target;

  // setters for named parameter idiom
  Type & set__target(
    const battle_interfaces::msg::Target_<ContainerAllocator> & _arg)
  {
    this->target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    battle_interfaces::srv::Pointing_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const battle_interfaces::srv::Pointing_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      battle_interfaces::srv::Pointing_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      battle_interfaces::srv::Pointing_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__battle_interfaces__srv__Pointing_Request
    std::shared_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__battle_interfaces__srv__Pointing_Request
    std::shared_ptr<battle_interfaces::srv::Pointing_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pointing_Request_ & other) const
  {
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pointing_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pointing_Request_

// alias to use template instance with default allocator
using Pointing_Request =
  battle_interfaces::srv::Pointing_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace battle_interfaces


#ifndef _WIN32
# define DEPRECATED__battle_interfaces__srv__Pointing_Response __attribute__((deprecated))
#else
# define DEPRECATED__battle_interfaces__srv__Pointing_Response __declspec(deprecated)
#endif

namespace battle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Pointing_Response_
{
  using Type = Pointing_Response_<ContainerAllocator>;

  explicit Pointing_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->remark = "";
    }
  }

  explicit Pointing_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : remark(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->remark = "";
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _remark_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _remark_type remark;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__remark(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->remark = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    battle_interfaces::srv::Pointing_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const battle_interfaces::srv::Pointing_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      battle_interfaces::srv::Pointing_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      battle_interfaces::srv::Pointing_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__battle_interfaces__srv__Pointing_Response
    std::shared_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__battle_interfaces__srv__Pointing_Response
    std::shared_ptr<battle_interfaces::srv::Pointing_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pointing_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->remark != other.remark) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pointing_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pointing_Response_

// alias to use template instance with default allocator
using Pointing_Response =
  battle_interfaces::srv::Pointing_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace battle_interfaces

namespace battle_interfaces
{

namespace srv
{

struct Pointing
{
  using Request = battle_interfaces::srv::Pointing_Request;
  using Response = battle_interfaces::srv::Pointing_Response;
};

}  // namespace srv

}  // namespace battle_interfaces

#endif  // BATTLE_INTERFACES__SRV__DETAIL__POINTING__STRUCT_HPP_
