// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from battle_interfaces:srv/Pointing.idl
// generated code does not contain a copyright notice

#ifndef BATTLE_INTERFACES__SRV__DETAIL__POINTING__TRAITS_HPP_
#define BATTLE_INTERFACES__SRV__DETAIL__POINTING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "battle_interfaces/srv/detail/pointing__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target'
#include "battle_interfaces/msg/detail/target__traits.hpp"

namespace battle_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Pointing_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    out << "target: ";
    to_flow_style_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pointing_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target:\n";
    to_block_style_yaml(msg.target, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pointing_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace battle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use battle_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const battle_interfaces::srv::Pointing_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  battle_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use battle_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const battle_interfaces::srv::Pointing_Request & msg)
{
  return battle_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<battle_interfaces::srv::Pointing_Request>()
{
  return "battle_interfaces::srv::Pointing_Request";
}

template<>
inline const char * name<battle_interfaces::srv::Pointing_Request>()
{
  return "battle_interfaces/srv/Pointing_Request";
}

template<>
struct has_fixed_size<battle_interfaces::srv::Pointing_Request>
  : std::integral_constant<bool, has_fixed_size<battle_interfaces::msg::Target>::value> {};

template<>
struct has_bounded_size<battle_interfaces::srv::Pointing_Request>
  : std::integral_constant<bool, has_bounded_size<battle_interfaces::msg::Target>::value> {};

template<>
struct is_message<battle_interfaces::srv::Pointing_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace battle_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Pointing_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: remark
  {
    out << "remark: ";
    rosidl_generator_traits::value_to_yaml(msg.remark, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pointing_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: remark
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remark: ";
    rosidl_generator_traits::value_to_yaml(msg.remark, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pointing_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace battle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use battle_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const battle_interfaces::srv::Pointing_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  battle_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use battle_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const battle_interfaces::srv::Pointing_Response & msg)
{
  return battle_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<battle_interfaces::srv::Pointing_Response>()
{
  return "battle_interfaces::srv::Pointing_Response";
}

template<>
inline const char * name<battle_interfaces::srv::Pointing_Response>()
{
  return "battle_interfaces/srv/Pointing_Response";
}

template<>
struct has_fixed_size<battle_interfaces::srv::Pointing_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<battle_interfaces::srv::Pointing_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<battle_interfaces::srv::Pointing_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<battle_interfaces::srv::Pointing>()
{
  return "battle_interfaces::srv::Pointing";
}

template<>
inline const char * name<battle_interfaces::srv::Pointing>()
{
  return "battle_interfaces/srv/Pointing";
}

template<>
struct has_fixed_size<battle_interfaces::srv::Pointing>
  : std::integral_constant<
    bool,
    has_fixed_size<battle_interfaces::srv::Pointing_Request>::value &&
    has_fixed_size<battle_interfaces::srv::Pointing_Response>::value
  >
{
};

template<>
struct has_bounded_size<battle_interfaces::srv::Pointing>
  : std::integral_constant<
    bool,
    has_bounded_size<battle_interfaces::srv::Pointing_Request>::value &&
    has_bounded_size<battle_interfaces::srv::Pointing_Response>::value
  >
{
};

template<>
struct is_service<battle_interfaces::srv::Pointing>
  : std::true_type
{
};

template<>
struct is_service_request<battle_interfaces::srv::Pointing_Request>
  : std::true_type
{
};

template<>
struct is_service_response<battle_interfaces::srv::Pointing_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BATTLE_INTERFACES__SRV__DETAIL__POINTING__TRAITS_HPP_
