/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:18:10 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/16 17:05:26 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream   infile("data.csv");
	std::string     line;
	std::string		date;
	double			price;

	if (!infile.is_open())
	{
		std::cout << "Error: could not open data file." << std::endl;
		return ;
	}
	std::getline(infile, line);//first line is raw
	while (std::getline(infile, line))
	{
		std::string::size_type pos = line.find(",");
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			price = std::atof(line.substr(pos + 1).c_str());
			this->data[date] = price;
		}
	}
	infile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
	{
		this->data = cpy.data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::checkDate(const std::string &date)
{
	int	year;
	int	month;
	int	day;

	if (date[4] != '-' || date[7] != '-' || date.length() != 10)
		return (false);
	for (size_t i = 0; i < date.length(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			return (false);
	}
	year = std::atoi(date.substr(0, 4).c_str());
	if (year < 2009 || year > 2022)
		return (false);
	month = std::atoi(date.substr(6, 2).c_str());
	if (month < 0 || month > 12)
		return (false);
	day = std::atoi(date.substr(9, 2).c_str());
	if (day < 0 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return (false);
	if (month == 2)
	{
		if ((year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) && day > 28)
			return false;
		else if (day > 29)
			return false;
	}
	return (true);
}

double BitcoinExchange::checkValue(const std::string &val)
{
	double value = -1;

	for (size_t i = 0; i < val.length(); i++)
	{
		if (!isdigit(val[i]) && val[0] != '-' && val[i] != '.')
		{
			std::cout << "Error: bad input in the value, only numbers between 0 and 1000" << std::endl;
			return (-1);
		}
	}
	value = std::atof(val.c_str());
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (-1);
	}
	return (value);
}

void BitcoinExchange::openFile(std::string filename)
{
	std::ifstream   infile(filename.c_str());
	std::string     line;
	std::string		date;
	double			value;
	double			bitcoins;

	if (!infile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	std::getline(infile, line);//first line is raw
	while (std::getline(infile, line))
	{
		std::string::size_type pipe = line.find("|");
		if (pipe != std::string::npos)
		{
			if (line[pipe - 1] != ' ' || line[pipe + 1] != ' ')
				std::cout << "Error: bad input => " << line << std::endl;
			else
			{
				line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
				pipe = line.find("|");
				if (!checkDate(line.substr(0, pipe)))
					std::cout << "Error: bad input => " << line.substr(0, pipe) << std::endl;
				else
				{
					date = line.substr(0, pipe);
					bitcoins = checkValue(line.substr(pipe + 1));
					if (bitcoins != -1)
					{
						value = bitcoins * getValue(date);
						if (value >= 0)
							std::cout << date << " => " << bitcoins << " = " << value << std::endl;
					}
				}
			}
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
	infile.close();
}

double BitcoinExchange::getValue(std::string date)
{
	std::map<std::string, double>::const_iterator it = this->data.find(date);
	if (it != this->data.end())
	{
		return (it->second);
	}
	it = this->data.lower_bound(date);
	if (it == this->data.begin())
	{
		std::cout << "Error: no data for this date" << std::endl;
		return (-1);
	}
	else if (it == this->data.end() || it->first != date)
		--it;
	return it->second;
}
