/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:44:30 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/28 16:44:30 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->_vector = NULL;
	this->_N = 0;
}

Span::Span(unsigned int N)
{
	this->_N = N;
	this->_vector = new std::vector<int>;
}

Span::Span(const Span &cpy)
{
	*this = cpy;
}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		this->_N = cpy._N;
		if (this->_vector != NULL)
			delete this->_vector;
		this->_vector = new std::vector<int>(*cpy._vector);
	}
	return (*this);
}

Span::~Span()
{
	delete _vector;
}

void Span::addNumber(int n)
{
	if (this->size() >= this->_N)
		throw Span::VectorIsFullException();
	this->_vector->push_back(n);
}

//ordenamos el vector de menor a mayor con sort
int Span::shortestSpan()
{
	int aux = 0;
	int span;
	std::vector<int> auxVec(*this->_vector);
	std::sort(auxVec.begin(), auxVec.end());
	if (this->size() <= 1)
		throw Span::SpanIsImpossibleException(); 
	
	span = auxVec[1] - auxVec[0];
	for (int i = 2; i < this->size(); i++)
	{
		aux = auxVec[i] - auxVec[i - 1];
		if (aux < span)
			span = aux;
	}
	return (span);
}

//Tambien ordenamos y hacemos la diferencia entre el ultimo y el primer numero
int Span::longestSpan()
{
	if (this->size() <= 1)
		throw Span::SpanIsImpossibleException();
	std::vector<int> auxVec(*this->_vector);
	std::sort(auxVec.begin(), auxVec.end());
	return (auxVec[this->size() - 1] - auxVec[0]);
}

unsigned int Span::size()
{
	return (this->_vector->size());
}

const char *Span::VectorIsFullException::what() const throw()
{
	return ("The vector is full");
}

const char *Span::SpanIsImpossibleException::what() const throw()
{
	return ("Vector size is 0 or 1, can't find a Span");
}

void Span::addNumbersInRange(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator i = beg; i != end; ++i)
	{
		this->addNumber(*i);
	}
}
