/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:35 by bsavinel          #+#    #+#             */
/*   Updated: 2022/09/11 17:30:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "pair.hpp"
#include "RBT.hpp"
#include <memory>
#include <functional>
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T > > >
	class map
	{
		public:
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef	typename ft::pair<const key_type,mapped_type>	value_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			// typedef	iterator_map<value_type>						iterator;
			// typedef	const iterator									const_iterator;
			// typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;
		
		// //! ------------------------- Constructor -------------------------
		
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

			/*void	print()
			{
				tree.print();
			}*/
		
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
		
		// //! ------------------------- Destructor -------------------------
		
			~map()
			{
			}

		// //! ------------------------- Iterators -------------------------

			// iterator begin()
			// {

			// }

			// const_iterator begin() const
			// {

			// }

			// iterator end()
			// {

			// }

			// const_iterator end() const
			// {

			// }

			// reverse_iterator rbegin()
			// {

			// }
			
			// const_reverse_iterator rbegin() const
			// {

			// }

			// reverse_iterator rend()
			// {

			// }

			// const_reverse_iterator rend() const
			// {

			// }
		
		// //! ------------------------- Capacity -------------------------

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
				
				tmp.max_size();
			}
		
		// //! ------------------------- Element access  -------------------------

			// mapped_type& operator[] (const key_type& k)
			// {

			// }
		
		// //! ------------------------- Modifiers -------------------------

			/*pair<iterator,bool>*/void insert(const value_type& val)
			{
				_tree.insert_value(val);
			}

			// iterator insert(iterator position, const value_type& val)
			// {

			// }

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (;first != last; first++)
					_tree.insert_value(*first);
			}

			void erase(iterator position)
			{
				_tree.delete_value(first.base()->_value.first);
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
					_tree.delete_value(first.base()->_value.first);
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
		
			// void clear()
			// {
			//		this->erase(this->begin(), this->end());
			// }

		// //! ------------------------- Observers -------------------------

			key_compare key_comp() const
			{
				return _comp;
			}

			// value_compare value_comp() const
			// {
				
			// }

		// 	//! ------------------------- Operations -------------------------

			// iterator find (const key_type& k)
			// {

			// }
		
			// const_iterator find (const key_type& k) const
			// {
			
			// }

			// size_type count (const key_type& k) const
			// {
			
			// }

			// iterator lower_bound (const key_type& k)
			// {

			// }

			// const_iterator lower_bound (const key_type& k) const
			// {
	
			// }

			// iterator upper_bound (const key_type& k)
			// {

			// }
		
			// const_iterator upper_bound (const key_type& k) const
			// {

			// }

			// pair<iterator,iterator> equal_range (const key_type& k)
			// {
			
			// }

		// //! ------------------------- Allocator -------------------------

			allocator_type get_allocator() const
			{
				return _alloc;
			}

		private:
			RBT<value_type, Compare, Alloc>	_tree;
			key_compare						_comp;
			allocator_type					_alloc;
	};
}

#endif