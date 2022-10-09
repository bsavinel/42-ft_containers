/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:27 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/09 16:30:47 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
		
			typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;

			explicit stack (const container_type& ctnr = container_type())
			{
				c = cntr;
			}

			~stack()
			{
			}

			stack& operator=( const stack& other )
			{
				c = other.c;
				return *this;
			}

			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			value_type& top()
			{
				return c.back();
			}

			const value_type& top() const
			{
				return c.back();
			}

			void push (const value_type& val)
			{
				c.push_back(val);
			}

			void pop()
			{
				c.pop_back();
			}
		
			container_type c;
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c == rhs.c;
	}
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c != rhs.c;
	}
	
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c < rhs.c;
	}
	
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c <= rhs.c;
	}
	
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c > rhs.c;
	}
	
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c >= rhs.c;
	}
}

#endif