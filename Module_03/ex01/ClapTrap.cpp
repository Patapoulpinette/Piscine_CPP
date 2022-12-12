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

ClapTrap::ClapTrap() : _Name(NULL), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
	return ;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << this->_Name << " constructor called\n";
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << this->_Name << " copy constructor called\n";
	*this = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_Name << " destructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_Name = rhs.get_Name();
	this->_HitPoints = rhs.get_HitPoints();
	this->_EnergyPoints = rhs.get_EnergyPoints();
	this->_AttackDamage = rhs.get_AttackDamage();
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
	if (this->get_EnergyPoints() > 0 && this->get_HitPoints() > 0)
	{
		std::cout << "ClapTrap " << this->get_Name() << " attacks " << target
				<< ", causing " << this->get_AttackDamage() << " points of damage\n";
		this->_EnergyPoints--;
	}
	else
	{
		if (this->get_EnergyPoints() <= 0)
			std::cout << "ClapTrap " << this->get_Name() << " have not enough energy to attack\n";
		if (this->get_HitPoints() <= 0)
			std::cout << "ClapTrap " << this->get_Name() << " have not enough hit points to attack\n";
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->get_Name() << " take " << amount << " points of damage\n";
	if ((this->get_HitPoints() - (int) amount) <= 0)
	{
		this->_HitPoints = 0;
		std::cout << "ClapTrap " << this->get_Name() << " died\n";
	}
	else
		this->_HitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->get_EnergyPoints() > 0 && this->get_HitPoints() > 0)
	{
		std::cout << "ClapTrap " << this->get_Name() << " recovers " << amount << " hit points\n";
		this->_HitPoints += amount;
		this->_EnergyPoints--;
	}
	else
	{
		if (this->get_EnergyPoints() <= 0)
			std::cout << "ClapTrap " << this->get_Name() << " have not enough energy to hill\n";
		if (this->get_HitPoints() <= 0)
			std::cout << "ClapTrap " << this->get_Name() << " have not enough hit points to hill\n";
	}
	return ;
}

void	ClapTrap::attributes() const
{
	std::cout << "┌──────────────────────┐\n";
	std::cout << "│" << std::setw(15) << this->get_Name() << std::setw(11) << "│\n";
	std::cout << "├───────────────┬──────┤\n";
	std::cout << "│ Hit points    │" << std::setw(5) << this->get_HitPoints() << " │\n";
	std::cout << "│ Energy points │" << std::setw(5) << this->get_EnergyPoints() << " │\n";
	std::cout << "│ Attack damage │" << std::setw(5) << this->get_AttackDamage() << " │\n";
	std::cout << "└───────────────┴──────┘" << std::endl;
}
