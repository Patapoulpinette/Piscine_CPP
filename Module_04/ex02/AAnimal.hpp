/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:49:53 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/13 17:49:53 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();

		AAnimal	&operator=(const AAnimal &rhs);

		const std::string	&getType() const;
		virtual void		makeSound() const = 0;

	protected:
		std::string	_type;
};

#endif //AANIMAL_HPP
