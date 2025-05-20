// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from battle_interfaces:srv/Pointing.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__SRV__DETAIL__POINTING__BUILDER_HPP_
#define BATTLE_INTERFACES__SRV__DETAIL__POINTING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "battle_interfaces/srv/detail/pointing__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace battle_interfaces
{

namespace srv
{

namespace builder
{

class Init_Pointing_Request_target
{
public:
  Init_Pointing_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::battle_interfaces::srv::Pointing_Request target(::battle_interfaces::srv::Pointing_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::battle_interfaces::srv::Pointing_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::battle_interfaces::srv::Pointing_Request>()
{
  return battle_interfaces::srv::builder::Init_Pointing_Request_target();
}

}  // namespace battle_interfaces


namespace battle_interfaces
{

namespace srv
{

namespace builder
{

class Init_Pointing_Response_remark
{
public:
  explicit Init_Pointing_Response_remark(::battle_interfaces::srv::Pointing_Response & msg)
  : msg_(msg)
  {}
  ::battle_interfaces::srv::Pointing_Response remark(::battle_interfaces::srv::Pointing_Response::_remark_type arg)
  {
    msg_.remark = std::move(arg);
    return std::move(msg_);
  }

private:
  ::battle_interfaces::srv::Pointing_Response msg_;
};

class Init_Pointing_Response_accepted
{
public:
  Init_Pointing_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pointing_Response_remark accepted(::battle_interfaces::srv::Pointing_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Pointing_Response_remark(msg_);
  }

private:
  ::battle_interfaces::srv::Pointing_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::battle_interfaces::srv::Pointing_Response>()
{
  return battle_interfaces::srv::builder::Init_Pointing_Response_accepted();
}

}  // namespace battle_interfaces

#endif  // BATTLE_INTERFACES__SRV__DETAIL__POINTING__BUILDER_HPP_
