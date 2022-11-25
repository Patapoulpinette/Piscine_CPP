/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:43:28 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/24 11:43:28 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed (const Fixed &src);
		~Fixed();

		Fixed &	operator=(const Fixed &rhs);
//		bool	operator<(const Fixed &rhs) const;
//		bool	operator>(const Fixed &rhs) const;
//		bool	operator<=(const Fixed &rhs) const;
//		bool	operator>=(const Fixed &rhs) const;
//		bool	operator==(const Fixed &rhs) const;
//		bool	operator!=(const Fixed &rhs) const;

		void	setRawBits(int const raw);
		int		getRawBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_number;
		static const int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif //FIXED_HPP
