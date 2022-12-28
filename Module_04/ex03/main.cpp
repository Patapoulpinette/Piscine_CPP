/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:17:09 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/19 14:17:09 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "\n--- LEARNING TIME ---\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << "\n--- ME: USE MATERIA ---\n";
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n--- BOB: EQUIP AND USE MATERIA ---\n";
	bob->use(0, *me);
	bob->equip(new Ice());
	bob->use(0, *me);

	std::cout << "\n--- ALFRED: DEEP COPY OF BOB ---\n";
	ICharacter*	alfred = new Character(*(Character *)bob);
	alfred->use(0, *me);
	alfred->use(1, *me);

	std::cout << "\n--- ALFRED: EQUIP, UNEQUIP AND USE MATERIA ---\n";
	alfred->equip(src->createMateria("cure"));
	alfred->unequip(0);
	alfred->use(0, *me);
	alfred->use(1, *me);

	delete alfred;
	delete bob;
	delete me;
	delete src;

	return 0;
}
