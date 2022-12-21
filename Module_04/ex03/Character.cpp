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

Character::Character(const Character &src) { *this = src; }

Character::~Character() {}

Character &Character::operator=(const Character &rhs)
{
	_name = rhs._name;
	for (int i = 4; i < 4; i++)
		_inventory[i] = rhs._inventory[i];
	return (*this);
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m)
{
	int i = 0;
	while (i < 4)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
		i++;
	}
	std::cout << "No space left on inventory\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL;
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
