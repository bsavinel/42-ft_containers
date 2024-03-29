/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:20:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/10 20:24:17 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTEUR_HPP
# define TESTEUR_HPP

# include <string>

void			map_test();
void			set_test();
void			stack_test();
void			vector_test();
void			enable_if_test();
void			equal_test();
void			is_integral_test();
void			lexi_comp_test();
void			pair_test();
void			print_time(std::string cont, long long int start);
long long int	give_utime(void);

#endif