/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 12:15:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <utility>
#else
# include "pair.hpp"
# include "make_pair.hpp"
#endif

#include "testeur.hpp"
#include <iostream>
#include <string>

using namespace NAMESPACE_USE;

void	pair_test()
{
	std::cout << "Test pair:" << std::endl << std::endl;
	pair <std::string,double> product1;
	pair <std::string,double> product2 ("tomatoes",2.30);
	pair <std::string,double> product3 (product2); 
	#if NB_NAMESPACE
		product1 = std::make_pair(std::string("lightbulbs"), 0.99);
	#else
		product1 = ft::make_pair(std::string("lightbulbs"), 0.99);
	#endif
	product2.first = "shoes";
	product2.second = 39.90;
	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
	
	pair <std::string,int> planet, homeplanet;
	#if NB_NAMESPACE
		planet = std::make_pair("Earth",6371);
	#else
		planet = ft::make_pair("Earth",6371);
	#endif
	homeplanet = planet;
	std::cout << "Home planet: " << homeplanet.first << std::endl;
	std::cout << "Planet size: " << homeplanet.second << std::endl;

	pair<int, double> test1 (10, 9.7);
	pair<int, double> test2 (90, 4.05);
	pair<int, double> test3 (test1);

	if (test1 == test2) 
		std::cout << "test1 and test2 are equal" << std::endl;
	if (test1 != test2)
		std::cout << "test1 and test2 are not equal" << std::endl;
	if (test1 < test2)
		std::cout << "test1 is less than test2" << std::endl;
	if (test1 > test2)
		std::cout << "test1 is greater than test2" << std::endl;
	if (test1 <= test2)
		std::cout << "test1 is less than or equal to test2" << std::endl;
	if (test1 >= test2)
		std::cout << "test1 is greater than or equal to test2" << std::endl;

	if (test1 == test3) 
		std::cout << "test1 and test3 are equal" << std::endl;
	if (test1 != test3)
		std::cout << "test1 and test3 are not equal" << std::endl;
	if (test1 < test3)
		std::cout << "test1 is less than test3" << std::endl;
	if (test1 > test3)
		std::cout << "test1 is greater than test3" << std::endl;
	if (test1 <= test3)
		std::cout << "test1 is less than or equal to test3" << std::endl;
	if (test1 >= test3)
		std::cout << "test1 is greater than or equal to test3" << std::endl;
}