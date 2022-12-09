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

int main()
{
	ClapTrap	Cunegonde("Cunegonde");
	ClapTrap	Alfonsor("Alfonsor");
	ClapTrap	Geromine("Geromine");

	Cunegonde.attributes();
	Alfonsor.attributes();
	Geromine.attributes();

	Cunegonde.attack(Alfonsor.get_Name());
	Alfonsor.takeDamage(Alfonsor.get_AttackDamage());

	Geromine.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Geromine.get_AttackDamage());

	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Geromine.get_Name());
	Geromine.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Geromine.get_Name());
	Geromine.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Geromine.get_Name());
	Geromine.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Geromine.get_Name());
	Geromine.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Cunegonde.get_Name());
	Cunegonde.takeDamage(Alfonsor.get_AttackDamage());
	Alfonsor.attack(Geromine.get_Name());
	Geromine.takeDamage(12);
	Alfonsor.attack(Cunegonde.get_Name());

	Geromine.beRepaired(6);
	Alfonsor.beRepaired(2);
	Cunegonde.beRepaired(1);

	Geromine.attack(Cunegonde.get_Name());

	Cunegonde.attributes();
	Alfonsor.attributes();
	Geromine.attributes();

	return (0);
}
