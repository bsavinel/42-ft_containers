/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:15:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:06:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeur.hpp"
#include <iostream>

int main()
{
	std::cout << "Debut des test" << std::endl;
	map_test();
	set_test();
	stack_test();
	vector_test();
	enable_if_test();
	equal_test();
	is_integral_test();
	lexi_comp_test();
	pair_test();
	std::cout << std::endl << "Fin des test" << std::endl;
	return 0;
}
