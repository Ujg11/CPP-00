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


class ScavTrap : public ClapTrap
{
private:
	bool	_guardGate;
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ClapTrap &st);
	ScavTrap &operator=(const ClapTrap &st);
	~ScavTrap();
	void	attack(const std::string& target);

	void guardGate();
};


#endif
