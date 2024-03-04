/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:57:59 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/03 19:57:59 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*_inventory[4];
		std::string _name;
		AMateria	*_trash[10];

	public:
		Character(std::string const name);
		Character(const Character &cpy);
		Character &operator=(const Character &cpy);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void cleanTrash();
		void addTrash(AMateria* m);
};
