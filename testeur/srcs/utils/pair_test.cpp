/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:23:13 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_USE
# define NAME_USE std
#endif

#include <utility>
#include "pair.hpp"
#include "make_pair.hpp"
#include <iostream>
#include <string>

void	pair_test()
{
	std::cout << std::endl << std::endl << "Test pair:" << std::endl << std::endl;

	NAME_USE::pair<std::string,double> product1;
	NAME_USE::pair<std::string,double> product2 ("tomatoes",2.30);
	NAME_USE::pair<std::string,double> product3 (product2); 
	product1 = NAME_USE::make_pair(std::string("lightbulbs"), 0.99);
	product2.first = "shoes";
	product2.second = 39.90;
	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
	
	NAME_USE::pair <std::string,int> planet, homeplanet;
	planet = NAME_USE::make_pair("Earth",6371);
	homeplanet = planet;
	std::cout << "Home planet: " << homeplanet.first << std::endl;
	std::cout << "Planet size: " << homeplanet.second << std::endl;

	NAME_USE::pair<int, double> test1 (10, 9.7);
	NAME_USE::pair<int, double> test2 (90, 4.05);
	NAME_USE::pair<int, double> test3 (test1);

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