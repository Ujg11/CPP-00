/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:43:44 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/27 17:43:44 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> vector;
	int				pos;

	vector.push_back(3);
	vector.push_back(8);
	vector.push_back(42);
	try
	{
		pos = easyfind(vector, 3);
		std::cout << "La posicion es: " << pos << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		pos = easyfind(vector, 5);
		std::cout << "La posicion es: " << pos << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

