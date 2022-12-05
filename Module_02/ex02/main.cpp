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

#include "Fixed.hpp"

int	main()
{
	Fixed 		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed		c(3.3f);
	Fixed		d(18.6f);
	Fixed		e(3.3f);
	Fixed const f(65);

// Increment and decrement -----------------------------------------------------

	std::cout << "INCREMENT AND DECREMENT -----------------------------------------------------\n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

// Calculation operators -------------------------------------------------------

	std::cout << "CALCULATION OPERATORS -------------------------------------------------------\n";
	std::cout << c << " + " << d << " = " << c + d << std::endl;
	std::cout << c << " - " << d << " = " << c - d << std::endl;
	std::cout << c << " * " << d << " = " << c * d << std::endl;
	std::cout << c << " / " << d << " = " << c / d << std::endl;

// Comparison operators --------------------------------------------------------

	std::cout << "COMPARISON OPERATORS --------------------------------------------------------\n";
	//	operator <
	if (c < d) { std::cout << c << " < " << d << " : True\n"; } else { std::cout << c << " < " << d << " : False\n"; }
	if (d < c) { std::cout << d << " < " << c << " : True\n"; } else { std::cout << d << " < " << c << " : False\n"; }
	if (c < e) { std::cout << c << " < " << e << " : True\n"; } else { std::cout << c << " < " << e << " : False\n"; }

	//	operator >
	if (c > d) { std::cout << c << " > " << d << " : True\n"; } else { std::cout << c << " > " << d << " : False\n"; }
	if (d > c) { std::cout << d << " > " << c << " : True\n"; } else { std::cout << d << " > " << c << " : False\n"; }
	if (c > e) { std::cout << c << " > " << e << " : True\n"; } else { std::cout << c << " > " << e << " : False\n"; }

	//	operator <=
	if (c <= d) { std::cout << c << " <= " << d << " : True\n"; } else { std::cout << c << " <= " << d << " : False\n"; }
	if (d <= c) { std::cout << d << " <= " << c << " : True\n"; } else { std::cout << d << " <= " << c << " : False\n"; }
	if (c <= e) { std::cout << c << " <= " << e << " : True\n"; } else { std::cout << c << " <= " << e << " : False\n"; }

	//	operator >=
	if (c >= d) { std::cout << c << " >= " << d << " : True\n"; } else { std::cout << c << " >= " << d << " : False\n"; }
	if (d >= c) { std::cout << d << " >= " << c << " : True\n"; } else { std::cout << d << " >= " << c << " : False\n"; }
	if (c >= e) { std::cout << c << " >= " << e << " : True\n"; } else { std::cout << c << " >= " << e << " : False\n"; }

	//	operator ==
	if (c == d) { std::cout << c << " == " << d << " : True\n"; } else { std::cout << c << " == " << d << " : False\n"; }
	if (d == c) { std::cout << d << " == " << c << " : True\n"; } else { std::cout << d << " == " << c << " : False\n"; }
	if (c == e) { std::cout << c << " == " << e << " : True\n"; } else { std::cout << c << " == " << e << " : False\n"; }

	//	operator !=
	if (c != d) { std::cout << c << " != " << d << " : True\n"; } else { std::cout << c << " != " << d << " : False\n"; }
	if (d != c) { std::cout << d << " != " << c << " : True\n"; } else { std::cout << d << " != " << c << " : False\n"; }
	if (c != e) { std::cout << c << " != " << e << " : True\n"; } else { std::cout << c << " != " << e << " : False\n"; }

// Min and max -----------------------------------------------------------------

	std::cout << "MIN AND MAX -----------------------------------------------------------------\n";
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "Min between " << c << " and "<< d << " : " << Fixed::min(c, d) << std::endl;
	std::cout << "Min between " << b << " and "<< f << " : " << Fixed::min(b, f) << std::endl;
	std::cout << "Max between " << c << " and "<< d << " : " << Fixed::max(c, d) << std::endl;
	std::cout << "Max between " << b << " and "<< f << " : " << Fixed::max(b, f) << std::endl;

	return (0);
}
