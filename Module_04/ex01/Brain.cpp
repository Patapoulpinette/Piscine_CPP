/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:37:41 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 17:37:41 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called\n";
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain	&Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}
