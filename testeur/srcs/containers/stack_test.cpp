/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:04 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/10 20:50:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include "stack.hpp"
#include <iostream>
#include <vector>
#include "vector.hpp"
#include <list>
#include "testeur.hpp"

#ifndef NAME_USE
# define NAME_USE std
#endif

static void	stack__test()
{
	NAME_USE::stack<int, NAME_USE::vector<int> > st;
	NAME_USE::vector<int> vect;

	vect.insert(vect.begin(), 48, 56);
	vect.insert(vect.begin(), 1, 23);
	vect.insert(vect.end(), 1, 85);
	NAME_USE::stack<int, NAME_USE::vector<int> > st2(vect);
	for (int i = 0; i < 50; i++)
	{
		std::cout << "size : " << st2.size() << std::endl;
		std::cout << st2.top();
		st2.pop();
	}
	for (int i = 0; i < 50; i++)
		st.push(i);
	std::cout << "empty : " << st.empty() << std::endl;
	for (int i = 0; i < 50; i++)
	{
		std::cout << "size :" << st.size() << std::endl;
		std::cout << st.top();
		st.pop();
	}
}

void	benchemarck_test()
{
	NAME_USE::stack<int, std::list<int> > st;

	long long int start = give_utime();
	for (int i = 0; i < 50000; i++)
		st.push(i);
	for (int i = 0; i < 50000; i++)
		st.pop();
	print_time("Stack", start);
}

void	stack_test()
{
	std::cout << "#############################################" << std::endl;
	std::cout << "################ Vector test ################" << std::endl;
	std::cout << "#############################################" << std::endl;
	std::cout << std::endl << "&&&&&&&& stack test &&&&&&&&" << std::endl;
	stack__test();
	std::cout << std::endl << "&&&&&&&& benchemarck test &&&&&&&&" << std::endl;
	benchemarck_test();
}