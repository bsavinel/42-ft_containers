/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_comp_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:56 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 14:44:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
#include <algorithm>
#else
#include "lexicographical_compare.hpp"
#endif


#include "testeur.hpp"
#include <iostream>
#include <cctype>

using namespace NAMESPACE_USE;

bool mycomp (char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}

void	lexi_comp_test()
{
	std::cout << "Test lexicographical_compare:" << std::endl << std::endl;
	{
		char foo[]="Apple";
		char bar[]="apartment";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9, mycomp) << std::endl;
	}
	{
		char foo[]="a";
		char bar[]="a";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9, mycomp) << std::endl;
	}
	{
		char foo[]="ab";
		char bar[]="a";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9, mycomp) << std::endl;
	}
	{
		char foo[]="a";
		char bar[]="ab";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << lexicographical_compare(foo, foo+5, bar, bar+9, mycomp) << std::endl;
	}
}
