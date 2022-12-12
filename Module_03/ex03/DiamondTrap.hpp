/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:36:07 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/09 18:36:07 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include <string>
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();

		DiamondTrap & operator=(const DiamondTrap &rhs);

		void	attack(const std::string &target);
		void	whoAmI(void);

	private:
		std::string	_Name;
};

#endif //DIAMONDTRAP_HPP
