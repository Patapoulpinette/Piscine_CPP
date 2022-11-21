/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:33:37 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/18 14:33:37 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void		announce(void);
		void		set_name(std::string name);
		std::string	get_name();

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP
