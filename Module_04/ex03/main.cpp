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

int	main()
{
	std::cout << "\n--- LEARN TECHNIQUES ---\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	std::cout << "\n--- ME: CREATE, EQUIP, UNEQUIP AND USE MATERIA ---\n";
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	AMateria* temp = tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(2);
	me->unequip(0);
	me->use(0, *bob);

	std::cout << "\n--- BOB: EQUIP, UNEQUIP AND USE MATERIA ---\n";
	bob->equip(tmp);
	bob->use(0, *me);
	bob->unequip(0);
	bob->equip(new Ice());
	bob->use(0, *me);

	std::cout << "\n--- ALFRED: DEEP COPY OF BOB / USE MATERIA ---\n";
	ICharacter* alfred;
	alfred = bob;
	alfred->use(0, *bob);
	alfred->use(1, *me);
	alfred->equip(new Cure());
	alfred->use(1, *me);

	delete temp;
	delete tmp;
	delete bob;
	delete me;
	delete src;

	return 0;
}
