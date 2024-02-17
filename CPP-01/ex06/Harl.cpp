/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:11:52 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/17 16:11:52 by ojimenez         ###   ########.fr       */
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
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain( std::string level )
{
	void	(Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	state[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	for (i = 0; i < state->size(); i++)
	{
		if (level == state[i])
			break;
	}
	switch (i)
	{
		case DEBUG:
			for (int j=i; j < 4; j++)
				(this->*f[j])();
			break;
		case INFO:
			for (int j=i; j < 4; j++)
				(this->*f[j])();
			break;
		case WARNING:
			for (int j=i; j < 4; j++)
				(this->*f[j])();
			break;
		case ERROR:
			for (int j=i; j < 4; j++)
				(this->*f[j])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
