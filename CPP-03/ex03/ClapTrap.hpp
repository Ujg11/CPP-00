/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:23:49 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/22 17:47:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	//private:
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &ct);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int attack);
		ClapTrap &operator=(const ClapTrap &ct);
		~ClapTrap();
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
		std::string	getName() const;
		int	getHitPoints() const;
		int	getEnergyPoints() const;
		int	getAttackDamage() const;
	
		void setAttack(unsigned int attack);
		void setEnergy(unsigned int energy);
		void setHitPoints(unsigned int hit);
};

#endif
