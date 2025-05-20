// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from battle_interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "battle_interfaces/msg/detail/target_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace battle_interfaces
{

namespace msg
{

namespace builder
{

class Init_TargetArray_frame_id
{
public:
  explicit Init_TargetArray_frame_id(::battle_interfaces::msg::TargetArray & msg)
  : msg_(msg)
  {}
  ::battle_interfaces::msg::TargetArray frame_id(::battle_interfaces::msg::TargetArray::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::battle_interfaces::msg::TargetArray msg_;
};

class Init_TargetArray_stamp
{
public:
  explicit Init_TargetArray_stamp(::battle_interfaces::msg::TargetArray & msg)
  : msg_(msg)
  {}
  Init_TargetArray_frame_id stamp(::battle_interfaces::msg::TargetArray::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_TargetArray_frame_id(msg_);
  }

private:
  ::battle_interfaces::msg::TargetArray msg_;
};

class Init_TargetArray_targets
{
public:
  Init_TargetArray_targets()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetArray_stamp targets(::battle_interfaces::msg::TargetArray::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return Init_TargetArray_stamp(msg_);
  }

private:
  ::battle_interfaces::msg::TargetArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::battle_interfaces::msg::TargetArray>()
{
  return battle_interfaces::msg::builder::Init_TargetArray_targets();
}

}  // namespace battle_interfaces

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_
