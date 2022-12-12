/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/08 15:20:52 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap	Cunegonde("Cunegonde");
	ScavTrap	Robinson("Robinson");
	FragTrap	Agatha("Agatha");
	DiamondTrap	Roberto("Roberto");

	Cunegonde.attributes();
	Robinson.attributes();
	Agatha.attributes();
	Roberto.attributes();

	Robinson.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Robinson.get_AttackDamage());
	Robinson.guardGate();
	Cunegonde.attack(Robinson.get_Name());
	Robinson.beRepaired(20);

	Cunegonde.beRepaired(20);
	Cunegonde.beRepaired(10);

	Robinson.attack(Agatha.get_Name());
	Agatha.takeDamage(Robinson.get_AttackDamage());
	Agatha.beRepaired(10);
	Robinson.attack(Agatha.get_Name());
	Agatha.takeDamage(Robinson.get_AttackDamage());
	Agatha.highFivesGuys();

	Roberto.attack(Robinson.get_Name());
	Robinson.takeDamage(Roberto.get_AttackDamage());
	Roberto.whoAmI();
	Roberto.guardGate();
	Roberto.highFivesGuys();

	Cunegonde.attributes();
	Robinson.attributes();
	Agatha.attributes();
	Roberto.attributes();

	return (0);
}
