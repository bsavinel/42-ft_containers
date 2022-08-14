/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:11:10 by bsavinel          #+#    #+#             */
/*   Updated: 2022/08/14 16:27:18 by bsavinel         ###   ########.fr       */
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

			RBT(): _root(NULL)
			{	
			}

			~RBT()
			{
				
			}

		private:
			ft::RBT_node	**_root;
	};
}

#endif