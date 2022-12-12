/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:43:46 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/08 13:43:46 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
	return ;
}

ClapTrap::ClapTrap(const std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << _Name << " constructor called\n";
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << _Name << " copy constructor called\n";
	*this = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _Name << " destructor called\n";
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	_Name = rhs._Name;
	_HitPoints = rhs._HitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_AttackDamage = rhs._AttackDamage;
	return (*this);
}

std::string	ClapTrap::get_Name() const
{
	return (this->_Name);
}

int	ClapTrap::get_HitPoints() const
{
	return (this->_HitPoints);
}

int	ClapTrap::get_EnergyPoints() const
{
	return (this->_EnergyPoints);
}

int	ClapTrap::get_AttackDamage() const
{
	return (this->_AttackDamage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing "
				  << _AttackDamage << " points of damage\n";
		_EnergyPoints--;
	}
	else
	{
		if (_EnergyPoints <= 0)
			std::cout << "ClapTrap " << _Name << " have not enough energy to attack\n";
		if (_HitPoints <= 0)
			std::cout << "ClapTrap " << _Name << " have not enough hit points to attack\n";
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _Name << " take " << amount << " points of damage\n";
	if ((_HitPoints - (int) amount) <= 0)
	{
		_HitPoints = 0;
		std::cout << "ClapTrap " << _Name << " died\n";
	}
	else
		_HitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		std::cout << "ClapTrap " << _Name << " recovers " << amount << " hit points\n";
		_HitPoints += amount;
		_EnergyPoints--;
	}
	else
	{
		if (_EnergyPoints <= 0)
			std::cout << "ClapTrap " << _Name << " have not enough energy to hill\n";
		if (_HitPoints <= 0)
			std::cout << "ClapTrap " << _Name << " have not enough hit points to hill\n";
	}
	return ;
}

void	ClapTrap::attributes() const
{
	std::cout << "┌──────────────────────┐\n";
	std::cout << "│" << std::setw(15) << _Name << std::setw(11) << "│\n";
	std::cout << "├───────────────┬──────┤\n";
	std::cout << "│ Hit points    │" << std::setw(5) << _HitPoints << " │\n";
	std::cout << "│ Energy points │" << std::setw(5) << _EnergyPoints << " │\n";
	std::cout << "│ Attack damage │" << std::setw(5) << _AttackDamage << " │\n";
	std::cout << "└───────────────┴──────┘" << std::endl;
}
