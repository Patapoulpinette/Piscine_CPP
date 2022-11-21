/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/21 15:54:59 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

void	Weapon::setType(std::string value)
{
	this->_type = value;
	return;
}

std::string const &	Weapon::getType() const
{
	return (this->_type);
}