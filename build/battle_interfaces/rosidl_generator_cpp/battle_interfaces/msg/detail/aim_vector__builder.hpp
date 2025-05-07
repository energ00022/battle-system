// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from battle_interfaces:msg/AimVector.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__BUILDER_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "battle_interfaces/msg/detail/aim_vector__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace battle_interfaces
{

namespace msg
{

namespace builder
{

class Init_AimVector_roll
{
public:
  explicit Init_AimVector_roll(::battle_interfaces::msg::AimVector & msg)
  : msg_(msg)
  {}
  ::battle_interfaces::msg::AimVector roll(::battle_interfaces::msg::AimVector::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return std::move(msg_);
  }

private:
  ::battle_interfaces::msg::AimVector msg_;
};

class Init_AimVector_pitch
{
public:
  explicit Init_AimVector_pitch(::battle_interfaces::msg::AimVector & msg)
  : msg_(msg)
  {}
  Init_AimVector_roll pitch(::battle_interfaces::msg::AimVector::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_AimVector_roll(msg_);
  }

private:
  ::battle_interfaces::msg::AimVector msg_;
};

class Init_AimVector_yaw
{
public:
  Init_AimVector_yaw()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AimVector_pitch yaw(::battle_interfaces::msg::AimVector::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_AimVector_pitch(msg_);
  }

private:
  ::battle_interfaces::msg::AimVector msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::battle_interfaces::msg::AimVector>()
{
  return battle_interfaces::msg::builder::Init_AimVector_yaw();
}

}  // namespace battle_interfaces

#endif  // BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__BUILDER_HPP_
