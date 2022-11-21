/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:28 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/21 15:53:28 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		void				setType(std::string value);
		std::string const &	getType() const;

	private:
		std::string	_type;
};

#endif //WEAPON_HPP
