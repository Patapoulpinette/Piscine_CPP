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
	std::cout << "ScavTrap default constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _Name << " constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap " << _Name << " copy constructor called\n";
	*this = src;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _Name << " destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		std::cout << "ScavTrap " << _Name << " attacks " << target
				  << ", causing " << _AttackDamage << " points of damage\n";
		this->_EnergyPoints--;
	}
	else
	{
		if (_EnergyPoints <= 0)
			std::cout << "ScavTrap " << _Name << " has not enough energy to attack\n";
		if (_HitPoints <= 0)
			std::cout << "ScavTrap " << _Name << " has not enough hit points to attack\n";
	}
	return ;
}

void	ScavTrap::guardGate()
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
		std::cout << "ScavTrap " << _Name << " enter in Gate Keeper mode\n";
	else
	{
		if (_EnergyPoints <= 0)
			std::cout << "ScavTrap " << _Name << " has not enough energy to enter in Gate Keeper mode\n";
		if (_HitPoints <= 0)
			std::cout << "ScavTrap " << _Name << " has not enough hit points to enter in Gate Keeper mode\n";
	}
	return ;
}

ScavTrap &	ScavTrap::operator=(const ScavTrap &rhs)
{
	_Name = rhs._Name;
	_HitPoints = rhs._HitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_AttackDamage = rhs._AttackDamage;
	return (*this);
}
