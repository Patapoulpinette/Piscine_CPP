/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:55:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/21 15:55:23 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::attack() const
{
	if (!this->_weapon)
		return;
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return;
}