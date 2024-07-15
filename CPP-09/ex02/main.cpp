/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:32 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/10 17:32:32 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int argc, char *argv[])
{
	PMergeMe pm;
	std::vector<std::string> nums;

	if (argc < 2)
	{
		std::cout << "Error! Positive numbers needed" << std::endl;
		return (1); 
	}
	for (int i = 1; i < argc; ++i)
	{
		nums.push_back(std::string(argv[i]));
	}
	pm.merge((int)nums.size(), nums.data());

	return 0;
}
