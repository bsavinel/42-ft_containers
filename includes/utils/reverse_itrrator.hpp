/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_itrrator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/17 10:50:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITRRATOR_HPP
# define REVERSE_ITRRATOR_HPP

#include "iterators_traits.hpp"

namespace ft
{
	template <class Iterator> 
	class reverse_iterator: public iterators_traits<Iterator>
	{
		reverse_iterator(): current()
		{
		}

		explicit reverse_iterator (iterator_type it): current(it)
		{
		}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it): current(rev_it.current)
		{
		}

		iterator_type base() const
		{
			return current;
		}

		reference operator*() const
		{
			Iterator tmp = *current
			return *--tmp;
		}

		reverse_iterator operator+ (difference_type n) const
		{
			return reverse_iterator(current - n);
		}

		reverse_iterator& operator++()
		{
			--current;
			return *this;			
		}

		reverse_iterator  operator++(int)
		{
			reverse_iterator _tmp = *this;
			--current;
			return tmp;
		}
		
		reverse_iterator& operator+= (difference_type n)
		{
			current -= n;
			return *this;
		}
		
		reverse_iterator operator- (difference_type n) const
		{
			return reverse_iterator(current + n);
		}

		reverse_iterator& operator--()
		{
			++current;
			return *this;	
		}

		reverse_iterator  operator--(int)
		{
			reverse_iterator _tmp = *this;
			++current;
			return tmp;
		}

		reverse_iterator& operator-= (difference_type n)
		{
			current += n;
			return *this;
		}
		
		pointer operator->() const
		{
			return &(operator*());
		
		}
		reference operator[] (difference_type n) const
		{
			
		}

		private:

			_Iterator current;
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

	template <class Iterator> reverse_iterator<Iterator>
	inline operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return reverse_iterator(it.base() - n);
	}

	template< class Iterator >
	inline typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
	{
		return (lhs.base() - rhs.base())
	}
}

#endif