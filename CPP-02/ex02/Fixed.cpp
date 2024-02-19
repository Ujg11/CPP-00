/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:00:00 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/19 14:00:00 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void)
{
	this->_fixedPoint = 0;
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
		this->_fixedPoint = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
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
	this->_fixedPoint = n << this->_fractionalBits;
}

//Constructor que toma un numero de punto flotante y lo convierte al valor de punto fijo
Fixed::Fixed(float const flotante)
{
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

// Operaciones de comparacion entre objetos
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPoint > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPoint < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPoint >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPoint <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPoint == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPoint != other.getRawBits());
}

//Operaciones aritmeticas entre objetos que devuelven uno nuevo
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
	
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(void)
{
	this->_fixedPoint++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->_fixedPoint--;
	return (*this);
}

//Devuelve una copia del objeto antes de incrementarlo e incrementa el objeto
Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);
	++(*this); //Llamamos a operator++
	return (cpy);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);
	--(*this); //Llamamos a opertor--
	return (cpy);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	else if (a < b)
		return (a);
	else
		return (a);
	//Tambien: return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (b);
	else if (a < b)
		return (a);
	else
		return (a);
	//Tambien: return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	else
		return (a);
	//Tambien: return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	else
		return (a);
	//Tambien: return (a > b ? a : b);
}
