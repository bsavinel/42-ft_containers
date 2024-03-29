/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_set.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:43:42 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/22 14:14:41 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_SET_HPP
# define ITERATOR_SET_HPP

#include "iterators_traits.hpp"
#include "RBT_node.hpp"
#include "RBT.hpp"

namespace ft
{
	template <class T, class Alloc>
		class Iterator_set;

	template <class T, class Alloc = std::allocator<T> >
	class IteratorBase_set
	{
		public:
			typedef	ptrdiff_t							difference_type;
			typedef	T									value_type;
			typedef	value_type*							pointer;
			typedef	value_type&							reference;
			typedef	std::random_access_iterator_tag		iterator_category;

		private:
			typedef	typename ft::IteratorBase_set<T, Alloc>		iteratorBase_type;
			typedef	typename ft::RBT_node<value_type, Alloc>	node;

		public:
            IteratorBase_set()
			{
			}

			IteratorBase_set(node *sentinel, node *start, int sensDepassement)
			{
				_sentinel = sentinel;
				_current = start;
				_sensDepassement = sensDepassement;
			}

			IteratorBase_set(const iteratorBase_type& rhs)
			{
				*this = rhs;
			}

			~IteratorBase_set()
			{
			}
			
			iteratorBase_type& operator=(const iteratorBase_type& rhs)
			{
				this->_current = rhs._current;
				this->_sentinel = rhs._sentinel;
				this->_sensDepassement = rhs._sensDepassement;
				return *this;
			}

			iteratorBase_type& operator++()
			{
				if (_current == _sentinel)
				{
					if (_sensDepassement == -1 || _sensDepassement == 0)
						_current = _current->_left;
					return *this;
				}
				_sensDepassement = 1;
				if (_current->_right != _sentinel)
				{
					_current = _current->_right;
					while (_current->_left != _sentinel)
						_current = _current->_left;
					return *this;
				}
				while (_current->_parent != _sentinel && _current->_parent->_right == _current)
					_current = _current->_parent;
				_current = _current->_parent;
				return *this;
			}

			iteratorBase_type  operator++(int)
			{
				iteratorBase_type tmp = *this;
				++(*this);
				return tmp;
			}
		
			iteratorBase_type& operator--()
			{
				if (_current == _sentinel)
				{
					if (_sensDepassement == 1 || _sensDepassement == 0)
						_current = _current->_right;
					return *this;
				}
				_sensDepassement = -1;
				if (_current->_left != _sentinel)
				{
					_current = _current->_left;
					while (_current->_right != _sentinel)
						_current = _current->_right;
					return *this;
				}
				while (_current->_parent != _sentinel && _current->_parent->_left == _current)
					_current = _current->_parent;
				_current = _current->_parent;
				return *this;
			}

			iteratorBase_type  operator--(int)
			{
				iteratorBase_type tmp = *this;
				--(*this);
				return tmp;
			}
			
			reference operator*() const
			{
				return _current->_value;
			}
		
			pointer operator->() const
			{
				return &(operator*());
			}

			template<class T2, class Alloc2>
			bool operator== (const IteratorBase_set<T2, Alloc2>& rhs) const
			{
				if (_current == rhs._current && _sentinel == rhs._sentinel)
				{
					if (_current == _sentinel && _sensDepassement == 0 && rhs._sensDepassement == 0 && _sensDepassement != rhs._sensDepassement)
						return false;
					return true;
				}
				return false;
			}

			template<class T2, class Alloc2>
			bool operator!= (const IteratorBase_set<T2, Alloc2>& rhs) const
			{
				return !(*this == rhs);
			}
		
		private:
			node	*_sentinel;
			node	*_current;
			int		_sensDepassement;
	};

	//! --------------------------------------- iterator set ----------------------------------
	
	template <class T, class Alloc = std::allocator<T> >
	class Iterator_set
	{
		public:
			typedef	ptrdiff_t							difference_type;
			typedef	const T								value_type;
			typedef	value_type*							pointer;
			typedef	value_type&							reference;
			typedef	std::random_access_iterator_tag		iterator_category;

		private:
			typedef	typename ft::IteratorBase_set<T, Alloc>		iteratorBase_type;
			typedef	typename ft::Iterator_set<T, Alloc>			iterator_type;
			typedef	typename ft::RBT_node<T, Alloc>	node;
		
		public:
			Iterator_set()
			{
			}
				
			Iterator_set(node *sentinel, node *start, int sensDepassement)
			{
				_current = iteratorBase_type(sentinel, start, sensDepassement);
			}

			Iterator_set(const iterator_type& rhs)
			{
				*this = rhs;
			}

			~Iterator_set()
			{
			}
			
			const iteratorBase_type &base() const
			{
				return _current;
			}
			
			iterator_type& operator=(const iterator_type& rhs)
			{
				_current = rhs.base();
                return *this;
			}

			iterator_type& operator++()
			{
				++_current;
				return *this;
			}

			iterator_type  operator++(int)
			{
				iterator_type tmp = *this;

				++(*this);
				return tmp;
			}
		
			iterator_type& operator--()
			{
				--_current;
				return *this;
			}

			iterator_type  operator--(int)
			{
				iterator_type tmp = *this;
				--(*this);
				return tmp;
			}

			reference operator*() const
			{
				return  *_current;
			}

			pointer operator->() const
			{
				return &(operator*());
			}

		private:
			iteratorBase_type _current;
	};
		
	template<class T1, class Alloc1, class T2, class Alloc2>
	inline bool operator== (const Iterator_set<T1, Alloc1>& lhs, const Iterator_set<T2, Alloc2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class T1, class Alloc1, class T2, class Alloc2>
	inline bool operator!= (const Iterator_set<T1, Alloc1>& lhs, const Iterator_set<T2, Alloc2>& rhs)
	{
		return lhs.base() != rhs.base();
	}

}

#endif