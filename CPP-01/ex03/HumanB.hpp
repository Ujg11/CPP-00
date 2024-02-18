/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:22 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/18 18:16:44 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_arma; //En este caso no almacenamos una instancia sino la direccion de memoria
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &arma);
};

#endif
//HumanB usa un puntero y permite cambiar dinámicamente la instancia de Weapon 
//durante el tiempo de vida de la instancia de HumanB.
