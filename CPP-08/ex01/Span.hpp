/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:44:23 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/28 16:44:23 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int 		_N;
		std::vector<int>	*_vector;
		unsigned int size();

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &cpy);
		Span &operator=(const Span &cpy);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		void addNumbersInRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
		
		class VectorIsFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SpanIsImpossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


