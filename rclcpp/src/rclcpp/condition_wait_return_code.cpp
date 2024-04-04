// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <string>
#include <type_traits>

#include "rclcpp/condition_wait_return_code.hpp"

namespace rclcpp
{

std::ostream &
operator<<(std::ostream & os, const rclcpp::ConditionWaitReturnCode & condition_wait_return_code)
{
  return os << to_string(condition_wait_return_code);
}

std::string
to_string(const rclcpp::ConditionWaitReturnCode & condition_wait_return_code)
{
  using enum_type = std::underlying_type<ConditionWaitReturnCode>::type;
  std::string prefix = "Unknown enum value (";
  std::string ret_as_string = std::to_string(static_cast<enum_type>(condition_wait_return_code));
  switch (condition_wait_return_code) {
    case ConditionWaitReturnCode::SUCCESS:
      prefix = "SUCCESS (";
      break;
    case ConditionWaitReturnCode::INTERRUPTED:
      prefix = "INTERRUPTED (";
      break;
    case ConditionWaitReturnCode::TIMEOUT:
      prefix = "TIMEOUT (";
      break;
  }
  return prefix + ret_as_string + ")";
}

}  // namespace rclcpp