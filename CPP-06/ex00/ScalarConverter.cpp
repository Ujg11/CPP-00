/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:44:49 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/25 16:34:34 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::printChar(char c)
{
	std::cout << "char: '" << c << "'" <<  std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(int i)
{
	char c = static_cast<char>(i);

	if (i >= 0 && i <= 127 && std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	char c = static_cast<char>(d);

	if (d >= 0 && d <= 127 && std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (d >= -FLT_MAX && d <= FLT_MAX)
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	char c = static_cast<char>(f);

	if (f >= 0 && f <= 127 && std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f >= INT_MIN && f <= static_cast<float>(INT_MAX))
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

bool ScalarConverter::checkInt(std::string s)
{
	double d = std::atof(s.c_str());

	if (d >= INT_MIN && d <= INT_MAX)
		return (true);
	return (false);
}

bool ScalarConverter::checkFloat(std::string s)
{
	double d = std::atof(s.c_str());

	if (d >= -FLT_MAX && d <= FLT_MAX)
		return (true);
	return (false);
}

void ScalarConverter::printInfinite(std::string param)
{
	if (param == "-inff" || param == "+inff" || param == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << param << std::endl;
		param.resize(param.size() - 1);
		std::cout << "double: " << param << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << param << "f" << std::endl;
		std::cout << "double: " << param << std::endl;
	}
}

void ScalarConverter::convert(std::string param)
{
	if (param.empty())
	{
		std::cout << "Error! Literal is empty" << std::endl;
		return ;
	}
	if (param == "-inff" || param == "+inff" || param == "nanf" || param == "-inf"
		|| param == "+inf" || param == "nan")
	{
		printInfinite(param);
		return ;
	}
	if (param.size() == 1 && !isdigit(param[0]))
	{
		if (std::isprint(param[0]))
			printChar((char)param[0]);
		else
		{
			std::cout << "Error! The string is a non displayable character" << std::endl;
			return ;
		}
	}
	else if (param.find(".") == std::string::npos)
	{
		for (size_t i = 0; i < param.length(); i++)
		{
			if (i == 0 && param[i] == '-')
				i = 0;
			else if (!isdigit(param[i]))
			{
				std::cout << "Error! Literal is incorrect" << std::endl;
				return ;
			}
		}
		if (checkInt(param))
			printInt(std::atoi(param.c_str()));
		else
			std::cout << "Error in input! Int out of range" << std::endl;
	}
	else if (param.find(".") != std::string::npos && param.find("f") == std::string::npos)
	{
		for (size_t i = 0; i < param.length(); i++)
		{
			if (i == 0 && param[i] == '-')
				i = 0;
			else if (!isdigit(param[i]) && param[i] != '.')
			{
				std::cout << "Error! Literal is incorrect" << std::endl;
				return ;
			}
		}
		printDouble(std::atof(param.c_str()));
	}
	else if (param.find(".") != std::string::npos && param.find("f") != std::string::npos)
	{
		for (size_t i = 0; i < param.length(); i++)
		{
			if (i == 0 && param[i] == '-')
				i = 0;
			else if (!isdigit(param[i]) && param[i] != '.' && param[i] != 'f')
			{
				std::cout << "Error! Literal is incorrect" << std::endl;
				return ;
			}
		}
		if (checkFloat(param))
			printFloat(static_cast<float>(std::atof(param.c_str())));
		else
			std::cout << "Error in input! Float out of range" << std::endl;
	}
}
