/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:35 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/17 21:36:31 by bsavinel         ###   ########.fr       */
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
			typedef	ft::Iterator_map<Key, T, Compare, Alloc>		iterator;
			typedef	ft::constIterator_map<Key, T, Compare, Alloc>	const_iterator;
			typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;
		
		class value_compare
		{
			public:
				typedef	value_type	first_argument_type;
				typedef	value_type	second_argument_type;
				typedef	bool		result_type;
				
				value_compare()
				{
					comp = Compare();
				}

				bool operator()(first_argument_type a, second_argument_type b)
				{
					if (!comp(a, b) && !comp(b, a))
						return true;
					return false;
				}
				
			private:
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
					this->_tree = rhs._tree;
				}
			}
		
		//! ------------------------- Destructor -------------------------
		
			~map()
			{
			}

		//! ------------------------- Iterators -------------------------

			iterator begin()
			{
				return iterator(&_tree, _tree.giveSentinel, _tree.minimum(), 0);
			}

			const_iterator begin() const
			{
				return const_iterator(&_tree, _tree.giveSentinel, _tree.minimum(), 0);
			}

			iterator end()
			{
				return iterator(&_tree, _tree.giveSentinel, _tree.giveSentinel, 1);
			}

			const_iterator end() const
			{
				return const_iterator(&_tree, _tree.giveSentinel, _tree.giveSentinel, 1);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(iterator(&_tree, _tree.giveSentinel, _tree.minimum(), 0));
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(const_iterator(&_tree, _tree.giveSentinel, _tree.minimum(), 0));
			}

			reverse_iterator rend()
			{
				return reverse_iterator(iterator(&_tree, _tree.giveSentinel, _tree.giveSentinel, 1));
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(const_iterator(&_tree, _tree.giveSentinel, _tree.giveSentinel, 1));
			}
		
		//! ------------------------- Capacity -------------------------

			bool empty() const
			{
				return _tree.empty();
			}

			size_type size() const
			{
				
			}
		
			size_type max_size() const
			{
				std::allocator<_tree::node> tmp;
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
				pair<node *, bool> ret;
				
				ret = _tree.insert_value(val);
				return ft::make_pair(iterator(_tree, _tree.giveSentinel(), ret.fisrt, 0), ret.second);
			}

			iterator insert(iterator position, const value_type& val)
			{
				pair<node *, bool> ret;
				
				(void) position;
				ret = _tree.insert_value(val);
				if (ret.second == false)
					return this->end();
				return iterator(_tree, _tree.giveSentinel(), ret.fisrt ,0);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (;first != last; first++)
					_tree.insert_value(*first);
			}

			void erase(iterator position)
			{
				_tree.delete_value(first->first);
			}

			size_type erase(const key_type& k)
			{
				if(_tree.delete_value(k));
					return 1;
				return 0;
			}

			void erase (iterator first, iterator last)
			{
				for (;first != last; first++)
					_tree.delete_value(first->first);
			}

			void swap (map& x)
			{
				RBT<value_type, Compare, Alloc>	tmpTree;
				key_compare						tmpComp;
				allocator_type					tmpAlloc;

				tmpTree = this->_tree;
				tmpComp = this->_comp;
				tmpAlloc = this->_alloc;

				this->_tree = rhs._tree;
				this->_comp = rhs._comp;
				this->_alloc = rhs._alloc;

				rhs._tree = tmpTree;
				rhs._comp = tmpComp;
				rhs._alloc = tmpAlloc;	
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
				return value_compare();
			}

		//! ------------------------- Operations -------------------------

			iterator find (const key_type& k)
			{
				node *tmp;

				tmp = _tree.find_key(k);
				if (tmp)
					return iterator(&_tree, tmp, tree.giveSentinel(), 0);
				return end();
			}
		
			const_iterator find (const key_type& k) const
			{
				node *tmp;

				tmp = _tree.find_key(k);
				if (tmp)
					return const_iterator(&_tree, tmp, tree.giveSentinel(), 0);
				return end();
			}

			size_type count (const key_type& k) const
			{
				if (_tree.find_key(k) == tree.giveSentinel())
					return 0;
				return 1;
			}

			iterator lower_bound (const key_type& k)
			{
				iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (_comp(it->first, k) || !_comp(k, it->first)) //?true si a < b
						return it;
				}
				return end();
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (_comp(it->first, k) || !_comp(k, it->first)) //?true si a < b
						return it;
				}
				return end();
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (_comp(k, it->first) || !_comp(it->first, k)) //?true si a < b
						return it;
				}
				return end();
			}
		
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it;
				
				for (it = this->begin(); it != this->end(); it++)
				{
					if (_comp(k, it->first) || !_comp(it->first, k)) //?true si a < b
						return it;
				}
				return end();
			}

			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
			{
				const_iterator it;

				it = this->find(k)
				if (it != this->end())
					return ft::make_pair(it, it);
				it = upper_bound(k);
				return ft::make_pair(it, it);
			}

			pair<iterator,iterator>		equal_range (const key_type& k)
			{
				iterator it;

				it = this->find(k)
				if (it != this->end())
					return ft::make_pair(it, it);
				it = upper_bound(k);
				return ft::make_pair(it, it);
			}
			
		//! ------------------------- Allocator -------------------------

			allocator_type get_allocator() const
			{
				return _alloc;
			}

		private:
			typedef	ft::RBT_node<value_type, allocator_type>	node;
			RBT<value_type, Alloc>			_tree;
			key_compare						_comp;
			allocator_type					_alloc;
	};
}

#endif