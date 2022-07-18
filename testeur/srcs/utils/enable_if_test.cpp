/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:03:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 11:39:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE

#else

#endif

//#include "enable_if.hpp"
#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	enable_if_test()
{
	std::cout << "Test enable_if:" << std::endl << std::endl;
}