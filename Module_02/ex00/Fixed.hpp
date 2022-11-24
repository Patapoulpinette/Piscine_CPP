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

class Fixed
{
	public:
		Fixed();
		Fixed (const Fixed &);
		~Fixed();
		Fixed &operator=(const Fixed&);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;

	private:
		int					_width;
		static const int	_binary;
};

#endif //FIXED_HPP
