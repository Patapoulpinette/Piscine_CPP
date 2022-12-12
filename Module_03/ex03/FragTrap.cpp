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
	std::cout << "FragTrap " << _Name << " default constructor called\n";
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
	std::cout << "FragTrap " << _Name << " ask for a high five\n";
	return ;
}

FragTrap &	FragTrap::operator=(const FragTrap &rhs)
{
	_Name = rhs.get_Name();
	_HitPoints = rhs.get_HitPoints();
	_EnergyPoints = rhs.get_EnergyPoints();
	_AttackDamage = rhs.get_AttackDamage();
	return (*this);
}
