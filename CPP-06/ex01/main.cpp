/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:24:14 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/23 16:24:14 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data d;
	uintptr_t puntero;
	Data *d2;

	d.c = 'a';
	d.number = 42;
	d.s = "42barcelona";

	puntero = Serializer::serialize(&d);
	std::cout << "Puntero a Data convertido a uintptr_t de valor: " << puntero << std::endl << std::endl;
	std::cout << "Volvemos a obtener el puntero a Data con deserialize" << std::endl;
	d2 = Serializer::deserialize(puntero);
	std::cout << "Valores de Data:" << std::endl;
	std::cout << "c = " << d2->c << ", number = " << d2->number << " i s = " << d2->s << std::endl;
}
