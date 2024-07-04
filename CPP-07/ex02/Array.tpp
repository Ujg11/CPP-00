/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:26:48 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/04 16:03:01 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_array = NULL;
	this->_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_n = n;
	this->_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array &cpy)
{
	this->_n = cpy._n;
	this->_array = new T[cpy._n];
	for (unsigned int i = 0; i < cpy._n; i++)
		this->_array[i] = cpy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &cpy)
{
	if (this != &cpy)
	{
		if (this->_n > 0)
				delete [] this->_array;
		this->_n = cpy->_n;
		this->_array = new T[cpy->_n];
		for (unsigned int i = 0; i < cpy._n; i++)
			this->_array[i] = cpy._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int position)
{
	if (position >= 0 && position < this->_n)
		return (this->_array[position]);
	throw std::range_error("Index out of bounds");
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_n);
}
