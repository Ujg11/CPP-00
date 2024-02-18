/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:31:17 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/18 18:03:09 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	N = 10;
	Zombie* horde;

	horde = zombieHorde(N, "Paco");
	for (int i=0; i<N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
