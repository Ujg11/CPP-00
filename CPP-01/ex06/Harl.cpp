/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:11:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 19:47:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.";
	std::cout << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}

void Harl::complain( std::string level )
{
	std::string	state[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t i = 0;

	if (!level.empty())
	{
		for (i = 0; i < state->size() - 1; i++)
		{
			if (level.compare(state[i]) == 0)
				break;
		}
		switch (i)
		{
			case DEBUG:
				Harl::debug();
			case INFO:
				Harl::info();
			case WARNING:
				Harl::warning();
			case ERROR:
				Harl::error();
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
