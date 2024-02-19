/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:42:51 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/19 11:42:51 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//Copy assignment operator overload
//Se utiliza para asignar el valor de un objeto a otro objeto de la misma clase
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		this->_fixedPoint = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}

//Constructor that takes a constant integer and converts it to the corresponding fixed-point value
Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = n << this->_fractionalBits;
}

//Constructor que toma un numero de punto flotante y lo convierte al valor de punto fijo
Fixed::Fixed(float const flotante)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(flotante * (1 << this->_fractionalBits));
}

//Per passar de punt fixe a punt flotant fem la operació inversa
float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPoint / (1 << this->_fractionalBits));
}

//Per passar de punt fixe a int fem la operació contraria
int Fixed::toInt( void ) const
{
	return (this->_fixedPoint >> this->_fractionalBits);
}

//Sirve para poder hacer "cout << fixed" e imprimir el valor pasando directamente el objeto
std::ostream &operator<<(std::ostream &ret, const Fixed &fixed)
{
	ret << fixed.toFloat();
	return (ret);
}
