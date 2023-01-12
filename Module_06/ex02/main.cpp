/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:18 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/12 15:49:55 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base { public : virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate()
{
	Base *base;
	srand(time(NULL));
	int nb = rand() % 3;
	if (nb == 0)
		base = new A;
	else if (nb == 1)
		base = new B;
	else
		base = new C;
	std::cout << "Base generated at: " << base << std::endl;
	return base;
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	if (a != NULL)
		std::cout << "Type object pointed by p is A" << std::endl;
	else if (b != NULL)
		std::cout << "Type object pointed by p is B" << std::endl;
	else if (c != NULL)
		std::cout << "Type object pointed by p is C" << std::endl;
	else
		std::cout << "Conversion NOT ok" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Type object pointed by p is A" << std::endl;
		(void) a;
	}
	catch (std::bad_cast &bc) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Type object pointed by p is B" << std::endl;
		(void) b;
	}
	catch (std::bad_cast &bc) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Type object pointed by p is C" << std::endl;
		(void) c;
	}
	catch (std::bad_cast &bc) {}
}

int main()
{
	Base *base = generate();

	std::cout << "POINTER: ";
	identify(base);

	std::cout << "REFERENCE: ";
	identify(*base);

	delete base;

	return 0;
}
