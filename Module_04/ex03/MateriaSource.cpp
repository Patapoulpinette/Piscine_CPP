/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:09:01 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/19 16:09:01 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{

}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria *)
{
	// Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner plus tard.
	// Tout comme le Character, la MateriaSource peut contenir 4 Materias maximum.
	// Ces dernières ne sont pas forcément uniques.
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	// Retourne une nouvelle Materia.
	// Celle-ci est une copie de celle apprise précédemment par la MateriaSource
	// et dont le type est le même que celui passé en paramètre.
	// Retourne 0 si le type est inconnu.
	return NULL;
}

// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias afin de les recréer à volonté.
// Ainsi, vous serez capable de générer une nouvelle Materia à partir de son type sous forme de chaîne de caractères.