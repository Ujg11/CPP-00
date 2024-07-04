/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:32:55 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/04 15:08:23 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T 				*_array;
		unsigned int	_n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &cpy);
		Array &operator=(const Array &cpy);
		T &operator[](unsigned int position);
		~Array();
		unsigned int size() const;
};

# include "Array.tpp"
