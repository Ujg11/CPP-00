/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:42:17 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/30 00:42:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
		}

		MutantStack(const MutantStack &cpy) : std::stack<T>(cpy)
		{
			
		}

		MutantStack &operator=(const MutantStack &cpy)
		{
			if (this != &cpy)
			{
				std::stack<T>::operator=(cpy);
			}
			return (*this);
		}

		~MutantStack()
		{
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}

		iterator end()
		{
			return (std::stack<T>::c.end());
		}
	// c es el contenedor real interno de la clase Container que es miembro protected y podemos acceder a el y aplicarle las funciones que queremos
};

