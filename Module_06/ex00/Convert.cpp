/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:34:38 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/10 13:34:38 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{

}

Convert::Convert(const std::string &arg) : _arg(arg)
{
	double	convert;

	if (_arg.length() == 1 && !isdigit(static_cast<int>(_arg[0])))
		convert = static_cast<double>(_arg[0]);
	else
		convert = strtod(_arg.c_str(), NULL);

	_c = static_cast<char>(convert);
	_i = static_cast<int>(convert);
	_f = static_cast<float>(convert);
	_d = static_cast<double>(convert);
}

Convert::Convert(const Convert &src)
{
	*this = src;
}

Convert::~Convert()
{

}

Convert &Convert::operator=(const Convert &rhs)
{
	_c = rhs._c;
	_i = rhs._i;
	_f = rhs._f;
	_d = rhs._d;
	return *this;
}

const std::string &Convert::getArg() const
{
	return _arg;
}

char Convert::getC() const
{
	return _c;
}

int Convert::getI() const
{
	return _i;
}

float Convert::getF() const
{
	return _f;
}

double Convert::getD() const
{
	return _d;
}

std::ostream &operator<<(std::ostream &o, Convert const &rhs)
{
	if ((strtol(rhs.getArg().c_str(), NULL, 10) == 0 && rhs.getArg().length() > 1)
		|| rhs.getC() < std::numeric_limits<int>::min()
		|| rhs.getC() > std::numeric_limits<int>::max())
		o << "char: impossible" << "\n";
	else if (rhs.getC() < 32 || rhs.getC() > 126)
		o << "char: Non displayable" << "\n";
	else
		o << "char: " << rhs.getC() << "\n";
	if (rhs.getArg() == "nan" || rhs.getArg() == "-nan"
		|| rhs.getD() < std::numeric_limits<int>::min()
		|| rhs.getD() > std::numeric_limits<int>::max())
		o << "int: impossible" << "\n";
	else
		o << "int: " << rhs.getI() << "\n";
	o << "float: " << rhs.getF() << "f\n";
	o << "double: " << rhs.getD();
	return (o);
}
