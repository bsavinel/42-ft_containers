/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:08 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/14 16:11:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

//? https://eli.thegreenplace.net/2014/sfinae-and-enable_if

namespace ft
{
	template<bool Cond, class T = void>
	struct enable_if 
	{
	};
	
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif