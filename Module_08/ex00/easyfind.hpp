/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:20:14 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/16 15:21:42 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>

template<typename T>
int &easyfind(T &dest, int src)
{
	typename T::iterator i;
	i = std::find(dest.begin(), dest.end(), src);
	if (i == dest.end())
		throw std::exception();
	return *i;
}

#endif //EASYFIND_HPP
