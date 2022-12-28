/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:51:00 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/19 15:51:00 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _inventory() {}

Character::Character(const std::string &name) : _name(name), _inventory() {}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

Character::Character(const Character &src)
{
	*this = src;
}

Character &Character::operator=(const Character &rhs)
{
	_name = rhs._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = rhs._inventory[i];
	return (*this);
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _inventory[i]->getType() << " equipped\n";
			return;
		}
	std::cout << "No space left on inventory\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx] == NULL)
			std::cout << "Nothing to unequip\n";
		else
		{
			std::cout << _inventory[idx]->getType() << " unequipped\n";
			_inventory[idx] = NULL;
		}
	}
	else
		std::cout << "Wrong index: must be between 0 to 3\n";
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
		else
			std::cout << "Nothing to use\n";
	}
	else
		std::cout << "Wrong index: must be between 0 to 3\n";
}
