/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:11:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/13 20:22:16 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "testeur.hpp"
#include <vector>
#include <iostream>
#include <string>

#ifndef NAME_USE
# define NAME_USE std
#endif

template <typename T1, typename T2>
static void print_pair(NAME_USE::pair<T1,T2> p)
{
	std::cout << p.first << " " << p.second << std::endl;
}

template <typename T1, typename T2>
static void print_map(NAME_USE::map<T1, T2> mp)
{
	typename NAME_USE::map<T1, T2>::iterator it = mp.begin();

	std::cout << "size : " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	std::cout << "empty :" << mp.empty() << std::endl;
	for (; it != mp.end(); it++)
		print_pair(*it);
}

static void	constructor_test()
{
	NAME_USE::map<int, std::string> mp;
	
	print_map(mp);
	mp.insert(NAME_USE::make_pair(2, "coucou"));
	mp.insert(NAME_USE::make_pair(2, "coucou"));
	print_map(mp);
	NAME_USE::map<int, std::string> mp2(mp);
	print_map(mp2);
	NAME_USE::map<int, std::string> mp3(mp.begin(), mp.end());
	mp.insert(NAME_USE::make_pair(2, "coucou"));
	print_map(mp3);
	mp = mp2;
	print_map(mp2);
}

static void insert_erase_test()
{
	NAME_USE::map<int, std::string> mp;

	print_map(mp);
	std::cout << mp.insert(NAME_USE::make_pair(2, "coucou")).second << std::endl;
	print_pair(*mp.insert(NAME_USE::make_pair(4, "bidule")).first);
	print_pair(*mp.insert(mp.begin(), NAME_USE::make_pair(3, "bidule")));
	print_map(mp);
	std::vector<NAME_USE::pair<int, std::string> > vect;
	vect.push_back(NAME_USE::make_pair(1, "rien"));
	vect.push_back(NAME_USE::make_pair(5, "vraiment"));
	vect.push_back(NAME_USE::make_pair(6, "rien"));
	
	print_map(mp);
	mp.erase(mp.begin());
	std::cout << mp.erase(mp.begin()->first) << std::endl;
	print_map(mp);
	mp.erase(mp.begin(), mp.end());
	print_map(mp);
}

static void	iterator_test()
{
	NAME_USE::map<int, int> mp;

	for (int i = 0; i < 10; i++)
		mp.insert(NAME_USE::make_pair(i * 2, i + 1));

	NAME_USE::map<int, int>::reverse_iterator itr = mp.rbegin();
	for (;itr != mp.rend(); itr++)
		print_pair(*itr);
}

static void other_test()
{
	NAME_USE::map<int, int> mp;

	for (int i = 0; i < 10; i++)
		mp.insert(NAME_USE::make_pair(i, i * i));
	
	std::cout << mp[3] << std::endl;
	print_map(mp);
	NAME_USE::map<int, int> mp2(mp);
	mp.clear();
	print_map(mp);
	mp.swap(mp2);
	print_map(mp);
	print_pair(*mp.find(3));
	if (mp.find(132123) == mp.end())
		std::cout << "find failed" << std::endl;
	std::cout << mp.count(3) << std::endl;
	std::cout << mp.count(-3) << std::endl;
	mp.erase(3);
	print_pair(*mp.lower_bound(3));
	if (mp.lower_bound(-3) != mp.end())
		print_pair(*mp.lower_bound(-3));
	else
		std::cout << "lower_bound failed" << std::endl;
	print_pair(*mp.upper_bound(3));
	if (mp.lower_bound(-3) != mp.end())
		print_pair(*mp.upper_bound(-3));
	else
		std::cout << "lower_bound failed" << std::endl;
	print_pair(*mp.equal_range(3).first);
	print_pair(*mp.equal_range(3).second);
}

static void benchemarck_test()
{
	long long int start = give_utime();
	NAME_USE::map<int, int> mp;
	for (int i = 0; i < 100000; i++)
		mp.insert(NAME_USE::make_pair(i, i));
	for	(NAME_USE::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		print_pair(*it);
	for (int i = 0; i < 100000; i++)
		mp.erase(i);
	print_time("Map", start);
}

void	map_test()
{
	std::cout << "##########################################" << std::endl;
	std::cout << "################ Map test ################" << std::endl;
	std::cout << "##########################################" << std::endl;
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
