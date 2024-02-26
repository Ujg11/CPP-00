/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:20:32 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/24 13:20:32 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &ft);
		FragTrap &operator=(const FragTrap &ft);
		~FragTrap();

		void highFivesGuys(void);

		static const unsigned int FTHhit = 100;
		static const unsigned int FTEnergy = 100;
		static const unsigned int FTAttack = 30;
};

#endif
