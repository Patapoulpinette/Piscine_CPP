/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:43:51 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/05 19:43:51 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return;
}

Point::Point(const float fvalue1, const float fvalue2) : _x(fvalue1), _y(fvalue2)
{
	return;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	return;
}

Point::~Point()
{
	return;
}

Fixed const	Point::get_x(void) const
{
	return (this->_x);
}

Fixed const	Point::get_y(void) const
{
	return (this->_y);
}

Point &	Point::operator=(const Point &rhs)
{
	(void) rhs;
	return (*this);
}

bool Point::operator==(const Point &rhs) const
{
	if (this->_x == rhs._x && this->_y == rhs._y)
		return (true);
	return (false);
}
