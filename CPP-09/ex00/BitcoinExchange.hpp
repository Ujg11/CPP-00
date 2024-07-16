/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:18:18 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/16 16:55:30 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <algorithm>
# include <string>
# include <cctype>


class BitcoinExchange
{
	private:
		std::map<std::string, double> data;

		bool checkDate(const std::string &date);
		double checkValue(const std::string &val);
		double getValue(std::string date);
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &cpy);
		~BitcoinExchange();

		void openFile(std::string filename);
};

