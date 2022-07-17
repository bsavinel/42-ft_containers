/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/17 11:10:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T>>
	class vector
	{
		public :
			typedef	T								value_type;
			typedef	Alloc							allocator_type;
			typedef	allocator_type::reference		reference;
			typedef	allocator_type::const_reference	const_reference;
			typedef	allocator_type::pointer			pointer;
			typedef	allocator_type::const_pointer	const_pointer;
			/*typedef		iterator;
			typedef		const_iterator;
			typedef		reverse_iterator;
			typedef		const_reverse_iterator;*/
			typedef	ptrdiff_t						difference_type;
			typedef	size_t							size_type;

		//!	------------------------- Constructor -------------------------
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				
			}

			template <class InputIterator>
        	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				
			}

			vector (const vector& x)
			{
				
			}
		//!	------------------------- Destructor -------------------------
		
			~vector()
			{
				
			}

		//!	------------------------- Iterators -------------------------

			iterator begin()
			{

			}

			const_iterator begin() const
			{
				
			}
			
			iterator end()
			{

			}

			const_iterator end() const
			{
				
			}

			reverse_iterator rbegin()
			{
				
			}
			
			const_reverse_iterator rbegin() const
			{
				
			}

		//!	------------------------- Capacity -------------------------

			size_type size() const
			{
				
			}

			size_type max_size() const
			{
				
			}
			
			void resize (size_type n, value_type val = value_type())
			{
				
			}

			size_type capacity() const
			{
				
			}

			bool empty() const
			{
				
			}

			void reserve (size_type n)
			{
				
			}

		//!	------------------------- Element access -------------------------

			reference operator[] (size_type n)
			{

			}
			
			const_reference operator[] (size_type n) const
			{
				
			}

			reference at (size_type n)
			{

			}
			
			const_reference at (size_type n) const
			{
				
			}

			reference front()
			{

			}

			const_reference front() const
			{
				
			}

			reference back()
			{

			}
			
			const_reference back() const
			{
				
			}

		//!	------------------------- Modifiers -------------------------

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				
			}
			
			void assign (size_type n, const value_type& val)
			{
				
			}

			void push_back (const value_type& val)
			{
				
			}

			void pop_back()
			{
				
			}

			iterator insert (iterator position, const value_type& val)
			{
				
			}

			void insert (iterator position, size_type n, const value_type& val);
			{
				
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
			{
				
			}

			void insert (iterator position, InputIterator first, iterator erase (iterator position);InputIterator last);
			{
			
			}

			iterator erase (iterator first, iterator last);
			{
				
			}

			void swap (vector& x);
			{
			
			}

			void clear();
			{
				
			}
			
		//!	------------------------- Allocator -------------------------

			allocator_type get_allocator() const
			{
				
			}
	};

	template <class T, class Alloc>
	inline bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		
	}

	template <class T, class Alloc>
	inline bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		
	}

	template <class T, class Alloc>
	inline bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		
	}

	template <class T, class Alloc>
	inline bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		
	}

	template <class T, class Alloc>
	inline bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		
	}

	template <class T, class Alloc>
	inline bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		
	}

	template <class T, class Alloc>
	inline void swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		
	}
}

#endif