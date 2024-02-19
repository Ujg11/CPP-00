/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:24:49 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/19 16:24:49 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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
	Point	ab;
	Point	ac;
	bool	oTriangulo;
	bool	in;

	if (point == a || point == b || point == c)
		return (false);

	oTriangulo = orientacionTriangulo(a, b, c);
	bool orientacion1 = orientacionTriangulo(point, a, b);
	bool orientacion2 = orientacionTriangulo(point, b, c);
	bool orientacion3 = orientacionTriangulo(point, c, a);

	if ((orientacion1 && orientacion2 && orientacion3) || (!orientacion1 && !orientacion2 && !orientacion3))
		in = true;
	else
		in = false;
	return (in);
}
