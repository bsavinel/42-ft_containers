/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:11:10 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/01 12:35:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include "RBT_node.hpp"
#include "pair.hpp"
#include <iostream>
#include <memory>
#include <functional>
#include <cstddef>
#include <iostream>
#include <memory>
#include "pair.hpp"
#include "make_pair.hpp"

namespace ft
{
	template <class T, class Compare, class Alloc = std::allocator<T> >
	class RBT
	{
		public:
			typedef typename T::first_type							key_type;
			typedef	typename T::second_type							mapped_type;
			typedef	T												value_type;
			typedef	Compare											key_compare;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;
			typedef Alloc											allocator_type;
			typedef	ft::RBT_node<value_type, allocator_type>		node;

			RBT(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _root(NULL)
			{
				this->_comp = comp;
				this->_sentinel = new node();
				this->_root = _sentinel;
				_alloc = alloc;
			}

			RBT(const RBT &rhs, const allocator_type& alloc = allocator_type())
			{
				*this = rhs;
				_alloc = alloc;
			}

			~RBT()
			{
				destroyHelper(this->_root);
				delete _sentinel;
			}

			RBT& operator= (const RBT& rhs)
			{
				if (this != &rhs)
				{
					this->_comp = rhs._comp;
					this->_alloc = rhs._alloc;
					//! Mettre iterator pour inserer les element corectement
				}
				return *this;
			}
			
			// ! -------------------------- Utilitaire --------------------------
			
			bool	empty() const
			{
				if (_root == _sentinel)
					return true;
				return false;
			}

			node	*find_key(const key_type key) const
			{
				node	*tmp;
				
				tmp = _root;
				while (tmp != _sentinel)
				{
					if (_comp(key, tmp->_value.first)) //? true a < b
						tmp = tmp->_left;
					else if (_comp(tmp->_value.first, key))
						tmp = tmp->_right;
					else
						return tmp;
				}
				return NULL;
			}

			node	*minimum() const
			{
				node *rootMinimum;
	
				rootMinimum = _root;
				if (!rootMinimum || rootMinimum == _sentinel)
					return NULL;
				while (rootMinimum->_left != _sentinel)
					rootMinimum = rootMinimum->_left;
				return rootMinimum;
			}

			node	*maximum() const
			{
				node *rootMaximum;

				rootMaximum = _root;
				if (!rootMaximum || rootMaximum == _sentinel)
					return NULL;
				while (rootMaximum->_right != _sentinel)
					rootMaximum = rootMaximum->_right;
				return rootMaximum;
			}

			node	*giveSentinel() const
			{
				return _sentinel;
			}

			
			// ! ------------------------- Insert fonction -------------------------
			
			
			ft::pair<node *,bool>	insert_value(const value_type &data)
			{
				node	*y = _sentinel;
				node	*tmp;
				node	*newNode;

				tmp = _root;
				y = NULL;
				while (tmp != _sentinel)
				{
					y = tmp;
					this->setSentinel();
					if (_comp(data.first, tmp->_value.first)) //? true a < b
						tmp = tmp->_left;
					else if (_comp(tmp->_value.first, data.first))
						tmp = tmp->_right;
					else
						return ft::make_pair(_sentinel, false);
				}
				newNode = new node(data, _sentinel, _sentinel, _sentinel, RED, _alloc);
				if (y == NULL)
				{
					_root = newNode;
					_root->_color = BLACK;
					this->setSentinel();
					return ft::make_pair(newNode, true);
				}
				else if (_comp(newNode->_value.first, y->_value.first))
					y->_left = newNode;
				else
					y->_right = newNode;
				newNode->_parent = y;
				if (newNode->_parent->_parent != _sentinel)
					insertFix(newNode);
				this->setSentinel();
				return ft::make_pair(newNode, true);
			}

			// ! ------------------- Delete fonction -------------------

			
			bool	delete_value(key_type key)
			{
				node		*z = NULL;
				node		*x;
				node		*y;
				t_RBT_color saveColor;
								
				z = find_key(key);
				if (z == NULL)
					return false;
				y = z;
				saveColor = y->_color;
				if (z->_left == _sentinel)
				{
					x = z->_right;
					transplant(z, z->_right);
				}
				else if (z->_right == _sentinel)
				{
					x = z->_left;
					transplant(z, z->_left);
				}
				else
				{
					y = minimumNode(z->_right);
					saveColor = y->_color;
					x = y->_right;
					if (y->_parent == z)
						x->_parent = y;
					else
					{
						transplant(y, y->_right);
						y->_right = z->_right;
						y->_right->_parent = y;
					}
					transplant(z, y);
					y->_left = z->_left;
					y->_left->_parent = y;
					y->_color = z->_color;
				}
				delete z;
				if (saveColor == BLACK)
					deleteFix(x);
				this->setSentinel();
				return true;
			}

			void	print() const
			{
				this->printHelper(_root);	
			}

			size_t	size() const
			{
				size_t i = 0;

				this->sizeHelper(_root, &i);
				return i;
			}
			
		private:
			node			*_root;
			key_compare		_comp;
			node			*_sentinel;
			allocator_type	_alloc;

			void	setSentinel()
			{
				_sentinel->_parent = _root;
				_sentinel->_left = this->minimum();
				_sentinel->_right = this->maximum();
            }

			void	printHelper(node *nd) const
			{
				if (nd == _sentinel)
					return;
				this->printHelper(nd->_left);
				std::cout << "{ " << nd->_value.first << " , " << nd->_value.second << " }" << std::endl;
				this->printHelper(nd->_right);
			}

			void	sizeHelper(node *nd, size_t *i) const
			{
				if (nd == _sentinel)
					return;
				(*i)++;
				this->sizeHelper(nd->_left, i);
				this->sizeHelper(nd->_right, i);
			}

			void	destroyHelper(node *ptr)
			{
				if (!ptr || ptr == _sentinel)
					return ;
				destroyHelper(ptr->_left);
				destroyHelper(ptr->_right);
				delete ptr;
			}

		// ! ------------------------- Fix founction -------------------------

			void	insertFix(node *newNode)
			{
				while (newNode->_parent->_color == RED)
				{
					if (newNode->_parent == newNode->_parent->_parent->_left)
					{
						if (newNode->_parent->_parent->_right->_color == RED)
						{
							newNode->_parent->_parent->_right->_color = BLACK;
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							newNode = newNode->_parent->_parent;
						}
						else
						{
							if (newNode->_parent->_right == newNode)
							{
								newNode = newNode->_parent;
								leftRotate(newNode);
							}
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							rightRotate(newNode->_parent->_parent);
						}
					}
					else
					{
						if (newNode->_parent->_parent->_left->_color == RED)
						{
							newNode->_parent->_parent->_left->_color = BLACK;
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							newNode = newNode->_parent->_parent;
						}
						else
						{
							if (newNode == newNode->_parent->_left)
							{
								newNode = newNode->_parent;
								rightRotate(newNode);
							}
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							leftRotate(newNode->_parent->_parent);
						}
					}
					if (newNode == _root)
						break ;
				}
				_root->_color = BLACK;
			}

			void	deleteFix(node *x)
			{
				node *s;

				while (x != _root && x->_color == BLACK)
				{
					if (x == x->_parent->_left)
					{
						s = x->_parent->_right;
						if (s->_color == RED)
						{
							s->_color = BLACK;
							x->_parent->_color = RED;
							leftRotate(x->_parent);
							s = x->_parent->_right;
						}
						if (s->_right->_color == BLACK && s->_left->_color == BLACK)
						{
							s->_color = RED;
							x = x->_parent;
						}
						else 
						{
							if (s->_right->_color == BLACK)
							{
								s->_left->_color = BLACK;
								s->_color = RED;
								rightRotate(s);
								s = x->_parent->_right;
							}
							s->_color = x->_parent->_color;
							x->_parent->_color = BLACK;
							s->_right->_color = BLACK;
							leftRotate(x->_parent);
							x = _root;
						}
					}
					else
					{
						s = x->_parent->_left;
						if (s->_color == RED)
						{
							s->_color = BLACK;
							x->_parent->_color = RED;
							rightRotate(x->_parent);
							s = x->_parent->_left;
						}
						if (s->_right->_color == BLACK && s->_left->_color == BLACK)
						{
							s->_color = RED;
							x = x->_parent;
						}
						else 
						{
							if (s->_left->_color == BLACK)
							{
								s->_right->_color = BLACK;
								s->_color = RED;
								leftRotate(s);
								s = x->_parent->_left;
							}
							s->_color = x->_parent->_color;
							x->_parent->_color = BLACK;
							s->_left->_color = BLACK;
							rightRotate(x->_parent);
							x = _root;
						}
					}
				}
				x->_color = BLACK;
			}

		// ! ---------------------- Private utilitaire ----------------------

			node	*minimumNode(node *rootMinimum)
			{
				if (!rootMinimum || rootMinimum == _sentinel)
					return NULL;
				while (rootMinimum->_left != _sentinel)
					rootMinimum = rootMinimum->_left;
				return rootMinimum;
			}

			node	*maximumNode(node *rootMaximum)
			{
				if (!rootMaximum || rootMaximum == _sentinel)
					return NULL;
				while (rootMaximum->_right != _sentinel)
					rootMaximum = rootMaximum->_right;
				return rootMaximum;
			}

			void	leftRotate(node *x)
			{
				node *y = x->_right;
				
				x->_right = y->_left;
				if (x->_left != _sentinel)
					x->_right->_parent = x;
				y->_parent = x->_parent;
				if (x->_parent == _sentinel)
					_root = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				x->_parent = y;
				y->_left = x;
			}
			
			void	rightRotate(node *x)
			{
				node *y = x->_left;

				x->_left = y->_right;
				if (y->_right != _sentinel)
					y->_right->_parent = x;
				y->_parent = x->_parent;
				if (x->_parent == _sentinel)
					_root = y;
				else if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
				x->_parent = y;
				y->_right = x;
			}

			void	transplant(node *a, node *b)
			{
				if (a->_parent == _sentinel)
					_root = b;
				else if (a == a->_parent->_left)
					a->_parent->_left = b;
				else
					a->_parent->_right = b;
				b->_parent = a->_parent;
			}
	};
}

#endif