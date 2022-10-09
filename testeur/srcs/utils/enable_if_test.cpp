/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:03:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:23:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_USE
# define NAME_USE std
#endif

#include <type_traits>
#include "is_integral.hpp"
#include "enable_if.hpp"
#include <iostream>

template <class T>
typename NAME_USE::enable_if<NAME_USE::is_integral<T>::value ,bool>::type is_odd (T i)
{
	return bool(i%2);
}

template <class T>
typename NAME_USE::enable_if<NAME_USE::is_integral<T>::value ,bool>::type is_even (T i)
{
	return !bool(i%2);
}

void	enable_if_test()
{
	std::cout << std::endl << std::endl << "Test enable_if:" << std::endl << std::endl;

	short int i = 1;

	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
	std::cout << "i is even: " << is_even(i) << std::endl;
}