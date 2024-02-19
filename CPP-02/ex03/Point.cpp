/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:24:37 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/19 16:24:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Constructor por defecto
Point::Point(void): _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

//Destructor
Point::~Point()
{
}

//Constructor de copia
Point::Point(const Point &point)
{
	*this = point;
}

//Sobrecarga del operador de asignación de copia
Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		(Fixed)this->_x = point.getX();
		(Fixed)this->_y = point.getY();
	}
	return (*this);
}

const Fixed &Point::getX(void) const
{
	return (this->_x);
}

const Fixed &Point::getY(void) const
{
	return (this->_y);
}

void Point::setX(Fixed x)
{
    (Fixed)this->_x = x;
}

void Point::setY(Fixed y)
{
    (Fixed)this->_y = y;
}

bool Point::operator==(const Point &other) const
{
	if (this->_x == other.getX() && this->_y == other.getY())
		return (true);
	else
		return (false);
}
