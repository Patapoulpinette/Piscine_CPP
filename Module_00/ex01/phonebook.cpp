/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:18 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/14 13:13:18 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int	main(void)
{
	std::string command;

	std::cout << "Please, enter a command [ADD, SEARCH or EXIT] : ";
	std::cin >> command;
	std::cout << "You enter : " << command << std::endl;
}
