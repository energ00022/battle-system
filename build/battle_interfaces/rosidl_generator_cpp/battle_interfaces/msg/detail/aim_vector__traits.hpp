// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from battle_interfaces:msg/AimVector.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__TRAITS_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "battle_interfaces/msg/detail/aim_vector__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace battle_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AimVector & msg,
  std::ostream & out)
{
  out << "{";
  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AimVector & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AimVector & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace battle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use battle_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const battle_interfaces::msg::AimVector & msg,
  std::ostream & out, size_t indentation = 0)
{
  battle_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use battle_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const battle_interfaces::msg::AimVector & msg)
{
  return battle_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<battle_interfaces::msg::AimVector>()
{
  return "battle_interfaces::msg::AimVector";
}

template<>
inline const char * name<battle_interfaces::msg::AimVector>()
{
  return "battle_interfaces/msg/AimVector";
}

template<>
struct has_fixed_size<battle_interfaces::msg::AimVector>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<battle_interfaces::msg::AimVector>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<battle_interfaces::msg::AimVector>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BATTLE_INTERFACES__MSG__DETAIL__AIM_VECTOR__TRAITS_HPP_
