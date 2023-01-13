/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:21:57 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/13 18:22:22 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
	public:
		Array() { _array = new T; }
		Array(unsigned int n) { _array = new T[n]; _n = n; }
		Array(const Array &src) { *this = src; }
		Array &operator=(const Array &rhs)
		{
			delete _array;
			_array = new T[rhs._array];
			return (*this);
		}

	private:
		T				_array[];
		unsigned int	_n;
};


#endif //ARRAY_HPP
