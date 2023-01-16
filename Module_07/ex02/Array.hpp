/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:21:57 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/16 11:45:32 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	public:
		Array() : _n(0) { _array = new T; }
		Array(unsigned int n) : _n(n) { _array = new T[n]; }
		Array(const Array &src)
		{
			unsigned int    i = 0;

			this->_n = src._n;
			this->_array = new T[this->_n];
			while (i < this->_n)
			{
				this->_array[i] = src._array[i];
				i++;
			}
		}
		virtual ~Array() { delete _array; }

		Array &operator=(const Array &rhs)
		{
			delete _array;
			_n = rhs._n;
			_array = new T[rhs._n];
			for (unsigned int i = 0; i < rhs._n; i++)
				_array[i] = rhs._array[i];
			return (*this);
		}

		T &operator[](unsigned int idx)
		{
			if (idx >= _n)
				throw std::invalid_argument("bad argument for operator []");
			return _array[idx];
		}

		const T &operator[](unsigned int idx) const
		{
			if (idx >= _n)
				throw std::invalid_argument("bad argument for operator []");
			return _array[idx];
		}

		unsigned int size() const { return _n; }

	private:
		unsigned int	_n;
		T				*_array;
};


#endif //ARRAY_HPP
