#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>

# define NO_DECLARATION "Not declarated!"

class Contact
{
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		secret;
		std::string		phone;
	public:
		// Constructor
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string secret);
		Contact();

		// Destructor
		~Contact();

		// Methods
		std:: string getFirstName();
		std:: string getLastName();
		std:: string getNickName();
		std:: string getSecret();
		std:: string getPhone();

		std::string toString();

		bool equals(Contact other);
};

#endif
