/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/18 13:10:35 by bsavinel         ###   ########.fr       */
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
		public :
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
			reverse_iterator (const reverse_iterator<Iter>& rev_it): _current(rev_it.base())
			{
			}

			iterator_type base() const
			{
				return _current;
			}

			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other )
			{
				this->_current = other.base();
				return *this;
			}

			reference operator*() const
			{
				return * (_current - 1);
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
				return *(_current -1 - n);
			}

		private:

			Iterator _current;
	};

	template <class Iterator1, class Iterator2>
	inline bool operator== (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	
	template <class Iterator1, class Iterator2>
	inline bool operator!= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	
	template <class Iterator1, class Iterator2>
	inline bool operator<  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	
	template <class Iterator1, class Iterator2>
	inline bool operator<= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class Iterator1, class Iterator2>
	inline bool operator>  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return rhs < lhs;
	}
	
	template <class Iterator1, class Iterator2>
	inline bool operator>= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Iterator>
	inline reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return reverse_iterator<Iterator>(it.base() - n);
	}

	template< class Iterator1, class Iterator2>
	inline typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{
		return (rhs.base() - lhs.base());
	}
}

#endif