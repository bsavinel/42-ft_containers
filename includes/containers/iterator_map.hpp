/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:43:42 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/18 21:38:14 by bsavinel         ###   ########.fr       */
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
	template <class Key, class T, class Compare, class Alloc>
	class constIterator_map;
	//! --------------------------------------- iterator map ----------------------------------
	
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
	class Iterator_map
	{
		public:
			typedef	ptrdiff_t						difference_type;
			typedef	typename ft::pair<const Key, T>	value_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;
			typedef	random_access_iterator_tag		iterator_category;

		private:
			typedef	typename ft::Iterator_map<Key, T, Compare, Alloc>		iterator_type;
			typedef	typename ft::constIterator_map<Key, T, Compare, Alloc>	constIterator_type;
			typedef	typename ft::RBT_node<value_type, Alloc>				node;
			typedef	typename ft::RBT<value_type, Compare, Alloc>			RBTtree;
		
		public:
			Iterator_map()
			{
			}
				
			Iterator_map(RBTtree *tree, node *sentinel, node *start, int sensDepassement): _tree(tree), _sentinel(sentinel), _current(start), _sensDepassement(sensDepassement)
			{
			}

			Iterator_map(const iterator_type& rhs)
			{
				*this = rhs;
			}

			~Iterator_map()
			{
			}
			
			iterator_type& operator=(const iterator_type& rhs)
			{
				this->_current = rhs._current;
				this->_sentinel = rhs._sentinel;
				this->_tree = rhs._tree;
				this->_sensDepassement = _sensDepassement;
				return *this;
			}

			reference operator*() const
			{
				return _current->_value;
			}

			iterator_type& operator++()
			{
				if (_current == _sentinel)
				{
					if (_sensDepassement == -1)
						_current = _tree->minimum();
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
				if (_current == _sentinel)
				{
					if (_sensDepassement == 1)
						_current = _tree->maximum();
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
				return *this;
			}

			iterator_type  operator--(int)
			{
				iterator_type tmp = *this;
				--(*this);
				return tmp;
			}
		
			pointer operator->() const
			{
				return &(operator*());
			}
			
			friend bool operator== (const iterator_type& lhs, const iterator_type& rhs)
			{
				if (lhs._current == rhs._current && lhs._sentinel == rhs._sentinel && lhs._tree == rhs._tree)
				{
					if (lhs._current == lhs._sentinel && lhs._sensDepassement != rhs._sensDepassement)
						return false;
					return true;
				}
				return false;
			}
			
			friend bool operator== (const iterator_type& lhs, const constIterator_type& rhs)
			{
				if (lhs._current == rhs._current && lhs._sentinel == rhs._sentinel && lhs._tree == rhs._tree)
				{
					if (lhs._current == lhs._sentinel && lhs._sensDepassement != rhs._sensDepassement)
						return false;
					return true;
				}
				return false;
			}

			friend bool operator!= (const iterator_type& lhs, const iterator_type& rhs)
			{
				return !(lhs == rhs);
			}

			friend bool operator!= (const iterator_type& lhs, const constIterator_type& rhs)
			{
				return !(lhs == rhs);
			}

		private:
			RBTtree	*_tree;
			node	*_sentinel;
			node	*_current;
			int		_sensDepassement;
			
	};

	//! --------------------------------- Const iterator map -------------------------------

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
	class constIterator_map
	{
		public:
			typedef	ptrdiff_t								difference_type;
			typedef	const typename ft::pair<const Key, T>	value_type;
			typedef	const value_type*						pointer;
			typedef	const value_type&						reference;
			typedef	random_access_iterator_tag				iterator_category;
		
		private:
			typedef	typename ft::Iterator_map<Key, T, Compare, Alloc>				iterator_type;
			typedef	typename ft::constIterator_map<Key, T, Compare, Alloc>			constIterator_type;
			typedef	const typename ft::RBT_node<ft::pair<const Key, T>, Alloc>		node;
			typedef	const typename ft::RBT<ft::pair<const Key, T>, Compare, Alloc>	RBTtree;
		
		public:
			constIterator_map()
			{
			}
				
			constIterator_map(RBTtree *tree, node *sentinel, node *start, int sensDepassement): _tree(tree), _sentinel(sentinel), _current(start), _sensDepassement(sensDepassement)
			{
			}

            constIterator_map(const constIterator_type& rhs)
            {
				*this = rhs;
			}

			~constIterator_map()
			{
			}
			
			constIterator_type& operator=(const constIterator_type& rhs)
			{
				this->_current = rhs._current;
				this->_sentinel = rhs._sentinel;
				this->_tree = rhs._tree;
				this->_sensDepassement = _sensDepassement;
				return *this;
			}

			reference operator*() const
			{
				return _current->_value;
			}

			constIterator_type& operator++()
			{
				if (_current == _sentinel)
				{
					if (_sensDepassement == -1)
						_current = _tree->minimum();
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
				if (_current == _sentinel)
				{
					if (_sensDepassement == 1)
						_current = _tree->maximum();
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
				return *this;
			}

			constIterator_type  operator--(int)
			{
				constIterator_type tmp = *this;
				--(*this);
				return tmp;
			}
		
			pointer operator->() const
			{
				return &(operator*());
			}
			
			friend bool operator== (const constIterator_type& lhs, const constIterator_type& rhs)
			{
				if (lhs._current == rhs._current && lhs._sentinel == rhs._sentinel && lhs._tree == rhs._tree)
				{
					if (lhs._current == lhs._sentinel && lhs._sensDepassement != rhs._sensDepassement)
						return false;
					return true;
				}
				return false;
			}

			friend bool operator== (const constIterator_type& lhs, const iterator_type& rhs)
			{
				if (lhs._current == rhs._current && lhs._sentinel == rhs._sentinel && lhs._tree == rhs._tree)
				{
					if (lhs._current == lhs._sentinel && lhs._sensDepassement != rhs._sensDepassement)
						return false;
					return true;
				}
				return false;
			}
			
			friend bool operator!= (const constIterator_type& lhs, const constIterator_type& rhs)
			{
				return !(lhs == rhs);
			}
			
			friend bool operator!= (const constIterator_type& lhs, const iterator_type& rhs)
			{
				return !(lhs == rhs);
			}

		private:
			RBTtree	*_tree;
			node	*_sentinel;
			node	*_current;
			int		_sensDepassement;
	};
}

#endif