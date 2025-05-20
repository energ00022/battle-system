// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from battle_interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET__BUILDER_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "battle_interfaces/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace battle_interfaces
{

namespace msg
{

namespace builder
{

class Init_Target_frame_id
{
public:
  explicit Init_Target_frame_id(::battle_interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  ::battle_interfaces::msg::Target frame_id(::battle_interfaces::msg::Target::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::battle_interfaces::msg::Target msg_;
};

class Init_Target_confidence
{
public:
  explicit Init_Target_confidence(::battle_interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_frame_id confidence(::battle_interfaces::msg::Target::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_Target_frame_id(msg_);
  }

private:
  ::battle_interfaces::msg::Target msg_;
};

class Init_Target_z
{
public:
  explicit Init_Target_z(::battle_interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_confidence z(::battle_interfaces::msg::Target::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Target_confidence(msg_);
  }

private:
  ::battle_interfaces::msg::Target msg_;
};

class Init_Target_y
{
public:
  explicit Init_Target_y(::battle_interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_z y(::battle_interfaces::msg::Target::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Target_z(msg_);
  }

private:
  ::battle_interfaces::msg::Target msg_;
};

class Init_Target_x
{
public:
  explicit Init_Target_x(::battle_interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_y x(::battle_interfaces::msg::Target::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Target_y(msg_);
  }

private:
  ::battle_interfaces::msg::Target msg_;
};

class Init_Target_id
{
public:
  Init_Target_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Target_x id(::battle_interfaces::msg::Target::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Target_x(msg_);
  }

private:
  ::battle_interfaces::msg::Target msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::battle_interfaces::msg::Target>()
{
  return battle_interfaces::msg::builder::Init_Target_id();
}

}  // namespace battle_interfaces

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET__BUILDER_HPP_
