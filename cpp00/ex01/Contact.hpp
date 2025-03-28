#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <array>

class Contact
{
	private:
		std::string	name2;
		char				*name;
		char				*phone;
		static int			countPeople;
		static Contact	arrayContacts[9];
	public:
		// Constructor
		Contact(char *name, char *phone);
		Contact();

		// Destructor
		~Contact();

		// Methods
		void	search(char *name);
		char	*getName();
		char	*getNum();
};

#endif
