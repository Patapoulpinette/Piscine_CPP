/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:34:31 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/18 14:34:31 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/// Creates a zombie, gives him a name,
/// and returns it so it can be used outside the scope of the function
/// \param name
/// \return pointer of Zombie class
Zombie* newZombie(std::string name)
{
	Zombie*	new_zombie = new Zombie(name);
	return (new_zombie);
}