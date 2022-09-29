/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:43:42 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/29 19:42:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

#include "iterators_traits.hpp"
#include "pair.hpp"
#include "RBT_node.hpp"
#include "RBT.hpp"

namespace ft
{
	template <class Key, class T, class Alloc>
		class constIterator_map;

	template <class Key, class T, class Alloc>
		class Iterator_map;

	template <class Key, class T, class Alloc = std::allocator<ft::pair<const Key,T > > >
	class IteratorBase_map
	{
		public:
			typedef	ptrdiff_t						difference_type;
			typedef	typename ft::pair<const Key, T>	value_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;
			typedef	random_access_iterator_tag		iterator_category;

		private:
			typedef	typename ft::IteratorBase_map<Key, T, Alloc>	iteratorBase_type;
			typedef	typename ft::RBT_node<value_type, Alloc>		node;

		public:
            IteratorBase_map()
			{
			}

			IteratorBase_map(node *sentinel, node *start, int sensDepassement)
			{
				_sentinel = sentinel;
				_current = start;
				_sensDepassement = sensDepassement;
			}

			IteratorBase_map(const iteratorBase_type& rhs)
			{
				*this = rhs;
			}

			~IteratorBase_map()
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
					if (_sensDepassement == -1)
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
					if (_sensDepassement == 1)
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

			template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
			friend inline bool operator== (const IteratorBase_map<Key1, T1, Alloc1>& lhs, const IteratorBase_map<Key2, T2, Alloc2>& rhs)
			{
				if (lhs._current == rhs._current && lhs._sentinel == rhs._sentinel)
				{
					if (lhs._current == lhs._sentinel && lhs._sensDepassement != rhs._sensDepassement)
						return false;
					return true;
				}
				return false;
			}

			template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
			friend inline bool operator!= (const IteratorBase_map<Key1, T1, Alloc1>& lhs, const IteratorBase_map<Key2, T2, Alloc2>& rhs)
			{
				return !(lhs == rhs);
			}
		
		private:
			node	*_sentinel;
			node	*_current;
			int		_sensDepassement;
	};

	//! --------------------------------------- iterator map ----------------------------------
	
	template <class Key, class T, class Alloc = std::allocator<ft::pair<const Key,T > > >
	class Iterator_map
	{
		public:
			typedef	ptrdiff_t						difference_type;
			typedef	typename ft::pair<const Key, T>	value_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;
			typedef	random_access_iterator_tag		iterator_category;

		private:
			typedef	typename ft::IteratorBase_map<Key, T, Alloc>	iteratorBase_type;
			typedef	typename ft::Iterator_map<Key, T, Alloc>		iterator_type;
			typedef	typename ft::constIterator_map<Key, T, Alloc>	constIterator_type;
			typedef	typename ft::RBT_node<value_type, Alloc>		node;
		
		public:
			Iterator_map()
			{
			}
				
			Iterator_map(node *sentinel, node *start, int sensDepassement)
			{
				_current = iteratorBase_type(sentinel, start, sensDepassement);
			}

			Iterator_map(const iterator_type& rhs)
			{
				*this = rhs;
			}

			~Iterator_map()
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

			constIterator_type  operator--(int)
			{
				constIterator_type tmp = *this;
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

	//! --------------------------------- Const iterator map -------------------------------

	template <class Key, class T, class Alloc = std::allocator<ft::pair<const Key,T > > >
	class constIterator_map
	{
		public:
			typedef	ptrdiff_t								difference_type;
			typedef	const typename ft::pair<const Key, T>	value_type;
			typedef	const value_type*						pointer;
			typedef	const value_type&						reference;
			typedef	random_access_iterator_tag				iterator_category;
		
		private:
			typedef	typename ft::IteratorBase_map<Key, T, Alloc>			iteratorBase_type;
			typedef	typename ft::Iterator_map<Key, T, Alloc>				iterator_type;
			typedef	typename ft::constIterator_map<Key, T, Alloc>			constIterator_type;
			typedef	typename ft::RBT_node<ft::pair<const Key, T>, Alloc>	node;
		
		public:
			constIterator_map()
			{
			}

			constIterator_map(node *sentinel, node *start, int sensDepassement)
			{
				_current = iteratorBase_type(sentinel, start, sensDepassement);
			}

            constIterator_map(const constIterator_type& rhs)
            {
				*this = rhs;
			}

			constIterator_map(const iterator_type& rhs)
			{
				_current = rhs.base();
			}

			~constIterator_map()
			{
			}

			const iteratorBase_type &base() const
			{
				return _current;
			}
			
			constIterator_type& operator=(const constIterator_type& rhs)
			{
				_current = rhs.base();
				return *this;
			}

			constIterator_type& operator++()
			{
				++_current;
				return *this;
			}

			constIterator_type  operator++(int)
			{
				constIterator_type tmp = *this;

				++(*this);
				return tmp;
			}
		
			constIterator_type& operator--()
			{
				return *_current;
			}

			constIterator_type  operator--(int)
			{
				constIterator_type tmp = *this;
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

			
	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator== (const Iterator_map<Key1, T1, Alloc1>& lhs, const Iterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator== (const Iterator_map<Key1, T1, Alloc1>& lhs, const constIterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	
	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator== (const constIterator_map<Key1, T1, Alloc1>& lhs, const constIterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator== (const constIterator_map<Key1, T1, Alloc1>& lhs, const Iterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator!= (const Iterator_map<Key1, T1, Alloc1>& lhs, const Iterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator!= (const Iterator_map<Key1, T1, Alloc1>& lhs, const constIterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator!= (const constIterator_map<Key1, T1, Alloc1>& lhs, const constIterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() != rhs.base();
	}
			
	template<class Key1, class T1, class Alloc1, class Key2, class T2, class Alloc2>
	inline bool operator!= (const constIterator_map<Key1, T1, Alloc1>& lhs, const Iterator_map<Key2, T2, Alloc2>& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif