/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:35 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/03 20:37:35 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "pair.hpp"
#include "make_pair.hpp"
#include "RBT.hpp"
#include "RBT_node.hpp"
#include <memory>
#include <functional>
#include "reverse_iterator.hpp"
#include "iterator_map.hpp"
#include <iostream>
#include "lexicographical_compare.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T > > >
	class map
	{
		public:
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef	typename ft::pair<const key_type, mapped_type>	value_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			typedef	ft::Iterator_map<Key, T, Alloc>					iterator;
			typedef	ft::constIterator_map<Key, T, Alloc>			const_iterator;
			typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;

		private:
			typedef	ft::RBT_node<value_type, allocator_type>	node;

		public:
			class value_compare
			{
				friend class map;
				
				public:
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
					typedef	bool		result_type;

					bool operator()(first_argument_type a, second_argument_type b) const
					{
						return comp(a.first, b.first);
					}
					
				protected:
					value_compare(Compare cmp)
					{
						comp = cmp;
					}
					
					Compare	comp;
			};

		//! ------------------------- Constructor -------------------------

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				this->_comp = comp;
				this->_alloc = alloc;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				for (;first != last; first++)
					_tree.insert_value(*first);
				this->_comp = comp;
				this->_alloc = alloc;
			}
		
			map (const map& rhs)
			{
				*this = rhs;
			}
		
			map& operator= (const map& rhs)
			{
				if (this != &rhs)
				{
					this->_alloc = rhs._alloc;
					this->_comp = rhs._comp;
					this->erase(begin(), end());
					this->insert(rhs.begin(), rhs.end());
				}
				return *this;
			}

		//! ------------------------- Destructor -------------------------

			~map()
			{
			}

		//! ------------------------- Iterators -------------------------

			iterator begin()
			{
				return iterator(_tree.giveSentinel(), _tree.minimum(), 0);
			}

			const_iterator begin() const
			{
				return const_iterator(_tree.giveSentinel(), _tree.minimum(), 0);
			}

			iterator end()
			{
				return iterator(_tree.giveSentinel(), _tree.giveSentinel(), 1);
			}

			const_iterator end() const
			{
				return const_iterator(_tree.giveSentinel(), _tree.giveSentinel(), 1);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

		//! ------------------------- Capacity -------------------------

			bool empty() const
			{
				return _tree.empty();
			}

			size_type size() const
			{
				return _tree.size();
			}
		
			size_type max_size() const
			{
				std::allocator<node> tmp;
				return(tmp.max_size());
			}

		//! ------------------------- Element access  -------------------------

			mapped_type& operator[] (const key_type& k)
			{
				node *tmp;

				tmp = _tree.find_key(k);
				if (tmp)
					return tmp->_value.second;
				_tree.insert_value(value_type(k, mapped_type()));
				return _tree.find_key(k)->_value.second;
			}

		//! ------------------------- Modifiers -------------------------

			ft::pair<iterator,bool> insert(const value_type& val)
			{
				ft::pair<node *, bool> ret;
				
				ret = _tree.insert_value(val);
				return ft::make_pair(iterator(_tree.giveSentinel(), ret.first, 0), ret.second);
			}

			iterator insert(iterator position, const value_type& val)
			{
				ft::pair<node *, bool> ret;
				
				(void) position;
				ret = _tree.insert_value(val);
				if (ret.second == false)
					return this->end();
				return iterator(_tree.giveSentinel(), ret.first ,0);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (;first != last; first++)
					_tree.insert_value(*first);
			}

			void erase(iterator position)
			{
				_tree.delete_value(position->first);
			}

			size_type erase(const key_type& k)
			{
				if(_tree.delete_value(k))
					return 1;
				return 0;
			}

			void erase (iterator first, iterator last)
			{
				iterator tmp;

				for (; first != last;)
				{
					tmp = first;
					first++;
					_tree.delete_value(tmp->first);
				}
			}

			void swap (map& x)
			{
				RBT<value_type, Compare, Alloc>	tmpTree;
				key_compare						tmpComp;
				allocator_type					tmpAlloc;

				tmpTree = this->_tree;
				tmpComp = this->_comp;
				tmpAlloc = this->_alloc;

				this->_tree = x._tree;
				this->_comp = x._comp;
				this->_alloc = x._alloc;

				_tree.swap(x._tree);
			}
		
			void clear()
			{
				this->erase(this->begin(), this->end());
			}

		//! ------------------------- Observers -------------------------

			key_compare key_comp() const
			{
				return _comp;
			}

			value_compare value_comp() const
			{
				return value_compare(_comp);
			}

		//! ------------------------- Operations -------------------------

			iterator find (const key_type& k)
			{
				node *tmp;

				tmp = _tree.find_key(k);
				if (tmp)
					return iterator(_tree.giveSentinel(), tmp, 0);
				return end();
			}
		
			const_iterator find (const key_type& k) const
			{
				node *tmp;

				tmp = _tree.find_key(k);
				if (tmp)
					return const_iterator(_tree.giveSentinel(), tmp, 0);
				return end();
			}

			size_type count (const key_type& k) const
			{
				if (_tree.find_key(k) == NULL)
					return 0;
				return 1;
			}

			iterator lower_bound (const key_type& k)
			{
				iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (!_comp(it->first, k)) //?true si a < b
						return it;
				}
				return end();
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (!_comp(it->first, k)) //?true si a < b
						return it;
				}
				return end();
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (_comp(k, it->first)) //?true si a < b
						return it;
				}
				return end();
			}
		
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (_comp(k, it->first)) //?true si a < b
						return it;
				}
				return end();
			}

			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			pair<iterator,iterator>		equal_range (const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

		//! ------------------------- Allocator -------------------------

			allocator_type get_allocator() const
			{
				return _alloc;
			}

		private:
			RBT<value_type, Compare, Alloc>	_tree;
			key_compare						_comp;
			allocator_type					_alloc;
	};
	
	template< class Key, class T, class Compare, class Alloc >
	inline bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs) && !(lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	inline bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	inline bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class Key, class T, class Compare, class Alloc >
	inline bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	inline bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template< class Key, class T, class Compare, class Alloc >
	inline bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif