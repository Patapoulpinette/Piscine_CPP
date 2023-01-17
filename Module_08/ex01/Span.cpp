/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:20:57 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/17 17:14:32 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}
Span::Span(unsigned int N) : _n(N) {}
Span::Span(const Span &src) { *this = src; }
Span::~Span() {}

Span &Span::operator=(const Span &rhs)
{
	_n = rhs._n;
	_vct = rhs._vct;
	return *this;
}

void Span::addNumber(int number)
{
	try
	{
		if (_vct.size() >= _n)
			throw std::exception();
		_vct.push_back(number);
	}
	catch (std::exception &e)
	{
		std::cerr << "addNumber: no space left on Span" << std::endl;
	}
}

void Span::addNumbers(std::vector<int> &numbers)
{
	try
	{
		if (_vct.size() >= _n)
			throw std::exception();
		if (numbers.size() >= _n - _vct.size())
		{
			_vct.insert(_vct.end(), numbers.begin(), numbers.begin() + _n - _vct.size());
			std::cout << "Span is full now" << std::endl;
		}
		else
			_vct.insert(_vct.end(), numbers.begin(), numbers.end());
	}
	catch (std::exception &e)
	{
		std::cerr << "addNumber: no space left on Span" << std::endl;
	}
}

unsigned int Span::shortestSpan()
{
	try
	{
		if (_vct.size() < 2)
			throw std::exception();
		unsigned int result = UINT_MAX;
		for (std::vector<int>::iterator j = _vct.begin(); j < _vct.end(); j++)
		{
			for (std::vector<int>::iterator i = j + 1; i < _vct.end(); i++)
			{
				if (static_cast<unsigned int>(std::abs(*j - *i)) < result)
					result = std::abs(*j - *i);
			}
		}
		return result;
	}
	catch (std::exception &e)
	{
		std::cerr << "shortestSpan: calculation impossible, 0 or 1 single element in the Span: error ";
		return -1;
	}
}

unsigned int Span::longestSpan()
{
	try
	{
		if (_vct.size() < 2)
			throw std::exception();
		std::vector<int>::iterator min = std::min_element(_vct.begin(), _vct.end());
		std::vector<int>::iterator max = std::max_element(_vct.begin(), _vct.end());
		return *max - *min;
	}
	catch (std::exception &e)
	{
		std::cerr << "longestSpan: calculation impossible, 0 or 1 single element in the Span: error ";
		return -1;
	}
}

void Span::printSpan()
{
	for (std::vector<int>::iterator i = _vct.begin(); i < _vct.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}
