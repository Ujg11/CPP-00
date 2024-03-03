/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:11:25 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/26 21:11:25 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &cpy);
		~Cat();

		void	makeSound() const;
		std::string	getType() const;
};

#endif
