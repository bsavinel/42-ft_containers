/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:48 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 15:00:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <algorithm>
#else
//# include "equal.hpp"
#endif

#include "testeur.hpp"
#include <iostream>

using namespace NAMESPACE_USE;

void	equal_test()
{
	std::cout << "Test equal:" << std::endl << std::endl;
}