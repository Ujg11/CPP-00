#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "phonebook.h"

class PhoneBook
{
	private:
		Contact _list[8];
		int		size;
	public:
		PhoneBook(/* args */);
		~PhoneBook();
};

PhoneBook::PhoneBook(/* args */)
{
}
PhoneBook::~PhoneBook()
{
}


#endif