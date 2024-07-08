/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:42:03 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/08 16:55:24 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(42);
	mstack.push(52);
	mstack.push(62);
	mstack.push(72);
	mstack.push(82);
	mstack.push(92);
	mstack.push(102);

	for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	MutantStack<int>::iterator start = mstack.begin();
    ++start;
    --start;
	std::cout << *start << std::endl;
	return (0);
}
