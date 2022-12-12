/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:56:00 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/09 13:56:00 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << this->get_Name() << " default constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->get_Name() << " constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap " << this->get_Name() << " copy constructor called\n";
	*this = src;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->get_Name() << " destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->get_EnergyPoints() > 0 && this->get_HitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->get_Name() << " attacks " << target
				  << ", causing " << this->get_AttackDamage() << " points of damage\n";
		this->_EnergyPoints--;
	}
	else
	{
		if (this->get_EnergyPoints() <= 0)
			std::cout << "ScavTrap " << this->get_Name() << " have not enough energy to attack\n";
		if (this->get_HitPoints() <= 0)
			std::cout << "ScavTrap " << this->get_Name() << " have not enough hit points to attack\n";
	}
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->get_Name() << " enter in Gate Keeper mode\n";
	return ;
}

ScavTrap &	ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_Name = rhs.get_Name();
	this->_HitPoints = rhs.get_HitPoints();
	this->_EnergyPoints = rhs.get_EnergyPoints();
	this->_AttackDamage = rhs.get_AttackDamage();
	return (*this);
}
