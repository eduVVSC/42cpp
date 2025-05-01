#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact		contactList[8];
	static int	manyContactsAdded;

	std::string	getPrintableName(std::string toPrint);
public:
	PhoneBook();
	~PhoneBook();

	void	addContact(Contact newContact);
	void	displayPhoneList();
	void	displayContactInfo(int which);
	int		getManyContact();
};

#endif
