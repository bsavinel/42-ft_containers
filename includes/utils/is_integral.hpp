/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/14 16:17:47 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include <type_traits>

namespace ft
{	
	template <class T>
	struct is_integral: public false_type
	{
	};

	struct is_integral<bool>: public true_type
	{
	};
	
	struct is_integral<char>: public true_type
	{
	};
	
	struct is_integral<char16_t>: public true_type
	{
	};
	
	struct is_integral<char32_t>: public true_type
	{
	};
	
	struct is_integral<wchar_t>: public true_type
	{
	};
	
	struct is_integral<signed char>: public true_type
	{
	};
	
	struct is_integral<short int>: public true_type
	{
	};
	
	struct is_integral<int>: public true_type
	{
	};
	
	struct is_integral<long int>: public true_type
	{
	};
	
	struct is_integral<long long int>: public true_type
	{
	};
	
	struct is_integral<unsigned char>: public true_type
	{
	};
	
	struct is_integral<unsigned short int>: public true_type
	{
	};
	
	struct is_integral<unsigned int>: public true_type
	{
	};
	
	struct is_integral<unsigned long int>: public true_type
	{
	};
	
	struct is_integral<unsigned long long int>: public true_type
	{
	};
}

#endif
