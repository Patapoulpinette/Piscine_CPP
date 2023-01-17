/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:19:24 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/17 17:23:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		virtual ~Span();

		void addNumber(int number);
		void addNumbers(std::vector<int> &numbers);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void printSpan();

	private:
		unsigned int 		_n;
		std::vector<int>	_vct;
};

#endif //SPAN_HPP
