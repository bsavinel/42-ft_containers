/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:44:43 by bsavinel          #+#    #+#             */
/*   Updated: 2022/08/17 17:20:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include "pair.hpp"
#include <cstddef>

namespace ft
{
	typedef enum e_RBT_color
	{
		BLACK,
		RED
	}	t_RBT_color;

	template <class T>
	struct RBT_node
	{
		typedef	T	value_type;

		RBT_node	*_left;
		RBT_node	*_right;
		RBT_node	*_parent;
		value_type	_value;
		t_RBT_color	_color;
		
		RBT_node(): _left(NULL), _right(NULL), _parent(NULL), _value(value_type()), _color(BLACK)
		{	
		}

		RBT_node(value_type value, RBT_node *left, RBT_node *right, RBT_node *parent, t_RBT_color color): _left(left), _right(right), _parent(parent), _value(value), _color(color)
		{
		}

		RBT_node(const RBT_node &rhs): _left(rhs._left), _right(rhs._right), _parent(rhs._parent), _value(rhs._value), _color(rhs._color)
		{
		}

		~RBT_node()
		{	
		}

		RBT_node& operator= (const RBT_node& rhs)
		{
			if (this != &rhs)
			{
				this->_left = rhs._left;
				this->_right = rhs._right;
				this->_right = rhs._parent;
				this->_value = rhs._value;
				this->_color = rhs._color;
			}
			return *this;
		}
	};
}

#endif