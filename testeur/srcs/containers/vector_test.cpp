/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:01:19 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/19 16:20:28 by bsavinel         ###   ########.fr       */
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
	}
}