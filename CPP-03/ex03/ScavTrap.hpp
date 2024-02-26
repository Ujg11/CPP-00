/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:27 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 17:52:41 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
	private:
		bool	_guardGate;
		
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &st);
		ScavTrap &operator=(const ScavTrap &st);
		~ScavTrap();
		void	attack(const std::string& target);
	
		void	guardGate();
		bool	getGuardGate() const;

		static const unsigned int STHhit = 100;
		static const unsigned int STEnergy = 50;
		static const unsigned int STAttack = 20;
};


#endif
