// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from battle_interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__TRAITS_HPP_
#define BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "battle_interfaces/msg/detail/target_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'targets'
#include "battle_interfaces/msg/detail/target__traits.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace battle_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TargetArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: targets
  {
    if (msg.targets.size() == 0) {
      out << "targets: []";
    } else {
      out << "targets: [";
      size_t pending_items = msg.targets.size();
      for (auto item : msg.targets) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
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
  const TargetArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: targets
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.targets.size() == 0) {
      out << "targets: []\n";
    } else {
      out << "targets:\n";
      for (auto item : msg.targets) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
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

inline std::string to_yaml(const TargetArray & msg, bool use_flow_style = false)
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
  const battle_interfaces::msg::TargetArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  battle_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use battle_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const battle_interfaces::msg::TargetArray & msg)
{
  return battle_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<battle_interfaces::msg::TargetArray>()
{
  return "battle_interfaces::msg::TargetArray";
}

template<>
inline const char * name<battle_interfaces::msg::TargetArray>()
{
  return "battle_interfaces/msg/TargetArray";
}

template<>
struct has_fixed_size<battle_interfaces::msg::TargetArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<battle_interfaces::msg::TargetArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<battle_interfaces::msg::TargetArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BATTLE_INTERFACES__MSG__DETAIL__TARGET_ARRAY__TRAITS_HPP_
