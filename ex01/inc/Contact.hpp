/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:03:10 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/13 12:12:20 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "phonebook.h"

class	Contact
{
	private:
		std::string _firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact();
		~Contact();
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNikname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string getNikname(void) const;
		std::string getPhone(void) const;
		std::string	getDarkestSecret(void) const;

		void	displayContact(void) const;
};

#endif
