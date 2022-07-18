/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:53 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 15:00:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <type_traits>
#else
//# include "is_integral.hpp"
#endif

#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	is_integral_test()
{
	std::cout << "Test is_integral:" << std::endl << std::endl;
}
