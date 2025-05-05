
#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact newContact)
{
	int	locationToAdd;

	locationToAdd = manyContactsAdded;
	if (locationToAdd >= 8)
	{
		while (locationToAdd >= 8)
			locationToAdd -= 8;
		contactList[locationToAdd] = newContact;
	}
	else
		contactList[locationToAdd] = newContact;
	manyContactsAdded++;
}
int PhoneBook::manyContactsAdded = 0;

void PhoneBook::displayContactInfo(int which)
{
	std::cout << contactList[which].toString() << std::endl;
}

std::string PhoneBook::getPrintableName(std::string toPrint){
	if (toPrint.length() > 10)
		return (toPrint.substr(0, 9) + ".");
	else
		return (toPrint);
}

void PhoneBook::displayPhoneList(){
	int manyContacts = manyContactsAdded;
	std::cout << std::string(50, '-') << std::endl;
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
			  << std::setw(10) << "Last Name" << " | "
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(50, '-') << std::endl;

	if (manyContacts > 8)
		manyContacts = 8;
	for (size_t i = 0; i < (size_t)manyContacts; i++)
	{
		std::cout << std::setw(10) << i << " | "
				  << std::setw(10) << getPrintableName(contactList[i].getFirstName()) << " | "
				  << std::setw(10) << getPrintableName(contactList[i].getLastName()) << " | "
				  << std::setw(10) << getPrintableName(contactList[i].getNickName()) << " | " << std::endl;
	}
	std::cout << std::string(50, '-') << std::endl;
}

int PhoneBook::getManyContact() { return (manyContactsAdded); }

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

