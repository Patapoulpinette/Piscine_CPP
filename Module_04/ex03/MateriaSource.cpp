/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:09:01 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/19 16:09:01 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _inventory() {}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = rhs._inventory[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	while (i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _inventory[i]->getType() << " learned\n";
			return;
		}
		i++;
	}
	std::cout << "No more space to learn\n";
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	int i = 0;
	while (i < 4)
	{
		if (_inventory[i]->getType() == type)
		{
			std::cout << type << " created\n";
			return _inventory[i]->clone();
		}
		i++;
	}
	std::cout << type << " not created because it hasn't been learned yet\n";
	return NULL;
}
