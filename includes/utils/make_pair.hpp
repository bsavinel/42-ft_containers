/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:05:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/14 13:47:22 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

#include <type_traits>

/* //?  enable_if permet de specialiser le type, le premier element template etant un booleen dans les deux cas se qui permet de passer de l'un a l'autre car l'un des deux n'est que true, cela fait donc le typedef du second template si le premier template est true sinon rien eest et donc si une fonction utilise un enable if alors si la condition est false il ne compileras pas ou si une alternative existe il la choisiras elle,cela perment de creer des fonction avec des meme type mais sous certaine condition les ammene a n choisir une plutot qu'une autre
*/

namespace ft
{
}

#endif