/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:31:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/18 14:31:59 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* new_zombie;

	new_zombie = newZombie("Eleonor");
	if (!new_zombie)
		return (1);
	new_zombie->announce();
	randomChump("Baptiste");
	delete new_zombie;
	return (0);
}
