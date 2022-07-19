/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/19 23:12:49 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :
			typedef	T												value_type;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			// typedef	typename ft::iterator<pointer>					iterator;
			// typedef	typename ft::iterator<const_pointer>			const_iterator;
			// typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;

		//!	------------------------- Constructor -------------------------

			explicit vector(const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_size = 0;
				_capacity = 0;
			}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				reserve(n);
				for (size_type i = 0; i < n; i++)
				{
					*(_start + i) = val;
				}
				_size = n;
			}

			// template <class InputIterator>
        	// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			// {
				
			// }

			vector(const vector& x)
			{
				*this = x;
			}

			vector& operator= (const vector& x)
			{
				reserve(x->_size);
				this->clear();
				for (size_type i = 0; i < x._size; i++)
				{
					*(this->_start + i) = *(x._start + i); 
				}
				this->_size = x._size;
				return *this;
			}

		//!	------------------------- Destructor -------------------------
		
			~vector()
			{
				clear();
				if (_capacity != 0)
					_alloc.deallocate(_start, sizeof(value_type) * _capacity);
			}

		//!	------------------------- Iterators -------------------------

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

		//!	------------------------- Capacity -------------------------

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _alloc.max_size();
			}
			
			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = n; i < _size ; i++)
						_alloc.destroy(_start + i);
				}
				else if (n > _size)
				{
					reserve(n);
					for (size_type i = _size; i < n; i++)
						*(_start + i) = val;
				}
				_size = n;
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
			{
				if (_size == 0)
					return true;
				return false;
			}

			void reserve (size_type n)
			{
				pointer		new_stock;

				if (n <= _capacity)
					return ;
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				new_stock = _alloc.allocate(sizeof(value_type) * n);
				for (size_type i = 0; i < _size; i++)
					*(new_stock + i) = *(_start + i);
				if (_capacity != 0)
					_alloc.deallocate(_start, sizeof(value_type) * _capacity);
				_start = new_stock;
				_end = _start + _size;
				_end_capacity = _start + n;
				_capacity = n;
			}

		//!	------------------------- Element access -------------------------

			reference operator[](size_type n)
			{
				return _start + n;
			}
			
			const_reference operator[](size_type n) const
			{
				return _start + n;
			}

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return _start + n;
			}
			
			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return _start + n;
			}

			reference front()
			{
				return _start;
			}

			const_reference front() const
			{
				return _start;
			}

			reference back()
			{
				return _end;
			}
			
			const_reference back() const
			{
				return _end;
			}

		//!	------------------------- Modifiers -------------------------

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last)
			// {
				
			// }
			
			// void assign(size_type n, const value_type& val)
			// {
				
			// }

			void push_back(const value_type& val)
			{
				if (_capacity == 0)
					reserve(1);
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				*_end = val;
				_end = _end + 1;
				_size++;
			}

			void pop_back()
			{
				_alloc.destroy(_end);
				_end--;
				_size--;
			}

			// iterator insert(iterator position, const value_type& val)
			// {
				
			// }

			// void insert(iterator position, size_type n, const value_type& val)
			// {
				
			// }

			// template <class InputIterator>
			// void insert(iterator position, InputIterator first, InputIterator last)
			// {
				
			// }

			// void insert(iterator position, InputIterator first, iterator erase (iterator position);InputIterator last)
			// {
			
			// }

			// iterator erase(iterator first, iterator last)
			// {
				
			// }

			void swap(vector& x)
			{
				pointer _tmp;
				
				_tmp = this->_start;
				this->_start = x._start;
				x._start = _tmp;
				
				_tmp = this->_end;
				this->_end = x._end;
				x._end = _tmp;
				
				_tmp = this->_end_capacity;
				this->_end_capacity = x._end_capacity;
				x._end_capacity = _tmp;
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_size = 0;
			}
			
		//!	------------------------- Allocator -------------------------

			allocator_type get_allocator() const
			{
				return allocator_type(_alloc);
			}

			protected:

				size_type		_size;
				size_type		_capacity;
				allocator_type	_alloc;
				pointer			_start;
				pointer			_end_capacity;
				pointer			_end;
				
	};

	// template <class T, class Alloc>
	// inline bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	// {
			// return (lhs.size() != rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
	// }

	// template <class T, class Alloc>
	// inline bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	// {
			// return !(lhs == rhs);
	// }

	// template <class T, class Alloc>
	// inline bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	// {
			// ? Pas compris comment sa marche dans le man il est marque a la premeirer ocurence mais a la premiere ocurence de quoi ?
	// }

	// template <class T, class Alloc>
	// inline bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	// {
			// return !(rhs < lhs);
	// }

	// template <class T, class Alloc>
	// inline bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	// {
			// return rhs < lhs;
	// }

	// template <class T, class Alloc>
	// inline bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	// {
			// return !(lhs < rhs);
	// }

	// template <class T, class Alloc>
	// inline void swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
	// {
			// x.swap(y);
	// }
}

#endif