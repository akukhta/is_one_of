#pragma once

namespace iof
{
	template <typename T, typename U>
	struct is_same
	{
		static bool constexpr value = false;
	};

	template <typename T>
	struct is_same<T,T>
	{
		static bool constexpr value = true;
	};

	template <typename T, typename U>
	constexpr bool is_same_v = is_same<T, U>::value;
}

template <typename Type, typename... Args>
struct is_one_of;

template <typename Type, typename... Args>
struct is_one_of<Type, Type, Args...>
{
	static bool constexpr value = true;
};

template <typename Type, typename T, typename... Args>
struct is_one_of<Type, T, Args...>
{
	static bool constexpr value = is_one_of<Type, Args...>::value;
};

template <typename Type>
struct is_one_of<Type, Type>
{
	static bool constexpr value = true;
};

template <typename Type, typename T>
struct is_one_of<Type, T>
{
	static bool constexpr value = false;
};

template <typename Type, typename... Args>
constexpr bool is_one_of_v = is_one_of<Type, Args...>::value;

