#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <string>

# define NO_DECLARATION "Not declarated!"

class Contact
{
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		phone;
	public:
		// Constructor
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone);
		Contact();

		// Destructor
		~Contact();

		// Methods
		std:: string getFirstName();
		std:: string getLastName();
		std:: string getNickName();
		std:: string getPhone();

		std::string toString();

		bool equals(Contact other);
};

#endif
