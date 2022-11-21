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
	Zombie*	new_horde;

	new_horde = zombieHorde(8, "Sarah");
	if (!new_horde)
		return (1);
	for (int n = 0; n < 8; n++)
		new_horde[n].announce();
	delete [] new_horde;

	new_horde = zombieHorde(2, "Jean");
	if (!new_horde)
		return (1);
	for (int n = 0; n < 2; n++)
		new_horde[n].announce();
	delete [] new_horde;
	return (0);
}
