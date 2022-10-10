/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:01:19 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/10 20:33:14 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <string>
#include "testeur.hpp"

#ifndef NAME_USE
# define NAME_USE std
#endif

template <typename T>
static void printVector(NAME_USE::vector<T> vect)
{
	std::cout << "Vector content:" << std::endl;
	for (typename NAME_USE::vector<T>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vect.size() << std::endl;
	std::cout << "max_size: " << vect.max_size() << std::endl;
	std::cout << "capacity : " << vect.capacity() << std::endl;
	std::cout << "empty :" << vect.empty() << std::endl;
}

static void constructor_test()
{
	NAME_USE::vector<int> vect;
	printVector(vect);
	for (int i = 0; i <= 10; i++)
		vect.push_back(i);
	printVector(vect);

	NAME_USE::vector<int> vect2(vect);
	printVector(vect2);

	NAME_USE::vector<int> vect3(vect.begin(), vect.end());
	printVector(vect3);

	NAME_USE::vector<int> vect4(32, 1255);
	printVector(vect4);
}

static void insert_erase_test()
{
	NAME_USE::vector<int> vect;

	printVector(vect);
	vect.insert(vect.begin(), 12);
    printVector(vect);
	vect.push_back(12);
	printVector(vect);
	vect.insert(vect.begin(), 12, 5);
	printVector(vect);
	NAME_USE::vector<int> tmp(vect);
	vect.insert(vect.begin(), tmp.begin(), tmp.end());
	printVector(vect);
	vect.erase(vect.begin());
	printVector(vect);
	vect.erase(vect.begin() + 6, vect.begin() + 9);
	printVector(vect);
	vect.clear();
	printVector(vect);
}

static void iterator_test()
{
	NAME_USE::vector<std::string> vect;

	vect.push_back("coucou");
	vect.push_back("truc");
	vect.push_back("bidule");
	vect.push_back("bonjour");
	vect.push_back("machin");
	vect.push_back("chouete");
	vect.push_back("oiseau");
	vect.push_back("chien");
	vect.push_back("chat");
	vect.push_back("lettre");
	vect.push_back("A");
	vect.push_back("Albert");
	vect.push_back("main");
	vect.push_back("bras");
	printVector(vect);
	NAME_USE::vector<std::string>::iterator it(vect.begin());
	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *--it << std::endl;
	std::cout << *it-- << std::endl;
	printVector(vect);
	NAME_USE::vector<std::string>::reverse_iterator it2(vect.rbegin());
	std::cout << *(++it2) << std::endl;
	std::cout << *(it2++) << std::endl;
	std::cout << *it2++ << std::endl;
	std::cout << *++it2 << std::endl;
	std::cout << *(--it2) << std::endl;
	std::cout << *(it2--) << std::endl;
	std::cout << *--it2 << std::endl;
	std::cout << *it2-- << std::endl;
	printVector(vect);
	for (NAME_USE::vector<std::string>::reverse_iterator it = vect.rbegin(); it != vect.rend(); it++)
		std::cout << *it << std::endl;
}

static void other_test()
{	
	NAME_USE::vector<int> vect(3, 2);
	NAME_USE::vector<int> vect2(12, 5);
	printVector(vect);
	printVector(vect2);
	vect.assign(vect2.begin(), vect2.end());
	printVector(vect);
	vect.assign(22, 12);
	printVector(vect);
	for (int i = 0; i < 10; i++)
		vect.pop_back();
	printVector(vect);
	vect.resize(16);
	vect.push_back(16);
	vect2[0] = 13;
	vect2.at(8) = 6;
	printVector(vect);
	std::cout << vect.front();
	std::cout << vect.back();
}

static void	benchemarck_test()
{
	NAME_USE::vector<int> vect;

	long long int start = give_utime();
	vect.insert(vect.begin(), 10000000, 42);
	for (NAME_USE::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{}
	vect.erase(vect.begin(), vect.end());
	print_time("Vector", start);
}

void	vector_test()
{
	std::cout << "#############################################" << std::endl;
	std::cout << "################ Vector test ################" << std::endl;
	std::cout << "#############################################" << std::endl;
	std::cout << std::endl << "&&&&&&&& Construcor test &&&&&&&&" << std::endl;
	constructor_test();
	std::cout << std::endl << "&&&&&&&& Insertion deletion test &&&&&&&&" << std::endl;
	insert_erase_test();
	std::cout << std::endl << "&&&&&&&& Iterator test &&&&&&&&" << std::endl;
	iterator_test();
	std::cout << std::endl << "&&&&&&&& Other test &&&&&&&&" << std::endl;
	other_test();
	std::cout << std::endl << "&&&&&&&& benchemarck test &&&&&&&&" << std::endl;
	benchemarck_test();
}