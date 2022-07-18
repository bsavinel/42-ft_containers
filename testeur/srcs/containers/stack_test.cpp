/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:04 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 14:47:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <stack>
#else
//# include "stack.hpp"
#endif


#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	stack_test()
{
	std::cout << "Test stack:" << std::endl << std::endl;
}