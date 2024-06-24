/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:41:44 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/24 16:41:44 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void incrementInt(int &i)
{
	i++;
}

void printString(std::string &s)
{
	std::cout << s << std::endl;
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	std::string s[] = {"hola", "que", "tal"};

	iter(a, sizeof(a), incrementInt);
	std::cout << "a = { " << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3] << ", " << a[4] << "}" << std::endl << std::endl;
	iter(s, 3, printString);
}
