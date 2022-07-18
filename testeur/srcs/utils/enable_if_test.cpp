/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:03:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 15:59:25 by bsavinel         ###   ########.fr       */
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
# include "enable_if.hpp"
#endif

#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

template <class T>
typename enable_if<is_integral<T>::value ,bool>::type is_odd (T i)
{
	return bool(i%2);
}

template <class T>
typename enable_if<is_integral<T>::value ,bool>::type is_even (T i)
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