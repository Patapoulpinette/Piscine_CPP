/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:44:04 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 15:44:04 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog &src);
		virtual ~Dog();

		Dog	&operator=(const Dog &rhs);

		Brain	*getDogBrain() const;
		void	makeSound() const;

	private:
		Brain	*_dogBrain;
};

#endif //DOG_HPP
