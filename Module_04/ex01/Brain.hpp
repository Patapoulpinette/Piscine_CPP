/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:37:51 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 17:37:51 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain	&operator=(const Brain &rhs);

		std::string getIdeas(unsigned int index) const;

	private:
		std::string	_ideas[100];

};

#endif //BRAIN_HPP
