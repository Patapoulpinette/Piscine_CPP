/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:49:53 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/13 17:49:53 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &src);
		virtual ~Animal();

		Animal	&operator=(const Animal &rhs);

		const std::string	&getType() const;
		void virtual		makeSound() const;

protected:
			std::string	_type;
};

#endif //ANIMAL_HPP
