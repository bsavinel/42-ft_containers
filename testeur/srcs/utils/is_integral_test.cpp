/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:53 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:23:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_USE
# define NAME_USE std
#endif

#include <type_traits>
#include "is_integral.hpp"
#include <iostream>
#include <string>

void	is_integral_test()
{
	std::cout << std::endl << std::endl << "Test is_integral:" << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "char: " << NAME_USE::is_integral<char>::value << std::endl;
	std::cout << "int: " << NAME_USE::is_integral<int>::value << std::endl;
	std::cout << "float: " << NAME_USE::is_integral<float>::value << std::endl;
	std::cout << "double: " << NAME_USE::is_integral<double>::value << std::endl;
	std::cout << "unsigned long long int: " << NAME_USE::is_integral<unsigned long long int>::value << std::endl;
	std::cout << "short int: " << NAME_USE::is_integral<short int>::value << std::endl;
	std::cout << "std::string: " << NAME_USE::is_integral<std::string>::value << std::endl;
}
