// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from battle_interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET__TRAITS_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "battle_interfaces/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace battle_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Target & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Target & msg, bool use_flow_style = false)
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
  const battle_interfaces::msg::Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  battle_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use battle_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const battle_interfaces::msg::Target & msg)
{
  return battle_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<battle_interfaces::msg::Target>()
{
  return "battle_interfaces::msg::Target";
}

template<>
inline const char * name<battle_interfaces::msg::Target>()
{
  return "battle_interfaces/msg/Target";
}

template<>
struct has_fixed_size<battle_interfaces::msg::Target>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<battle_interfaces::msg::Target>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<battle_interfaces::msg::Target>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET__TRAITS_HPP_
