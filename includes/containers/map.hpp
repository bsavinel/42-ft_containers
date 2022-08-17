/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:35 by bsavinel          #+#    #+#             */
/*   Updated: 2022/08/17 14:14:52 by bsavinel         ###   ########.fr       */
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
				this->comp = comp;
				this->alloc = alloc;
				tree = RBT<value_type, Compare>(comp, alloc);
			}

			// template <class InputIterator>
			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			// {

			// }
		
			// map (const map& x)
			// {
			
			// }
		
			// map& operator= (const map& x)
			// {
			
			// }
		
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

			// bool empty() const
			// {

			// }

			// size_type size() const
			// {
			
			// }
		
			// size_type max_size() const
			// {
			
			// }
		
		// //! ------------------------- Element access  -------------------------

			// mapped_type& operator[] (const key_type& k)
			// {

			// }
		
		// //! ------------------------- Modifiers -------------------------

			/*pair<iterator,bool>*/void insert(const value_type& val)
			{
				tree.insert_value(val);
			}

			void	print()
			{
				tree.print();
			}

			// iterator insert(iterator position, const value_type& val)
			// {

			// }

			// template <class InputIterator>
			// void insert(InputIterator first, InputIterator last)
			// {
				
			// }

			// void erase(iterator position)
			// {

			// }

			size_type erase(const key_type& k)
			{
				tree.delete_value(k);
				return 1;
			}

			// void erase (iterator first, iterator last)
			// {
			
			// }

			// void swap (map& x)
			// {

			// }
		
			// void clear()
			// {
			
			// }

		// //! ------------------------- Observers -------------------------

			// key_compare key_comp() const
			// {
			
			// }

			// value_compare value_comp() const
			// {
			
			// }

			// 	// ! ------------------------- Operations -------------------------

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
		
			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			// {

			// }
		
			// pair<iterator,iterator> equal_range (const key_type& k)
			// {
			
			// }

		// //! ------------------------- Allocator -------------------------

			// allocator_type get_allocator() const
			// {
			
			// }

		private:
			RBT<value_type,Compare> tree;
			key_compare comp;
			allocator_type alloc;
	};
}

#endif