/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:03:20 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/13 12:55:19 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "phonebook.h"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_size;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	displayPhoneBookContact(int index);
};

#endif
