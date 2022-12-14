/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:12:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 17:12:34 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &rhs);

		const std::string	&getType() const;
		void				makeSound() const;

	protected:
		std::string	_type;
};

#endif //WRONGANIMAL_HPP
