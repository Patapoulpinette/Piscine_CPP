/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:55 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/14 16:57:55 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISCINE_CPP_RPN_HPP
# define PISCINE_CPP_RPN_HPP

# include <string>
# include <iostream>
# include <stack>

# define RED "\033[0;31m"
# define WHITE_ITALIC "\033[1;3;37m"
# define NO_COLOR "\033[0m"

class RPN
{
	public:
		RPN();
		~RPN();

		void calculate(const std::string &expr);

	private:
		RPN(const RPN &src);
		RPN &operator=(const RPN &rhs);

		std::stack<int> _stack;
};

#endif //PISCINE_CPP_RPN_HPP
