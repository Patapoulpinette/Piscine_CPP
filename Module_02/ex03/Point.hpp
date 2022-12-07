/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:43:20 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/05 19:43:20 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float fvalue1, const float fvalue2);
		Point(const Point &src);
		~Point();

		Point &	operator=(const Point &rhs);
		bool	operator==(const Point &rhs) const;

		Fixed const	get_x(void) const;
		Fixed const	get_y(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif //POINT_HPP
