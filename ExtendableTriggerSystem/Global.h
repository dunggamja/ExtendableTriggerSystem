#pragma once

#include <vector>
#include <memory>
#include <list>
#include <type_traits>
#include <map>
#include <unordered_map>
#include <optional>
#include <variant>
#include <algorithm>
#include <string>
#include <tuple>
#include <array>



template<typename T>
constexpr int Type2Int(T type)
{
	return std::underlying_type_t(type);
}