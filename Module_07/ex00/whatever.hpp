/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:18 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/13 17:00:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>

template<typename typeT>
void swap(typeT &a, typeT &b)
{
	typeT tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename typeT>
typeT min(typeT &a, typeT &b)
{
	return ((a < b) ? a : b);
}

template<typename typeT>
typeT max(typeT &a, typeT &b)
{
	return ((a > b) ? a : b);
}

#endif //WHATEVER_HPP
