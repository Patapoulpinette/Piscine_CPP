/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:32:25 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/12 14:03:15 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISCINE_CPP_DATA_HPP
#define PISCINE_CPP_DATA_HPP

class Data
{
	public:
		Data();
		Data(const Data &src);
		Data &operator=(const Data &rhs);
		~ Data();

		unsigned int getValue() const;
		void setValue(unsigned int value);

	private:
		unsigned int _value;
};

#endif //PISCINE_CPP_DATA_HPP
