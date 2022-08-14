/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:44:43 by bsavinel          #+#    #+#             */
/*   Updated: 2022/08/14 16:28:47 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include "pair.hpp"


namespace ft
{
	typedef enum e_RBT_color
	{
		BLACK,
		RED
	}	t_RBT_color;

	template <class Key, class value>
	struct RBT_node
	{
		typedef	typename pair<const key_type,mapped_type>		value_type;

		RBT_node	*_left;
		RBT_node	*_right;
		RBT_node	*_up;
		value_type	_value;
		t_RBT_color	_color;
		bool		_isLeaf
		
		RBT_node(): _left(NULL), _right(NULL), _value(value_type()), _isLeaf(true), _color(0), _up(NULL)
		{	
		}

		RBT_node(value_type value): _left(NULL), _right(NULL), _value(value), _isLeaf(false), _color(0), _up(NULL)
		{
		}

		RBT_node(value_type value, RBT_node *left, RBT_node *right): _left(left), _right(right), _value(value), _isLeaf(false), _color(0), _up(NULL)
		{
		}

		RBT_node(value_type value, RBT_node *left, RBT_node *right, RBT_node *up): _left(left), _right(right), _value(value), _isLeaf(false), _color(0), _up(up)
		{
		}

		RBT_node(const RBT_node rhs)
		{
			*this = rhs;
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
				this->_isLeaf = rhs._isLeaf;
				this->_value = rhs._value;
				this->_color = rhs._color;
			}
			return *this;
		}
	};
}

#endif