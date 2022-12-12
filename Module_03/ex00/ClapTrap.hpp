/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:43:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/08 13:43:23 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <iomanip>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();

		ClapTrap & operator=(const ClapTrap &rhs);

		std::string	get_Name(void) const;
		int 		get_HitPoints(void) const;
		int 		get_EnergyPoints(void) const;
		int 		get_AttackDamage(void) const;
		void		attributes(void) const;

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string	_Name;
		int 		_HitPoints;
		int 		_EnergyPoints;
		int 		_AttackDamage;
};

#endif //CLAPTRAP_HPP
