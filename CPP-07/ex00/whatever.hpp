/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:14:15 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/23 21:14:15 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T aux;

	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

