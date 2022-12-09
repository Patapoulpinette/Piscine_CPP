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

int main()
{
	ClapTrap	Cunegonde("Cunegonde");
	ClapTrap	Alfonsor("Alfonsor");
	ScavTrap	Robinson("Robinson");

	Cunegonde.attributes();
	Alfonsor.attributes();
	Robinson.attributes();

	Cunegonde.attack(Alfonsor.get_Name());
	Alfonsor.takeDamage(Cunegonde.get_AttackDamage());

	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());

	Robinson.attack(Alfonsor.get_Name());
	Alfonsor.takeDamage(Robinson.get_AttackDamage());
	Robinson.guardGate();
	Alfonsor.attack(Robinson.get_Name());
	Robinson.beRepaired(20);

	Alfonsor.beRepaired(20);
	Cunegonde.beRepaired(10);

	Cunegonde.attributes();
	Alfonsor.attributes();
	Robinson.attributes();

	return (0);
}
