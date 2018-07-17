#pragma once

#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <string>

#include "is_container.h"

template <class T>
std::enable_if_t<std::is_integral<T>::value, void>
print_ip(const T &number_, std::ostream& os = std::cout)
{
	T number = number_;

	std::uint8_t array[sizeof(T)];

	for (unsigned int i = 0; i < sizeof(T); ++i)
	{
		array[i] = number;
		number >>= 8;
	}

	for (unsigned int i = sizeof(T) - 1; i >= 0; --i)
	{
		os << static_cast<int>(array[i]);

		if (i == 0)
			break;
		else
			os << ".";
	}
}

template <class T>
std::enable_if_t<is_stl_container<T>::value && std::is_integral<typename T::value_type>::value, void>
print_ip(const T &container, std::ostream& os = std::cout)
{
	for (auto it = std::begin(container); it != std::end(container); ++it)
	{
		os << *it;

		if (std::next(it) != std::end(container))
			os << ".";
	}
}

template<typename T>
struct is_string : public std::integral_constant<bool, std::is_same<char*, typename std::decay<T>::type>::value || std::is_same<const char*, typename std::decay<T>::type>::value> {};

template<>
struct is_string<std::string> : std::true_type {};

template <typename T>
typename std::enable_if<is_string<T>::value, void>::type
print_ip(T const & x, std::ostream& os = std::cout)
{
	os << x;
}
