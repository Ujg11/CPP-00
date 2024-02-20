/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:24:49 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/20 13:33:50 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	orientacionTriangulo(Point const &a, Point const &b, Point const &c)
{
	Fixed	normal;

	normal = ((b.getX().toFloat() - a.getX().toFloat()) * (c.getY().toFloat() - a.getY().toFloat()))
			- ((b.getY().toFloat() - a.getY().toFloat()) * (c.getX().toFloat() - a.getX().toFloat()));

	/*normal = ((b.getX() - a.getX()) * (c.getY() - a.getY()))
			- ((b.getY() - a.getY()) * (c.getX() - a.getX()));*/

	if (normal.toFloat() > 0.0)
		return (1);
	else if (normal.toFloat() < 0.0)
		return (-1);
	else
		return (0);
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	bool	in;

	if (point == a || point == b || point == c)
		return (false);

	//nt oTriangulo = orientacionTriangulo(a, b, c);
	int orientacion1 = orientacionTriangulo(point, a, b);
	int orientacion2 = orientacionTriangulo(point, b, c);
	int orientacion3 = orientacionTriangulo(point, c, a);

	if (orientacion1 == orientacion2 && orientacion2 == orientacion3 && orientacion1 != 0)
		in = true;
	else
		in = false;
	return (in);
}
