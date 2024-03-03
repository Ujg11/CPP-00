/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:10:33 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/26 21:10:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* arrayDogsCats[6];
	int i = 0;

	while (i < 3)
	{
		arrayDogsCats[i] = new Dog(); //se crean con un cerebro
		i++;
	}
	while (i < 6)
	{
		arrayDogsCats[i] = new Cat(); //se crean con un cerebro
		i++;
	}
	i = 0;
	while (i < 6)
	{
		delete arrayDogsCats[i];
		i++;
	}
	std::cout << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;//should not create a leak
	delete cat;

	return 0;
}
