/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:10:46 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/07 12:05:16 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &cpy);
		Animal &operator=(const Animal &cpy);
		virtual ~Animal(); //Para que tambien se llame al destructor de las clases derivadas

		virtual void	makeSound() const = 0; //funcio virtual pura ---> classe abstracta
		std::string	getType() const;
};

#endif
