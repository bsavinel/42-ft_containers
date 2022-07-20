/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/20 23:45:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "equal.hpp"
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
				reserve(n);
				for (size_type i = 0; i < n; i++)
					*(_start + i) = val;
				_size = n;
			}

			template <class InputIterator>
        	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_size = last - first;
				reserve(_size);
				for (size_type i = 0; i < _size; i++)
				{
					*(_start + i) = *(first + i);
				}
			}

			vector(const vector& x)
			{
				*this = x;
			}

			vector& operator= (const vector& x)
			{
				reserve(x->_size);
				this->clear();
				for (size_type i = 0; i < x._size; i++)
					*(this->_start + i) = *(x._start + i); 
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
				return reverse_iterator(_end - 1);
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(_end - 1);
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_start - 1);
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_start - 1);
			}

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

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				reseve(last - first);
				_size = last - first;
				for (size_type i = 0; i < _size; i++)
					*(_start + i) = *(first + i);
				_end = _start + _size;
			}
			
			void assign(size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					*(_start + i) = val;
				_end = _start + _size;
			}

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

			iterator insert(iterator position, const value_type& val)
			{
				size_type dist_sp = (position - _start);
				if (_capacity == 0)
					reserve(1);
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				position = _start + dist_sp;

				iterator tmp = _end - 1;
				iterator new_place = _end;
				for (;tmp != (position - 1); tmp--, new_place--) 
				{
					*(new_place) = *(tmp);
				}
				*position = val;
					
				_end = _end + 1;
				_size = _size + 1;
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
					*(new_place) = *(tmp);
				}
				new_place++;
				for (;position != new_place; position++)
				{
					*(position) = val;
				}

				_end = _end + 1;
				_size = _size + n;
			}


			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				size_type dist_lf = (last - first);
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
					*(new_place) = *(tmp);
				}

				for (;first != last; position++, first++)
				{
					*(position) = *(first);
				}
				_end = _end + dist_lf;
				_size = new_size;
			}

			iterator erase(iterator position)
			{
				for (size_type i = 0; position + i != _end; i++)
				{
					_alloc.destroy(position + i);
					_size--;
				}
				_end = position;
				return (_end);
			}
			
			iterator erase(iterator first, iterator last)
			{
				iterator tmp = first;
				for (; first != last; first++)
				{
					_alloc.destroy(first);
					_size--;
				}
				for (; first != _end; first++, tmp++)
				{
					*tmp = *first;
				}
				_end = tmp;
				return _end;
			}

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

	template <class T, class Alloc>
	inline bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
			return (lhs.size() != rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	inline bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
			return !(lhs == rhs);
	}

	template <class T, class Alloc>
	inline bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
			ft::lexicographical_compare(lhs.begin(), lhs.last(), rhs.begin(), rhs.last());
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