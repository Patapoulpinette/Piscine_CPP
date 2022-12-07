/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:41:55 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/24 11:41:55 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point const	a1(0, 0);
	Point const	b1(110.3f, 310.2f);
	Point const	c1(210.6f, 0);
	Point const	point1(111.6, 63.4);

	std::cout << "Triangle 1 (point is inside the triangle, result should be \"inside\") : ";
	if (bsp(a1, b1, c1, point1)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	Point	a2(0, 0);
	Point	b2(10.3f, 30.2f);
	Point	c2(20.6f, 1.2f);
	Point	point2(10.6f, 45.2f);

	std::cout << "Triangle 2 (point is outside the triangle, result should be \"outside\") : ";
	if (bsp(a2, b2, c2, point2)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	Point	a3(0, 0);
	Point	b3(0, 30.2f);
	Point	c3(20.6f, 0);
	Point	point3(10.6f, 0);

	std::cout << "Triangle 3 (point is on the line AC of the triangle, result should be \"outside\") : ";
	if (bsp(a3, b3, c3, point3)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	Point	a4(2, 2);
	Point	b4(8, 2);
	Point	c4(8, 42);
	Point	point4(8, 12);

	std::cout << "Triangle 4 (point is on the line BC of the triangle, result should be \"outside\") : ";
	if (bsp(a4, b4, c4, point4)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	Point	a5(2, 2);
	Point	b5(8, 8);
	Point	c5(6, 1);
	Point	point5(4, 4);

	std::cout << "Triangle 5 (point is on the line AB of the triangle, result should be \"outside\") : ";
	if (bsp(a5, b5, c5, point5)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	Point	a6(12.669551f, 24.265f);
	Point	b6(-52.36f, 3.6f);
	Point	c6(18.0236f, -6.964f);
	Point	point6(10.15f, 3.4f);

	std::cout << "Triangle 6 (point is inside the triangle with negative values, result should be \"inside\") : ";
	if (bsp(a6, b6, c6, point6)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	Point	a7(12.669551f, 24.265f);
	Point	b7(-52.36f, 3.6f);
	Point	c7(18.0236f, -6.964f);
	Point	point7(-2.3f, (-2.3f * 0.316406f + 20.2578f));

	std::cout << "Triangle 7 (point is on the line AB of the triangle with negative values, result should be \"outside\") : ";
	if (bsp(a7, b7, c7, point7)) { std::cout << "INSIDE\n"; } else { std::cout << "OUTSIDE\n"; }

	return (0);
}
