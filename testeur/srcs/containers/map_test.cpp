/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:11:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 14:46:56 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <map>
#else
//# include "map.hpp"
#endif

#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	map_test()
{
	std::cout << "Test map:" << std::endl << std::endl;
}