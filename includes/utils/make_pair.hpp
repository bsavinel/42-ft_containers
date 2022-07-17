/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/15 14:04:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

#include <pair.hpp>

namespace ft
{
	template <class T1,class T2>
	typename ft::pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return (ft::pair<T1,T2>(x,y));
	}
}

#endif