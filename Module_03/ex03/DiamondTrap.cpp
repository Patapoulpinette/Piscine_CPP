/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:37:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/09 18:37:23 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap " << _Name << " default constructor called\n";
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_Name = name;
	std::cout << "DiamondTrap " << _Name << " constructor called\n";
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "DiamondTrap " << _Name << " copy constructor called\n";
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _Name << " destructor called\n";
	return ;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << _Name << " and ClapTrap " << ClapTrap::_Name << std::endl;
	return ;
}

DiamondTrap &	DiamondTrap::operator=(const DiamondTrap &rhs)
{
	_Name = rhs._Name;
	_HitPoints = rhs._HitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_AttackDamage = rhs._AttackDamage;
	return (*this);
}
