/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:44:43 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/05 21:28:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include "pair.hpp"
#include <cstddef>
#include <iostream>
#include <memory>

namespace ft
{
	typedef enum e_RBT_color
	{
		BLACK,
		RED
	}	t_RBT_color;

	template <class T, class Alloc = std::allocator<T> >
	struct RBT_node
	{
		typedef	T		value_type;
		typedef	Alloc	allocator_type;

		RBT_node		*_left;
		RBT_node		*_right;
		RBT_node		*_parent;
		value_type		_value;
		t_RBT_color		_color;
		allocator_type	_alloc;
		
		RBT_node(const allocator_type& alloc = allocator_type()): _left(NULL), _right(NULL), _parent(NULL), _value(value_type()), _color(BLACK)
		{
			_alloc = alloc;	
		}

		RBT_node(const value_type &value, RBT_node *left, RBT_node *right, RBT_node *parent, t_RBT_color color, const allocator_type& alloc = allocator_type()): _left(left), _right(right), _parent(parent), _color(color)
		{
			_alloc = alloc;
			_alloc.construct(&_value, value);
		}

		RBT_node(const RBT_node &rhs, const allocator_type& alloc = allocator_type()): _left(rhs._left), _right(rhs._right), _parent(rhs._parent), _color(rhs._color)
		{
			_alloc = alloc;
			_alloc.construct(&_value, rhs.value);
		}

		~RBT_node()
		{
			//_alloc.destroy(&_value);
		}

		RBT_node& operator= (const RBT_node& rhs)
		{
			if (this != &rhs)
			{
				this->_left = rhs._left;
				this->_right = rhs._right;
				this->_right = rhs._parent;
				_alloc.destroy(&_value);
				_alloc.construct(&_value, rhs._value);
				this->_value = rhs._value;
				this->_color = rhs._color;
				this->_alloc = rhs._alloc;
			}
			return *this;
		}
	};
}

#endif