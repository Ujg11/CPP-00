/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:56:41 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/05 14:31:07 by ojimenez         ###   ########.fr       */
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
	std::cout << "1. Creating MateriaSource" << std::endl; 
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "2. \"src\" learning 5 materias" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		std::cout << std::endl;
		Ice	*mat = new Ice();
		src->learnMateria(mat);
		delete	mat;

		// std::cout << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "3. Creating Character \"vilma\" and \"oktorok\"" << std::endl;
		Character* vilma = new Character("vilma");
		std::cout << std::endl;

		Character* oktorok = new Character("oktorok");
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia" << std::endl;
		vilma->equip(NULL);
		
		AMateria* tmp;

		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		std::cout << &tmp << std::endl;

		tmp = src->createMateria("cure");
		vilma->equip(tmp);
		tmp = src->createMateria("cure");
		vilma->equip(tmp);
		tmp = src->createMateria("ice");
		vilma->equip(tmp);

		std::cout << std::endl;

		std::cout << std::endl;
		tmp = src->createMateria("ice"); //esto lo pongo yo
		oktorok->equip(tmp);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "5. Testing Character Assignation overload \"vilma = oktorok\" for deep copy and changed vilma afterwards" << std::endl;	
		*oktorok = *vilma;
		
		vilma->unequip(0);
		std::cout << "VILMA" << std::endl;
		std::cout << std::endl;

		std::cout << "OKTOROK" << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "6. Testing character copy constructor for deep copy \"stardust = Character(vilma)\" and changed vilma afterwards" << std::endl;
		
		Character* stardust = new Character(*vilma);

		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		std::cout << "VILMA" << std::endl;
		std::cout << std::endl;

		std::cout << "STARDUST" << std::endl;


	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	
	std::cout << "7. \"vilma\" using all equiped materias on \"oktorok\" " << std::endl;
		vilma->use(0, *oktorok);
		vilma->use(1, *oktorok);
		vilma->use(2, *oktorok);
		vilma->use(3, *oktorok);
		vilma->use(10, *oktorok);
		vilma->use(-1, *oktorok);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "8. \"vilma\" trying to use unequiped materias on \"oktorok\" " << std::endl;
		vilma->unequip(0);
		vilma->use(0, *oktorok);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "9. New character \"lucifer\" equipping and unequipping materias" << std::endl;
		ICharacter* lucifer = new Character("lucifer");
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;
		

		lucifer->equip(cure);
		lucifer->equip(ice);
		
		lucifer->unequip(0);
		lucifer->unequip(1);
		lucifer->unequip(2);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "10. Testing if unequiped materia is freed" << std::endl;

		ICharacter* test = new Character("test");
		
		tmp = src->createMateria("ice");
		test->equip(tmp);
		test->unequip(0);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	std::cout << "11. Deleting \"vilma\", \"oktorok\", \"stardust\" and \"lucifer\"" << std::endl;
	
	delete test;
	delete lucifer;
	delete stardust;
	delete oktorok;
	delete vilma;
	delete src;

	return (0);
}
