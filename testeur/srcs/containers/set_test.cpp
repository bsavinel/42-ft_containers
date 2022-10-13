/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:01 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/13 21:11:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeur.hpp"
#include "set.hpp"
#include <set>
#include <iostream>
#include <vector>

#ifndef NAME_USE
# define NAME_USE std
#endif

template <typename T>
static void	print_set(NAME_USE::set<T> st)
{
	std::cout << "size : " << st.size() << std::endl;
	std::cout << "max_size: " << st.max_size() << std::endl;
	std::cout << "empty :" << st.empty() << std::endl;
	for (typename NAME_USE::set<T>::iterator it = st.begin(); it != st.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

static void	constructor_test()
{
	NAME_USE::set<int> st;
	
	print_set(st);
	st.insert(12);
	st.insert(22);
	st.insert(32);
	st.insert(42);
	st.insert(52);
	print_set(st);
    st.insert(12);
	print_set(st);
	NAME_USE::set<int> st2(st);
    print_set(st2);
	NAME_USE::set<int> st3(st.begin(), st.end());
	print_set(st3);
}

static void	insert_erase_test()
{
	std::vector<int> vect;

	for (int i = 0; i < 10; ++i)
		vect.push_back(i);
	
	NAME_USE::set<int> st;
	st.insert(vect.begin(), vect.end());
	print_set(st);
	NAME_USE::set<int> st2;
	st2.insert(12);
	st2.insert(22);
	print_set(st2);
	st2.insert(st2.begin(), 32);
	st2.insert(st2.begin(), 42);
	st2.insert(st2.begin(), 52);
	print_set(st2);
	st.swap(st2);
	print_set(st);
	print_set(st2);
	st.erase(st.begin());
	print_set(st);
	st.erase(52);
	print_set(st);
	st2.erase(st2.begin(), st2.end());
	print_set(st2);
	st.clear();
	print_set(st);
}

static void	iterator_test()
{
	NAME_USE::set<int> st;

	for (int i = 0; i < 10; i++)
		st.insert(i * 2);

	NAME_USE::set<int>::reverse_iterator itr = st.rbegin();
	for (;itr != st.rend(); itr++)
		std::cout << *itr << std::endl;
}

static void	other_test()
{
	NAME_USE::set<int> st;

	for (int i = 0; i < 10; i++)
		st.insert(i * i);
	
	std::cout << *st.find(4) << std::endl;
	if (st.find(132123) == st.end())
		std::cout << "find failed" << std::endl;
	std::cout << st.count(3) << std::endl;
	std::cout << st.count(-3) << std::endl;
	std::cout << *st.lower_bound(3) << std::endl;
	if (st.lower_bound(-3) != st.end())
		std::cout << *st.lower_bound(-3) << std::endl;
	else
		std::cout << "lower_bound failed" << std::endl;
	std::cout << *st.upper_bound(3) << std::endl;
	if (st.lower_bound(-3) != st.end())
		std::cout << *st.upper_bound(-3) << std::endl;
	else
		std::cout << "lower_bound failed" << std::endl;
	std::cout << *st.equal_range(3).first << std::endl;
	std::cout << *st.equal_range(3).second << std::endl;
}

static void	benchemarck_test()
{
	long long int start = give_utime();
	NAME_USE::set<int> st;
	for (int i = 0; i < 100000; i++)
		st.insert(i);
	for	(NAME_USE::set<int>::iterator it = st.begin(); it != st.end(); it++)
		std::cout << *it << std::endl;
	for (int i = 0; i < 100000; i++)
		st.erase(i);
	print_time("Set", start);
}

void	set_test()
{
	std::cout << "##########################################" << std::endl;
	std::cout << "################ Set test ################" << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << std::endl << "&&&&&&&& Construcor test &&&&&&&&" << std::endl;
	constructor_test();
	std::cout << std::endl << "&&&&&&&& Insertion deletion test &&&&&&&&" << std::endl;
	insert_erase_test();
	std::cout << std::endl << "&&&&&&&& Iterator test &&&&&&&&" << std::endl;
	iterator_test();
	std::cout << std::endl << "&&&&&&&& Other test &&&&&&&&" << std::endl;
	other_test();
	std::cout << std::endl << "&&&&&&&& Benchemarck test &&&&&&&&" << std::endl;
	benchemarck_test();
}