/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:34:49 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/10 13:34:49 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

# include <iostream>
# include <cmath>

class Convert
{
	public:
		Convert();
		Convert(const std::string &arg);
		Convert(const Convert &src);
		virtual ~Convert();

		Convert &operator=(const Convert &rhs);

		char getC() const;
		int getI() const;
		float getF() const;
		double getD() const;
        const std::string &getArg() const;

    private:
    		const std::string	_arg;
    		char				_c;
    		int					_i;
    		float				_f;
    		double				_d;
};

std::ostream &operator<<(std::ostream &o, Convert const &rhs);

#endif //CONVERT_HPP
