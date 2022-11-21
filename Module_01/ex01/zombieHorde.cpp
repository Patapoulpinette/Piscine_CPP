/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:53:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/21 13:53:23 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];

	for (int n = 0; n < N; n++)
	{
		horde[n].set_name(name);
		std::cout << "Zombie " << horde[n].get_name() << " created" << std::endl;
	}
	return (horde);
}