/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:15:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/17 19:00:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
#endif

#include "testeur.hpp"

using namespace NAMESPACE_USE;

int main()
{
	map_test();
	set_test();
	stack_test();
	vector_test();
	enable_if_test();
	equal_test();
	is_integral_test();
	lexi_comp_test();
	pair_test();
	return 0;
}
