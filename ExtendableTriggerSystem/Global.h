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
#include <initializer_list>
#include <functional>



template<typename T>
constexpr std::underlying_type_t<T> Type2Int(T type)
{
	return static_cast<std::underlying_type_t<T>>(type);
}

template<size_t T>
struct Int2Type { enum { Value = T }; };