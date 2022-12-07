/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:22:40 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/05 20:22:40 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/// Calculate the area of a triangle
/// \return the area of the triangle
/// wich coordinates are (x1, y1), (x2, y2) and (x3, y3)
Fixed area(Fixed const x1, Fixed const y1, Fixed const x2, Fixed const y2, Fixed const x3, Fixed const y3)
{
	Fixed area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * (float) 0.5;
	if (area < 0)
		area = area * -1;
	return (area);
}

// Function that return true if
// the given point lies on the given line
bool pointIsOnLine(Fixed const x1, Fixed const y1, Fixed const x2, Fixed const y2, Fixed const xp, Fixed const yp)
{
	Fixed m = (y2 - y1) / (x2 - x1);
	Fixed c = (m * x1 - y1) * -1;

	if (x1 == x2 && x1 == xp && x2 == xp)
		return (true);
	if (y1 == y2 && y1 == yp && y2 == yp)
		return (true);

	// If (x, y) satisfies the equation of the line
	if (yp == (m * xp + c))
		return (true);
	return (false);
}

/// Check if the Point point is inside the triangle abc or not
/// \return true if the point is inside the triangle, else it returns false
bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	// check if the point is a vertex of the triangle
	if (point == a || point == b || point == c)
		return (false);

	// check if the point is on a line of the triangle
	bool AB = pointIsOnLine(a.get_x(), a.get_y(), b.get_x(), b.get_y(), point.get_x(), point.get_y());
	bool BC = pointIsOnLine(b.get_x(), b.get_y(), c.get_x(), c.get_y(), point.get_x(), point.get_y());
	bool AC = pointIsOnLine(a.get_x(), a.get_y(), c.get_x(), c.get_y(), point.get_x(), point.get_y());
	if (AB || BC || AC)
		return (false);

	// calculate area of triangle ABC
	Fixed A = area(a.get_x(), a.get_y(), b.get_x(), b.get_y(), c.get_x(), c.get_y());
	// calculate area of triangle ABP
	Fixed A1 = area(a.get_x(), a.get_y(), b.get_x(), b.get_y(), point.get_x(), point.get_y());
	// calculate area of triangle APC
	Fixed A2 = area(a.get_x(), a.get_y(), point.get_x(), point.get_y(), c.get_x(), c.get_y());
	// calculate area of triangle PBC
	Fixed A3 = area(point.get_x(), point.get_y(), b.get_x(), b.get_y(), c.get_x(), c.get_y());

	// check if the A area is the same as the sum of A1, A2 and A3 areas
	return (A == A1 + A2 + A3);
}
