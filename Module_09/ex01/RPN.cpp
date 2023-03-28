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
	_stack = rhs._stack;
	_num1 = rhs._num1;
	_num2 = rhs._num2;
	_result = rhs._result;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &expr)
{
	if (expr.empty())
		return;
	if (expr.size() < 3)
	{
		std::cout << RED << "Error:" << NO_COLOR << " not enough elements" << std::endl;
		return;
	}
	std::string::const_iterator itExpr = expr.begin();
	for (;itExpr != expr.end(); itExpr++)
	{
		//Parsing
		if (*itExpr == ' ')
			continue;
		if (!isdigit(*itExpr)
			&& *itExpr != '+' && *itExpr != '-'
			&& *itExpr != '*' && *itExpr != '/')
		{
			std::cout << RED << "Error:" << NO_COLOR << " only digits and operators \"+-*/\"" << std::endl;
			return;
		}

		//Add in stack -----------------------------------------------------------------
		if (isdigit(*itExpr))
		{
			_stack.push(*itExpr - '0');
			if (itExpr + 1 == expr.end())
			{
				std::cout << RED << "Error:" << NO_COLOR << " not enough operators" << std::endl;
				return;
			}
		}
		else
		{
			if (_stack.size() < 2)
			{
				std::cout << RED << "Error:" << NO_COLOR << " first and second elements must be digits / too much operators" << std::endl;
				return;
			}
			_num1 = _stack.top();
			_stack.pop();
			_num2 = _stack.top();
			_stack.pop();
			switch (*itExpr)
			{
				case '+':
					_stack.push(_num2 + _num1);
					break;
				case '-':
					_stack.push(_num2 - _num1);
					break;
				case '*':
					_stack.push(_num2 * _num1);
					break;
				case '/':
					_stack.push(_num2 / _num1);
					break;
				default:
					std::cout << RED << "Error" << NO_COLOR << std::endl;
			}
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << RED << "Error:" << NO_COLOR << " not enough operators" << std::endl;
		return;
	}
	else
	{
		if (_stack.top() > std::numeric_limits<int>::max() || _stack.top() < std::numeric_limits<int>::min())
		{
			std::cout << RED << "Error:" << NO_COLOR << " result is out of range" << std::endl;
			return;
		}
		std::cout << _stack.top() << std::endl;
	}
}
