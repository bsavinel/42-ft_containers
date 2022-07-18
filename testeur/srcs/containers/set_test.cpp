/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:01 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 14:47:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <set>
#else
//# include "set.hpp"
#endif

#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	set_test()
{
	std::cout << "Test set:" << std::endl << std::endl;
}