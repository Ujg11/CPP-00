/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:33:25 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/27 11:23:31 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl ha aparecido!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl se va!" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "DEBUG -> ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO -> ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING -> ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout << "years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR -> ";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

//Creem un array de punteros a funcions void que no tenen parametres.
//Assignem a cada lloc del array la funció que volem de Harl
void Harl::complain( std::string level )
{
	void	(Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	state[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	if (!level.empty())
	{
		for (size_t i = 0; i < state->size() - 1; i++)
		{
			if (level == state[i])
			{
				(this->*f[i])(); //cridem a la funció en concret
				return ;
			}
		}
	}
	std::cout << "Nivel no encontrado, pruebe otra vez" << std::endl;
}
