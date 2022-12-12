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
	std::cout << "FragTrap " << this->get_Name() << " default constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->get_Name() << " constructor called\n";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap " << this->get_Name() << " copy constructor called\n";
	*this = src;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->get_Name() << " destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->get_Name() << " ask for a high five\n";
	return ;
}

FragTrap &	FragTrap::operator=(const FragTrap &rhs)
{
	this->_Name = rhs.get_Name();
	this->_HitPoints = rhs.get_HitPoints();
	this->_EnergyPoints = rhs.get_EnergyPoints();
	this->_AttackDamage = rhs.get_AttackDamage();
	return (*this);
}
