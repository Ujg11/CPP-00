/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:31:29 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/20 12:10:27 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class  Zombie
{
	private:
		std::string _name;

	public:
		 Zombie(void);
		~ Zombie(void);
		void announce(void);
		void setName(std::string name);
		std::string getName(void) const;
};

Zombie* zombieHorde( int N, std::string name );

#endif
