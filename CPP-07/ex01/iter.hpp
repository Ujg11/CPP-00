/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:41:54 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/24 16:41:54 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void iter(T *adress, size_t len, void (*f)(T&))
{
	if (!adress)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		f(adress[i]);
	}
}
