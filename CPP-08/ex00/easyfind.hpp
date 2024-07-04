/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:45:48 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/04 16:38:32 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <stdexcept>

template <typename T>
int	easyfind(T const &container, int val)
{
	typename T::const_iterator it;
	int position;

	it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw std::out_of_range("Value not found");
	position = std::distance(container.begin(), it);
	return (position);
}


