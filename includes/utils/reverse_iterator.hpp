/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/19 12:22:41 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft
{
	template <class Iterator> 
	class reverse_iterator
	{
		typedef	Iterator												iterator_type;
		typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename iterator_traits<Iterator>::value_type			value_type;
		typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename iterator_traits<Iterator>::pointer				pointer;
		typedef	typename iterator_traits<Iterator>::reference			reference;
		
		reverse_iterator()
		{
		}

		explicit reverse_iterator (iterator_type it): _current(it)
		{
		}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it): _current(rev_it.current)
		{
		}

		iterator_type base() const
		{
			return _current;
		}

		reference operator*() const
		{
			Iterator tmp = *_current;
			return *--tmp;
		}

		reverse_iterator operator+ (difference_type n) const
		{
			return reverse_iterator(_current - n);
		}

		reverse_iterator& operator++()
		{
			--_current;
			return *this;			
		}

		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp = *this;
			--_current;
			return tmp;
		}
		
		reverse_iterator& operator+= (difference_type n)
		{
			_current -= n;
			return *this;
		}
		
		reverse_iterator operator- (difference_type n) const
		{
			return reverse_iterator(_current + n);
		}

		reverse_iterator& operator--()
		{
			++_current;
			return *this;	
		}

		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp = *this;
			++_current;
			return tmp;
		}

		reverse_iterator& operator-= (difference_type n)
		{
			_current += n;
			return *this;
		}
		
		pointer operator->() const
		{
			return &(operator*());
		
		}
		reference operator[] (difference_type n) const
		{
			return _current + n;
		}

		private:

			Iterator _current;
	};

	template <class Iterator>
	inline bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	
	template <class Iterator>
	inline bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	
	template <class Iterator>
	inline bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	
	template <class Iterator>
	inline bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class Iterator>
	inline bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs < lhs;
	}
	
	template <class Iterator>
	inline bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Iterator>
	inline reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return reverse_iterator<Iterator>(it.base() - n);
	}

	template< class Iterator >
	inline typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
	{
		return (lhs.base() - rhs.base());
	}
}

#endif