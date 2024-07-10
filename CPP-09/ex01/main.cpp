/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:18:49 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/10 17:18:49 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error! Invalid or ausent expression" << std::endl;
		return (1);
	}
	RPN rpn;

	rpn.calculate(argv[1]);
	return (0);
}