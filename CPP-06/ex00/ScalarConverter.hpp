/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:44:25 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/20 11:44:25 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string> 
# include <climits> //INT_MIN, INT_MAX
# include <cfloat> //FLT_MIN, FLT_MAX
# include <cctype> //std::isdigit, std::isprint
# include <iomanip> //para std::fixed (notació decimal) i std::setprecision

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &cpy);
		~ScalarConverter();

		static bool checkInt(std::string s);
		static bool checkFloat(std::string s);

		static void printChar(char c);
		static void printInt(int i);
		static void printDouble(double d);
		static void printFloat(float f);
		static void printInfinite(std::string param);

	public:
		static void convert(std::string param);
};
