/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:48 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/19 09:52:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#include <algorithm>
#include "equal.hpp"
#include "testeur.hpp"
#include <iostream>
#include <vector>

bool mypredicate (int i, int j)
{
	return (i == j);
}

bool mypredicate2 (int i, int j)
{
	return (i >= j);
}

void	equal_test()
{
	std::cout << std::endl << std::endl << "Test equal:" << std::endl << std::endl;
	
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	if (TESTED_NAMESPACE::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal." << std::endl;
	else
		std::cout << "The contents of both sequences differ." << std::endl;

	myvector[3]=81;
	if (TESTED_NAMESPACE::equal(myvector.begin(), myvector.end(), myints, mypredicate))
		std::cout << "The contents of both sequences are equal." << std::endl;
	else
		std::cout << "The contents of both sequences differ." << std::endl;

	if (TESTED_NAMESPACE::equal(myvector.begin(), myvector.end(), myints, mypredicate2))
		std::cout << "The contents of both sequences are equal." << std::endl;
	else
		std::cout << "The contents of both sequences differ." << std::endl;
}