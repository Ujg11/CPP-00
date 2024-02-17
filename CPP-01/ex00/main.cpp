/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:30:09 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/17 14:30:09 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *UriEnMemoria;
	std::string zombies[5] = {"Uri", "Foo", "Poo", "Juan", "Miriam"};

	UriEnMemoria = newZombie("UriEnMemoria");
	UriEnMemoria->announce();
	delete UriEnMemoria;
	for (int i=0; i<5; i++)
	{
		randomChump(zombies[i]);
	}
	return (0);
}