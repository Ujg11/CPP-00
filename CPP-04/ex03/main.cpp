/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:56:41 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/14 18:38:12 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include <iostream>

/*int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	me->unequip(0);
	delete bob;
	delete me;
	delete src;

	return 0;
}*/

int main( void )
{
	IMateriaSource* creadorMaterial = new MateriaSource();
	AMateria* gel = new Ice();
	AMateria* cura = new Cure();
	
	std::cout << std::endl;
	creadorMaterial->learnMateria(gel);
	creadorMaterial->learnMateria(gel);
	creadorMaterial->learnMateria(cura);
	creadorMaterial->learnMateria(cura);

	std::cout << std::endl;
	Character* uri = new Character("Uri");
	std::cout << std::endl;
	uri->equip(creadorMaterial->createMateria("ice"));
	uri->equip(creadorMaterial->createMateria("cure"));
	uri->equip(creadorMaterial->createMateria("cure"));
	uri->equip(creadorMaterial->createMateria("ice"));
	
	std::cout << std::endl;
	AMateria* gel2 = new Ice();
	uri->equip(gel2); //The Uri inventory is full
	delete gel2;
	
	std::cout << std::endl;

	Character* target = new Character("target");
	
	std::cout << std::endl;
	uri->use(0, *target);
	uri->use(2, *target);
	std::cout << std::endl;
	uri->unequip(3);
	uri->unequip(2);
	std::cout << std::endl;
	uri->use(2, *target); //No Materia to use :(
	std::cout << std::endl;
	
	delete gel;
	delete cura;
	delete creadorMaterial;
	delete uri;
	delete target;
}
