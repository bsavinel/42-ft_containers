/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_comp_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:56 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 11:39:06 by bsavinel         ###   ########.fr       */
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

//#include "lexicographical_compare.hpp"
#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	lexi_comp_test()
{
	std::cout << "Test lexicographical_compare:" << std::endl << std::endl;
}
