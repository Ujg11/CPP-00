/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:26:02 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/19 00:26:02 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->__fixedPoint = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

//Copy assignment operator overload
//Se utiliza para asignar el valor de un objeto a otro objeto de la misma clase
Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
	{
		this->__fixedPoint = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return (this->__fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->__fixedPoint = raw;
}
