/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:47 by bsavinel          #+#    #+#             */
	/*   Updated: 2022/07/21 00:17:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"

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
			typedef	T*												iterator;
			typedef	const T*										const_iterator;
			typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;

		//!	------------------------- Constructor -------------------------

			explicit vector(const allocator_type& alloc = allocator_type())
			{
				_start = NULL;
				_end = NULL;
				_alloc = alloc;
				_size = 0;
				_capacity = 0;
			}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_start = NULL;
				_end = NULL;
				_capacity = 0;
				_size = 0;
				reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_start + i, val);
				_end = _start + n;
				_size = n;
			}

			template <class InputIterator>
        	vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				_capacity = 0;
				_start = NULL;
				_end = NULL;
				_size = 0;
				_alloc = alloc;
				reserve(std::distance(first, last));
				_size = std::distance(first, last);
				for (size_type i = 0; i < _size; i++, first++)
					_alloc.construct(_start + i,*(first));
				_end = _start + _size;
			}

			vector(const vector& x)
			{
				_start = NULL;
				_end = NULL;
				_size = 0;
				_capacity = 0;
				*this = x;
			}

			vector& operator= (const vector& x)
			{
				if (this != &x)
				{
					reserve(x._size);
					this->clear();
					for (size_type i = 0; i < x._size; i++)
						_alloc.construct(this->_start + i, *(x._start + i));
					//	*(this->_start + i) = *(x._start + i); 
					this->_size = x._size;
					this->_end = this->_start + this->_size;
				}
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

			iterator begin()
			{
				return _start;
			}

			const_iterator begin() const
			{
				return _start;
			}
			
			iterator end()
			{
				return _end;
			}

			const_iterator end() const
			{
				return _end;
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_end);
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(_end);
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_start);
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_start);
			}

		//!	------------------------- Capacity -------------------------

			size_type size() const
			{
				return _end - _start;
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
				else if (n > _size && n > _capacity * 2)
				{
					reserve(n);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_start + i, val);
				}
				else if (n > _size)
				{
					reserve(_capacity * 2);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_start + i, val);
				}
				_size = n;
				_end = _start + n;
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

			void reserve(size_type n)
			{
				pointer		new_stock;

				if (n <= _capacity)
					return ;
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				new_stock = _alloc.allocate(sizeof(value_type) * n);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(new_stock + i, *(_start + i));
					// *(new_stock + i) = *(_start + i);
					_alloc.destroy(_start + i); // ? pas sur avec ajout de construct
				}
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
				return _start[n];
			}
			
			const_reference operator[](size_type n) const
			{
				return _start[n];
			}

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return _start[n];
			}
			
			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return _start[n];
			}

			reference front()
			{
				return *_start;
			}

			const_reference front() const
			{
				return *_start;
			}

			reference back()
			{
				return *(_end - 1);
			}
			
			const_reference back() const
			{
				return *(_end - 1);
			}

		//!	------------------------- Modifiers -------------------------

			template <class InputIterator>
			void assign(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last)
			{
				clear();
				reserve(std::distance(first, last));
				_size = std::distance(first, last);
				for (size_type i = 0; i < _size; i++, first++)
					_alloc.construct(_start + i, *first);
					// *(_start + i) = *first;
				_end = _start + _size;
			}
			
			void assign(size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_start + i, val);
					//*(_start + i) = val;
				_end = _start + _size;
			}

			void push_back(const value_type& val)
			{
				if (_capacity == 0)
					reserve(1);
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_end, val);
				_end = _end + 1;
				_size++;
			}

			void pop_back()
			{
				_alloc.destroy(_end - 1);
				_end--;
				_size--;
			}

			iterator insert(iterator position, const value_type& val)
			{
				size_type dist_sp = (position - _start);
				if (_capacity == 0)
					reserve(1);
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				position = _start + dist_sp;

				iterator tmp = _end;
				for (;tmp != position; tmp--)
				{
					_alloc.construct(tmp, *(tmp - 1));
					_alloc.destroy(tmp - 1);
					// *(tmp) = *(tmp - 1);
				}
				_alloc.construct(position, val);
				// *position = val;
				_end = _end + 1;
				_size = _size + 1;
				return position;
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type dist_sp = (position - _start);
				size_type new_size = _size + n;
				if (_capacity == 0)
					reserve(1);
				if (new_size > _capacity)
				{
					if (new_size > _size * 2)
						reserve(new_size);
					else
						reserve(_size * 2);
				}
				position = _start + dist_sp;

				iterator tmp = _end - 1;
				iterator new_place = (_end - 1) + n;
				for (;tmp != (position - 1); tmp--, new_place--) 
				{
					_alloc.construct(new_place, *tmp);
					_alloc.destroy(tmp);
					// *(new_place) = *(tmp);
				}
				new_place++;
				for (;position != new_place; position++)
				{
					_alloc.construct(position, val);
					// *(position) = val;
				}

				_end = _end + n;
				_size = _size + n;
			}


			template <class InputIterator>
			void insert(iterator position, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last)
			{
				size_type dist_lf = std::distance(first, last);
				size_type dist_sp = (position - _start);

				size_type new_size = _size + dist_lf;
				if (_capacity == 0)
					reserve(1);
				if (new_size > _capacity)
				{
					if (new_size > _size * 2)
						reserve(new_size);
					else
						reserve(_size * 2);
				}
				position = _start + dist_sp;

				iterator tmp = _end - 1;
				iterator new_place = (_end - 1) + dist_lf;
				for (;tmp != (position - 1); tmp--, new_place--) 
				{
					_alloc.construct(new_place, *tmp);
					_alloc.destroy(tmp);
					// *(new_place) = *(tmp);
				}

				for (;first != last; position++, first++)
				{
					_alloc.construct(position, *(first));
					// *(position) = *(first);
				}
				_end = _end + dist_lf;
				_size = new_size;
			}

			iterator erase(iterator position)
			{
				_alloc.destroy(position);
				for (size_type i = 1; position + i != _end; i++)
				{
					_alloc.destroy(position + i - 1);
					_alloc.construct(position + i - 1, *(position + i));
					// *(position + i - 1) = *(position + i);
				}
				_size--;
				_end = _end - 1;
				return (position);
			}
			
			iterator erase(iterator first, iterator last)
			{
				iterator tmp = first;
				iterator ret = first;
				for (; first != last; first++)
				{
					_alloc.destroy(first);
					_size--;
				}
				for (; first != _end; first++, tmp++)
				{
					_alloc.construct(tmp, *(first));
					_alloc.destroy(first);
					// *tmp = *first;
				}
				_end = tmp;
				return ret;
			}

			void swap(vector& x)
			{
				pointer			tmp_p;
				size_type		tmp_s;
				allocator_type	tmp_a;
				
				tmp_p = this->_start;
				this->_start = x._start;
				x._start = tmp_p;

				tmp_p = this->_end;
				this->_end = x._end;
				x._end = tmp_p;
				
				tmp_p = this->_end_capacity;
				this->_end_capacity = x._end_capacity;
				x._end_capacity = tmp_p;

				tmp_s = this->_size;
				this->_size = x._size;
				x._size = tmp_s;

				tmp_a = this->_alloc;
				this->_alloc = x._alloc;
				x._alloc = tmp_a;

				tmp_s = this->_capacity;
				this->_capacity = x._capacity;
				x._capacity = tmp_s;
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_size = 0;
				_end = _start;
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

	template <class T, class Alloc>
	inline bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	inline bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	inline bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	inline bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	inline bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
	inline bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	inline void swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif