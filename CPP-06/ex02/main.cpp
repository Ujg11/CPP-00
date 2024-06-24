/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:00:57 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/23 18:00:57 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int r;

	r = rand() % 3;
	if (r == 0)
		return (new A());
	else if (r == 1)
		return (new B());
	else
		return (new C());
}

//dynamic_cast<>: para convertir punteros entre tipos en una jerarquia de herencia
void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer to A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer to B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer to C" << std::endl;
	else
		std::cout << "Class hasn't been found" << std::endl;
}

//(void): para no tomar el resultado del dynamic_cast y no de problemas
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference to B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference to C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}	
}

int main(void)
{
	std::srand(std::time(0));

	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = generate();

	std::cout << "Base 1:" << std::endl;
	identify(base1);
	identify(*base1);
	std::cout << std::endl;
	std::cout << "Base 2:" << std::endl;
	identify(base2);
	identify(*base2);
	std::cout << std::endl;
	std::cout << "Base 3:" << std::endl;
	identify(base3);
	identify(*base3);
	std::cout << std::endl;
	std::cout << "Base 4:" << std::endl;
	identify(base4);
	identify(*base4);
	std::cout << std::endl;
}
