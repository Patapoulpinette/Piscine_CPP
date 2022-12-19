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
#include "MateriaSource.hpp"

Character::Character() : _inventory()
{

}

Character::Character(const std::string &name) : _name(name), _inventory()
{

}

Character::Character(const Character &src)
{
	*this = src;
}

Character::~Character()
{

}

Character &Character::operator=(const Character &rhs)
{
	return (*this);
}

std::string const &Character::getName() const
{

}

void Character::equip(AMateria *m)
{
	// equips the first empty room and when it's full does nothing, without any mistakes
	int i = 0;
	while (!_inventory[i])
	{
		if (!_inventory[i])
			_inventory[i] = m;
		i++;
	}
}

void Character::unequip(int idx)
{
	// doesn't delete inventory
	// does nothing if trying to delete a Materia which doesn't exist
	if (idx > 0 && idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	// La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
	// et passera la cible en paramètre à la fonction AMateria::use
	std::cout << target.getName() << " uses " << _inventory[idx] << std::endl;
}
