/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:53 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/19 09:53:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#include <type_traits>
#include "is_integral.hpp"
#include "testeur.hpp"
#include <iostream>
#include <string>

void	is_integral_test()
{
	std::cout << std::endl << std::endl << "Test is_integral:" << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "char: " << TESTED_NAMESPACE::is_integral<char>::value << std::endl;
	std::cout << "int: " << TESTED_NAMESPACE::is_integral<int>::value << std::endl;
	std::cout << "float: " << TESTED_NAMESPACE::is_integral<float>::value << std::endl;
	std::cout << "double: " << TESTED_NAMESPACE::is_integral<double>::value << std::endl;
	std::cout << "unsigned long long int: " << TESTED_NAMESPACE::is_integral<unsigned long long int>::value << std::endl;
	std::cout << "short int: " << TESTED_NAMESPACE::is_integral<short int>::value << std::endl;
	std::cout << "std::string: " << TESTED_NAMESPACE::is_integral<std::string>::value << std::endl;
}
