/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:32:55 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/25 19:49:41 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
class Array
{
	private:
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &cpy);
		Array &operator=(const Array &cpy);
		Array &operator[]();
		~Array();
};

# include "Array.tpp"


