/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:09:37 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/09 18:09:37 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _Name << " constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap " << _Name << " copy constructor called\n";
	*this = src;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _Name << " destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys()
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
		std::cout << "FragTrap " << _Name << " asks for a high five\n";
	else
	{
		if (_EnergyPoints <= 0)
			std::cout << "FragTrap " << _Name << " has not enough energy to ask for a high five\n";
		if (_HitPoints <= 0)
			std::cout << "FragTrap " << _Name << " has not enough hit points to ask for a high five\n";
	}
	return ;
}

FragTrap &	FragTrap::operator=(const FragTrap &rhs)
{
	_Name = rhs._Name;
	_HitPoints = rhs._HitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_AttackDamage = rhs._AttackDamage;
	return (*this);
}
