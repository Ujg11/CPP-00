/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:19 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/16 18:50:50 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
	this->vec = new std::vector<int>;
	this->que = new std::deque<int>;
}

PMergeMe::PMergeMe(const PMergeMe &cpy)
{
	*this = cpy;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &cpy)
{
	if (this != &cpy)
	{
		this->vec = cpy.vec;
		this->que = cpy.que;
	}
	return (*this);
}

PMergeMe::~PMergeMe()
{
	delete this->vec;
	delete this->que;
}

bool PMergeMe::checkNums(const std::string nums) const
{
	for (size_t i = 0; i < nums.length(); i++)
	{
		if (!isdigit(nums[i]) && !isspace(nums[i]))
		{
			return (false);
		}
	}
	return (true);
}

void PMergeMe::printVector()
{
	for (size_t i = 0; i < vec->size(); i++)
	{
		if (i < 4 && vec->size() > 5)
			std::cout << " " << (*vec)[i];
		else if (vec->size() > 5)
		{
			std::cout << " [...]";
			break ;
		}
		else if (i < 5 && vec->size() <= 5)
		{
			std::cout << " " << (*vec)[i];
		}
	}
	std::cout << std::endl;
}

void PMergeMe::printDeque()
{
	for (size_t i = 0; i < que->size(); i++)
	{
		if (i < 4 && que->size() > 5)
			std::cout << " " << (*que)[i];
		else if (que->size() > 5)
		{
			std::cout << " [...]";
			break ;
		}
		else if (i < 5 && que->size() <= 5)
		{
			std::cout << " " << (*que)[i];
		}
	}
	std::cout << std::endl;
}

bool PMergeMe::checkRepeated()
{
	for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); ++i)
	{
		if (*i < 0)
		{
			std::cout << "Error: negative number" << std::endl;
			return (false);
		}
		for (std::vector<int>::iterator j = vec->begin(); j != vec->end(); ++j)
		{
			if (j != i && *i == *j)
			{
				std::cout << "Error: number repeated" << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

void PMergeMe::mergeVector(int left, int right)
{
	std::vector<int> aux;
	int i;
	int j;

	if (right - left > 1)
	{
		int mid = left + (right - left) / 2;
		mergeVector(left, mid);
		mergeVector(mid, right);
		i = left;
		j = mid;
		while (i < mid && j < right)
		{
			if ((*vec)[i] < (*vec)[j])
			{
				aux.push_back((*vec)[i]);
				i++;
			}
			else
			{
				aux.push_back((*vec)[j]);
				j++;
			}
		}
		while (i < mid)
		{
			aux.push_back((*vec)[i]);
			i++;
		}
		while (j < right)
		{
			aux.push_back((*vec)[j]);
			j++;
		}
		for (int k = left; k < right; ++k)
		{
			(*vec)[k] = aux[k - left];
		}
	}
	else if (right - left == 2)
	{
		if ((*vec)[left] > (*vec)[left + 1])
			std::swap((*vec)[left], (*vec)[left + 1]);
	}
}

void PMergeMe::mergeDeque(int left, int right)
{
	std::deque<int> aux;
	int i;
	int j;

	
	if (right - left > 1)
	{
		int mid = left + (right - left) / 2;
		mergeDeque(left, mid);
		mergeDeque(mid, right);
		i = left;
		j = mid;
		while (i < mid && j < right)
		{
			if ((*que)[i] < (*que)[j])
			{
				aux.push_back((*que)[i]);
				i++;
			}
			else
			{
				aux.push_back((*que)[j]);
				j++;
			}
		}
		while (i < mid)
		{
			aux.push_back((*que)[i]);
			i++;
		}
		while (j < right)
		{
			aux.push_back((*que)[j]);
			j++;
		}
		for (int k = left; k < right; ++k)
		{
			(*que)[k] = aux[k - left];
		}
	}
	else if (right - left == 2)
	{
		if ((*que)[left] > (*que)[left + 1])
			std::swap((*que)[left], (*que)[left + 1]);
	}
}

void PMergeMe::merge(int args, std::string nums[])
{
	int num = 0;

	for (int i = 0; i < args; i++)
	{
		if (!checkNums(nums[i]))
		{
			std::cout << "Error: bad input" << std::endl;
			return ;
		}
		num = std::atoi(nums[i].c_str());
		this->vec->push_back(num);
		this->que->push_back(num);
	}
	if (!checkRepeated())
		return ;
	std::cout << "Before: ";
	printVector();
	std::clock_t startMergeVector = std::clock();
	mergeVector(0, (int)vec->size());
	std::clock_t endMergeVector = std::clock();
	double durationVector = 1000000 * (endMergeVector - startMergeVector) / CLOCKS_PER_SEC;
	std::clock_t startMergeDeque = std::clock();
	mergeDeque(0, (int)que->size());
	std::clock_t endMergeDeque = std::clock();
	double durationDeque = 1000000 * (endMergeDeque - startMergeDeque) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	printDeque();
	std::cout << std::fixed;
	std::cout << "Time to process a range of " << this->vec->size() << " elements whith std::vector<int> : " << durationVector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->que->size() << " elements whith std::deque<int> : " << durationDeque << " us" << std::endl;
}
