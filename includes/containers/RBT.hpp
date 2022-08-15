/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:11:10 by bsavinel          #+#    #+#             */
/*   Updated: 2022/08/15 21:14:29 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include "RBT_node.hpp"
#include "pair.hpp"
#include <memory>
#include <functional>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class RBT
	{
		public:
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef	typename pair<const key_type,mapped_type>		value_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;
			typedef	ft::RBT_node									node;

			RBT(): _root(NULL)
			{
			}

			RBT(const RBT rhs):
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
					copy_tree(_root, _root);
				}
				return *this;
			}

			void	copy_tree(node *localRoot, node *copyRoot)
			{
				*localRoot = *copyRoot;
				if (copyRoot->_left != NULL)
					copy_tree(localRoot->_left, localRoot->_left);
				if (copyRoot->_right != NULL)
					copy_tree(localRoot->_right, localRoot->_right);
			}
			
			// ! -------------------------- Utilitaire --------------------------
			

			node	*find_key(key_type key)
			{
				node	*nodeToDelete;
				node	*tmp;
				
				tmp = root;
				nodeToDelete == NULL;
				while (!tmp != NULL)
				{
					y = tmp;
					if (key_compare(key, tmp->_value.first)) //? true a < b
						tmp = tmp->_left;
					else (key_compare(tmp->_value.first, key))
						tmp = tmp->_right;
					else
						return tmp;
				}
				return NULL;
			}

			node	*minimum_node(node *rootMinimum)
			{
				if (!rootMinimum)
					return NULL;
				while (rootMinimum->_left)
					rootMinimum = rootMinimum->_left;
			}
			
			// ! ------------------------- Insert fonction -------------------------
			
			void	insertFix(node *newNode)
			{
				while (newNode->_parent->_color == RED)
				{
					if (newNode->_parent == newNode->_parent->_parent->_left)
					{
						if (newNode->_parent->_parent->_right->_color == RED)
						{
							newNode->_parent->_parent->_right->_color = BLACK;
							newNode->_parent->_parent->_left->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							newNode = newNode->_parent->_parent;
						}
						else
						{
							if (newNode->_parent->_right == newNode)
							{
								newNode = newNode->_parent;
								left_rotate(newNode);
							}
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							right_rotate(newNode->_parent->_parent);
						}
					}
					else
					{
						if (newNode->_parent->_parent->_left->_color == RED)
						{
							newNode->_parent->_parent->_left->_color = BLACK;
							newNode->_parent->_parent->_right->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							newNode = newNode->_parent->_parent;
						}
						else
						{
							if (newNode == newNode->_parent->_left)
							{
								newNode = newNode->_parent;
								right_rotate(newNode);
							}
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							right_rotate(newNode->_parent->_parent);
						}
					}
					if (newNode == _root)
						break ;
				}
				_root->_color = BLACK;
			}
			
			bool	insert_value(value_type data)
			{
				node	*y = NULL;
				node	*x = _root;
				node	*tmp;
				node	*newNode;

				newNode = allocator_type.allocate(sizeof(node));
				allocator_type.construct(newNode, node(data));
				if (_root == NULL)
					_root = newNode;
				else
				{
					tmp = _root;
					while (!tmp != NULL)
					{
						y = tmp;
						if (key_compare(newNode->_value.first, tmp->_value.first)) //? true a < b
							tmp = tmp->_left;
						else
							tmp = tmp->_right;
					}
					newNode->parent = y;
					if (key_compare(newNode->_value.first, y->_value.first)) //? true a < b
						y->_left = newNode;
					else if (key_compare(y->_value.first, newNode->_value.first))
						y->_right = newNode;
					else
						return false;
					newNode->_color = RED;
					insertFix(newNode);
				}
				return true;
			}

			// ! ------------------- Delete fonction -------------------

			bool	delete_value(key_type key)
			{
				node		*nodeToDelete;
				node		*x;
				node		*y;
				t_RBT_color saveColor;
				
				nodeToDelete = find(key);
				if (nodeToDelete == NULL)
					return false;
				saveColor = nodeToDelete->_color;
				if (nodeToDelete->_left == NULL)
				{
					x = nodeToDelete->_right;
					transplant(nodeToDelete, x);
				}
				else if (nodeToDelete->_right == NULL)
				{
					x = nodeToDelete->_left;
					transplant(nodeToDelete, x);
				}
				else
				{
					y = minimum_node(nodeToDelete->right);
					saveColor = y->_color;
					x = y->_right;
					if (y->_parent == nodeToDelete)
					{
						x->_parent = y;
					}
					else
					{
						transplant(y, y->_right);
						y->_right = z->_right
						y->_right->_parent = y;
					}
					transplant(nodeToDelete, y);
					y->_left = nodeToDelete->_left;
					y->_left->_parent = y;
					y->_color = z->_color
				}
				allocator_type.destroy(nodeToDelete);
				allocator_type.deallocate(nodeToDelete);
				if (saveColor == BLACK)
					deleteFix(x);
				return true;
			}

		private:
			node	*_root;

		// ! ---------------------- Private utilitaire ----------------------

			void	left_rotate(node *x)
			{
				node *y = x->_right;
				
				x->_right = y->_left;
				if (x->right != NULL)
					x->_right->_parent = x;
				y->_parent = x->_parent;
				if (x->_parent == NULL)
					_root = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				x->_parent = y;
				y->_left = x;
			}
			
			void	right_rotate(node *y)
			{
				node *x = y->_right;

				y->_left = x->right;
				if (y->_left != NULL)
					y->_left->_parent = y;
				x->_parent = y->_parent;
				if (y->_parent == NULL)
					_root = x;
				else if (y == y->_parent->_left)
					y->_parent->_left = x;
				else
					y->_parent->_right = x;
				y->_parent = x;

			void	transplant(node *a, node *b)
			{
				if (a == _root)
					_root = b;
				else if (a == a->_parent->_left)
					a->parent->_left = b;
				else
					a->parent->_right = b;
				b->parent = a->parent;
			}
				x->_right = y;
			}
	};
}

#endif