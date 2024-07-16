/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:08:57 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/16 21:51:00 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
	if (this != &cpy)
	{
		this->stk = cpy.stk;
	}
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isCorrectOperator(const char &c) const
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return (false);
	return (true);
}

//Miramos primero que no haya un numero mayor a 10 y no haya operadores seguidos
//Miramos que solo haya caracteres permitidos
//Miramos que el ultimo caracter no sea un numero
bool RPN::checkExpression(std::string exp) const
{
	for (size_t i = 1; i < exp.length(); i++)
	{
		if (isdigit(exp[i - 1]) && isdigit(exp[i]))
			return (false);
		
	}
	exp.erase(std::remove_if(exp.begin(), exp.end(), isspace), exp.end());
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (i < 2 && isCorrectOperator(exp[i]))
			return (false);
		if (!isdigit(exp[i]) && !isCorrectOperator(exp[i]))
			return (false);
	}
	if (isdigit(exp[exp.length() - 1]))
		return (false);
	return (true);
}

void RPN::calculate(std::string polish)
{
	double	a;
	double	b;
	
	if (!checkExpression(polish))
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	for (size_t i = 0; i < polish.length(); i++)
	{
		if (isdigit(polish[i]))
			this->stk.push(polish[i] - '0');
		else if (isCorrectOperator(polish[i]))
		{
			if (this->stk.size() < 2)
			{
				std::cout << "Error: Not enough operands for operator" << std::endl;
				return ;
			}
			b = this->stk.top();
			this->stk.pop();
			a = this->stk.top();
			this->stk.pop();
			if (polish[i] == '+')
				this->stk.push(a + b);
			else if (polish[i] == '-')
				this->stk.push(a - b);
			else if (polish[i] == '*')
				this->stk.push(a * b);
			else if (polish[i] == '/')
				this->stk.push(a / b);
		}
	}
	if (this->stk.size() != 1)
		std::cout << "Error" << std::endl;
	else
		std::cout << this->stk.top() << std::endl;
}
