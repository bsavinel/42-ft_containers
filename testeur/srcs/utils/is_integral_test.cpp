/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:53 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 15:28:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <type_traits>
#else
# include "is_integral.hpp"
#endif

#include "testeur.hpp"
#include <iostream>
#include <string>

using namespace NAMESPACE_USE;

void	is_integral_test()
{
	std::cout << std::endl << std::endl << "Test is_integral:" << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "char: " << is_integral<char>::value << std::endl;
	std::cout << "int: " << is_integral<int>::value << std::endl;
	std::cout << "float: " << is_integral<float>::value << std::endl;
	std::cout << "double: " << is_integral<double>::value << std::endl;
	std::cout << "unsigned long long int: " << is_integral<unsigned long long int>::value << std::endl;
	std::cout << "short int: " << is_integral<short int>::value << std::endl;
	std::cout << "std::string: " << is_integral<std::string>::value << std::endl;
}
