/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:11:10 by bsavinel          #+#    #+#             */
/*   Updated: 2022/08/17 17:54:28 by bsavinel         ###   ########.fr       */
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

namespace ft
{
	template <class T, class Compare, class Alloc = std::allocator<ft::RBT_node<T> > >
	class RBT
	{
		public:
			typedef typename T::first_type							key_type;
			typedef	typename T::second_type							mapped_type;
			typedef	T												value_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;
			typedef	ft::RBT_node<value_type>						node;

			RBT(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _root(NULL)
			{
				this->_comp = comp;
				this->_alloc = alloc;
				this->_sentinel = new node();
				this->_root = _sentinel;
			}

			RBT(const RBT &rhs)
			{
				*this = rhs;
			}

			~RBT()
			{
			}

			RBT& operator= (const RBT& rhs)
			{
				if (this != &rhs)
				{
					this->_comp = rhs._comp;
					this->_alloc = rhs._alloc;
					this->_root = rhs._root;
					this->_sentinel = rhs._sentinel;
				}
				return *this;
			}

			
			// ! -------------------------- Utilitaire --------------------------
			

			node	*find_key(key_type key)
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

			node	*minimum()
			{
				node *rootMinimum;
	
				rootMinimum = _root;
				if (!rootMinimum || rootMinimum == _sentinel)
					return NULL;
				while (rootMinimum->_left)
					rootMinimum = rootMinimum->_left;
				return rootMinimum;
			}

			node	*maximum()
			{
				node *rootMaximum;

				rootMaximum = _root;
				if (!rootMaximum || rootMaximum == _sentinel)
					return NULL;
				while (rootMaximum->_right)
					rootMaximum = rootMaximum->_left;
				return rootMaximum;
			}

			node	*minimumNode(node *rootMinimum)
			{
				if (!rootMinimum || rootMinimum == _sentinel)
					return NULL;
				while (rootMinimum->_left)
					rootMinimum = rootMinimum->_left;
				return rootMinimum;
			}

			node	*maximumNode(node *rootMaximum)
			{
				if (!rootMaximum || rootMaximum == _sentinel)
					return NULL;
				while (rootMaximum->_right)
					rootMaximum = rootMaximum->_left;
				return rootMaximum;
			}
			
			// ! ------------------------- Insert fonction -------------------------
			
			
			bool	insert_value(const value_type &data)
			{
				node	*y = _sentinel;
				node	*tmp;
				node	*newNode;

				tmp = _root;
				y = NULL;
				std::cerr << "debut recherche" << std::endl;
				while (tmp != _sentinel)
				{
					y = tmp;
					if (_comp(data.first, tmp->_value.first)) //? true a < b
						tmp = tmp->_left;
					else if (_comp(tmp->_value.first, data.first))
						tmp = tmp->_right;
					else
						return false;
				}

				std::cerr << "apres recherche" << std::endl;
				newNode = _alloc.allocate(sizeof(node));
				_alloc.construct(newNode, node(data, _sentinel, _sentinel, _sentinel, RED));

				std::cerr << "mise en place dans l'arbre" << std::endl;
				if (y == NULL)
				{
					_root = newNode;
					_root->_color = BLACK;
					return true;
				}
				else if (_comp(newNode->_value.first, y->_value.first))
					y->_left = newNode;
				else
					y->_right = newNode;
				newNode->_parent = y;
				
				std::cerr << "debut insert fix" << std::endl;
				if (newNode->_parent->_parent != _sentinel)
					insertFix(newNode);
				std::cerr << "fin insert fix" << std::endl;
				return true;
			}

			// ! ------------------- Delete fonction -------------------

			
			bool	delete_value(key_type key)
			{
				node		*nodeToDelete;
				node		*x;
				node		*y;
				t_RBT_color saveColor;
				
				nodeToDelete = find_key(key);
				if (nodeToDelete == NULL)
					return false;
				saveColor = nodeToDelete->_color;
				if (nodeToDelete->_left == _sentinel)
				{
					x = nodeToDelete->_right;
					transplant(nodeToDelete, x);
				}
				else if (nodeToDelete->_right == _sentinel)
				{
					x = nodeToDelete->_left;
					transplant(nodeToDelete, x);
				}
				else
				{
					y = minimumNode(nodeToDelete->_right);
					saveColor = y->_color;
					x = y->_right;
					if (y->_parent == nodeToDelete)
					{
						x->_parent = y;
					}
					else
					{
						transplant(y, y->_right);
						y->_right = nodeToDelete->_right;
						y->_right->_parent = y;
					}
					transplant(nodeToDelete, y);
					y->_left = nodeToDelete->_left;
					y->_left->_parent = y;
					y->_color = nodeToDelete->_color;
				}
				_alloc.destroy(nodeToDelete);
				_alloc.deallocate(nodeToDelete, sizeof(node));
				if (saveColor == BLACK)
					deleteFix(x);
				return true;
			}

			void	print()
			{
				printHelper(_root);
			}

		private:
			node			*_root;
			key_compare		_comp;
			allocator_type	_alloc;
			node			*_sentinel;

			void printHelper(node *ptr)
			{
				if (!ptr || ptr == _sentinel)
					return ;
				printHelper(ptr->_left);
				std::cout << ptr->_value.first << std::endl;
				printHelper(ptr->_right);
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
							rightRotate(newNode->_parent->_parent);
						}
					}
					if (newNode == _root)
						break ;
				}
				_root->_color = BLACK;
			}

			void	deleteFix(node *x)
			{
				node *w;

				while (x->_color == BLACK && x != _root)
				{
					if (x == x->_parent->_left)
					{
						w = x->_parent->_right;
						if (w->_color == RED)
						{
							w->_color = BLACK;
							x->_parent->_color = RED;
							leftRotate(x->_parent);
							w = x->_parent->_right;
						}
						if (w->_right->_color == BLACK && w->_left->_color == BLACK)
						{
							w->_color = RED;
							x = x->_parent;
						}
						else 
						{
							if (w->_right->_color == BLACK)
							{
								w->_left->_color = BLACK;
								w->_color = RED;
								rightRotate(w);
								w = x->_parent->_right;
							}
							w->_color = x->_parent->_color;
							x->_parent->_color = BLACK;
							w->_right->_color = BLACK;
							leftRotate(x->_parent);
							x = _root;
						}
					}
					else
					{
						w = x->_parent->_left;
						if (w->_color == RED)
						{
							w->_color = BLACK;
							x->_parent->_color = RED;
							rightRotate(x->_parent);
							w = x->_parent->_left;
						}
						if (w->_right->_color == BLACK && w->_left->_color == BLACK)
						{
							w->_color = RED;
							x = x->_parent;
						}
						else 
						{
							if (w->_left->_color == BLACK)
							{
								w->_right->_color = BLACK;
								w->_color = RED;
								leftRotate(w);
								w = x->_parent->_left;
							}
							w->_color = x->_parent->_color;
							x->_parent->_color = BLACK;
							w->_left->_color = BLACK;
							rightRotate(x->_parent);
							x = _root;
						}
					}
				}
			}

		// ! ---------------------- Private utilitaire ----------------------

			void	leftRotate(node *x)
			{
				std::cerr << "debut left rotate" << std::endl;
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
				std::cerr << "fin left rotate" << std::endl;
			}
			
			void	rightRotate(node *x)
			{
				std::cerr << "debut right rotate" << std::endl;
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
				std::cerr << "fin right rotate" << std::endl;
			}

			void	transplant(node *a, node *b)
			{
				if (a == _root)
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