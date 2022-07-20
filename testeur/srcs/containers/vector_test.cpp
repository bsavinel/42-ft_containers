/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:01:19 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/20 22:43:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <vector>
#else
# include "vector.hpp"
#endif


#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	vector_test()
{
	std::cout << std::endl << std::endl << "Test vector:" << std::endl << std::endl;
	{
		vector<int> test1;

		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.pop_back();
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.pop_back();
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
	}
	{
		vector<int> test1;

		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.clear();
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		vector<int>::const_iterator it_const = test1.begin();
		std::cout << *it_const << std::endl;
		it_const++;
		std::cout << *it_const << std::endl;
	}
	{
		vector<int> my_vector;
		std::cout << my_vector.size() << " " << my_vector.capacity() << std::endl;
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		std::cout << my_vector.size() << " " << my_vector.capacity() << std::endl;
		vector<int> test1;
		test1.push_back(122);
		test1.push_back(232);
		test1.push_back(252);
		test1.push_back(229);
		test1.push_back(228);
		test1.push_back(32);
		test1.push_back(92);
		test1.push_back(82);
		test1.push_back(72);
		test1.push_back(2);
		test1.push_back(23);
		test1.push_back(25);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		std::cout << *my_vector.begin();
		std::cout << "valeur fin " << *(test1.end() - 1) << std::endl;
		std::cout << "valeur debut " << *(test1.begin()) << std::endl;
		test1.insert(test1.begin() + 3, my_vector.begin(), my_vector.begin() + 13);
		for (int i = 0; i < static_cast<int>(test1.size()); i++)
			std::cout << "elem [" << i << "] : " << test1[i] << std::endl;
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
	}
}