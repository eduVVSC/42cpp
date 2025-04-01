
#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact newContact)
{
	if (manyContactsAdded >= 8)
	{
		while (manyContactsAdded >= 8)
			manyContactsAdded -= 8;
		contactList[manyContactsAdded] = newContact;
	}
	else
	{
		contactList[manyContactsAdded] = newContact;
	}
	manyContactsAdded++;
}
int PhoneBook::manyContactsAdded = 0;

void PhoneBook::displayContactInfo(int which)
{
	std::cout << contactList[which].toString() << std::endl;
}

void PhoneBook::displayPhoneList(){
	std::cout << std::string(50, '-') << std::endl;
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
			  << std::setw(10) << "Last Name" << " | "
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(50, '-') << std::endl;

	// change the substr function to your own to properly handle the way that it wants it to be printed
	for (size_t i = 0; i < (size_t)manyContactsAdded; i++)
	{
		std::cout << std::setw(10) << i << " | "
				  << std::setw(10) << contactList[i].getFirstName().substr(0, 9) << " | "
				  << std::setw(10) << contactList[i].getLastName().substr(0, 9) << " | "
				  << std::setw(10) << contactList[i].getNickName().substr(0, 9) << " | " << std::endl;
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

