/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:19:25 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/12 14:19:25 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data *ptr = new Data();
	ptr->setValue(42);
	std::cout << "Data pointer: " << ptr << " | Data value: " << ptr->getValue() << std::endl;

	uintptr_t raw = serialize(ptr);
	ptr = deserialize(raw);

	std::cout << "raw pointer:  " << &raw << " | raw value: " << raw << std::endl;
	std::cout << "Data pointer: " << ptr << " | Data value: " << ptr->getValue() << std::endl;

	delete ptr;

	return 0;
}
