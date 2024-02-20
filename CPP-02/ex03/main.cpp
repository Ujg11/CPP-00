/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:23:43 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/20 13:34:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point const	p1(0.0f, 0.0f);
	Point const	p2(0.0f, 2.0f);
	Point const	p3(5.0f, 0.0f);

	Point	point(5.0f, 10.5f); //fuera
	//Point point(2.0f, 1.0f); //Dentro
	//Point point(1.0, 1.0); //Dentro
	//Point point(p3); //En una punta
	//Point point(0.0f, 1.0f); //en la linea del contorno


	if (bsp(p1, p2, p3, point))
	{
		std::cout << "El punto esta dentro" << std::endl << std::endl;
	}
	else
		std::cout << "El punto esta fuera" << std::endl << std::endl;
	return (0);
}
