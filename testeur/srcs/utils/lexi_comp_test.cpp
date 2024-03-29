/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_comp_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:56 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:23:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_USE
# define NAME_USE std
#endif

#include <algorithm>
#include "lexicographical_compare.hpp"
#include <iostream>
#include <cctype>

bool mycomp (char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}

void	lexi_comp_test()
{
	std::cout << std::endl << std::endl << "Test lexicographical_compare:" << std::endl << std::endl;

	{
		char foo[]="Apple";
		char bar[]="apartment";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo+5, bar, bar+9) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo+5, bar, bar+9, mycomp) << std::endl;
	}
	{
		char foo[]="a";
		char bar[]="a";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo + 1, bar, bar + 1) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo + 1, bar, bar + 1, mycomp) << std::endl;
	}
	{
		char foo[]="ab";
		char bar[]="a";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo + 2, bar, bar + 1) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo + 2, bar, bar + 1, mycomp) << std::endl;
	}
	{
		char foo[]="a";
		char bar[]="ab";
	
		std::cout << std::boolalpha << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo + 1, bar, bar + 2) << std::endl;

		std::cout << "Using mycomp as comparison object: ";
		std::cout << NAME_USE::lexicographical_compare(foo, foo + 1, bar, bar + 2, mycomp) << std::endl;
	}
}
