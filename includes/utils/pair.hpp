/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:52 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/18 11:48:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair()
		{
		}
		
		pair(const first_type a, const second_type b): first(a), second(b)
		{
		}
		
		template<class U, class V>
		pair (const pair<U,V>& pr): first(pr.first), second(pr.second)
		{
		}
		
		~pair()
		{
		}

		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	inline bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	inline bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	inline bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first || (rhs.first == lhs.first && lhs.second<rhs.second);
	}
	//*		lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	//*	=>	lhs.first < rhs.first || (!(lhs.first > rhs.first) && lhs.second < rhs.second);
	//* =>	lhs.first < rhs.first || (lhs.first <= rhs.first && lhs.second < rhs.second);
	//*	=>	lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);

	template <class T1, class T2>
	inline bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	inline bool operator>  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	inline bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif