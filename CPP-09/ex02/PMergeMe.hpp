/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:26 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/16 18:00:24 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <algorithm>
# include <cstdlib>

class PMergeMe
{
	private:
		std::vector<int> *vec;
		std::deque<int> *que;

		bool checkNums(const std::string nums) const;
		bool checkRepeated();
		void printVector();
		void printDeque();
		void mergeVector(int left, int right);
		void mergeDeque(int left, int right);

	public:
		PMergeMe();
		PMergeMe(const PMergeMe &cpy);
		PMergeMe &operator=(const PMergeMe &cpy);
		~PMergeMe();

		void merge(int args, std::string nums[]);
};


