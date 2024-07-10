/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:09:05 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/10 16:09:05 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>
# include <algorithm>
# include <stack>

class RPN
{
	private:
		std::stack<double> stk;

		bool checkExpression(std::string exp) const;
		bool isCorrectOperator(const char &c) const;

	public:
		RPN();
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &cpy);
		~RPN();

		void calculate(std::string polish);
};

