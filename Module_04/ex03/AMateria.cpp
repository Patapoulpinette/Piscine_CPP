/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:08:19 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/19 11:08:19 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &src) { *this = src; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	_type = rhs._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << _type << " used on " << target.getName() << std::endl;
}
