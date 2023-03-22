/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:58:40 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/14 16:58:40 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &src) { *this = src; }

RPN &RPN::operator=(const RPN &rhs)
{
	(void) rhs;
	//TODO at the end
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &expr)
{
	if (expr.empty())
		return;
	std::string::const_iterator itExpr = expr.begin();
	for (;itExpr != expr.end(); itExpr++)
	{
		//Parsing ----------------------------------------------------------------------
		if (expr[*itExpr] == ' ')
			continue;
//		CANNOT DO THAT - MUST CHECK WITH STACK SIZE EVERY TIME BEFORE AN OPERATION
//		if ((itExpr == expr.begin() && !isdigit(expr[*itExpr]))
//			|| (itExpr == expr.begin() + 1 && !isdigit(expr[*itExpr])))
//		{
//			std::cout << RED << "Error:" << NO_COLOR << " first and second chars must be digits" << std::endl;
//			return;
//		}
		if (!isdigit(expr[*itExpr])
			&& expr[*itExpr] != '+' && expr[*itExpr] != '-'
			&& expr[*itExpr] != '*' && expr[*itExpr] != '/')
		{
			std::cout << RED << "Error:" << NO_COLOR << " only digits or operator \"+-*/\"" << std::endl;
			return;
		}

		//Add in stack -----------------------------------------------------------------
		//TODO
	}
}
