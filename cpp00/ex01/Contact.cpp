
#include "Contact.hpp"

// getters
std:: string Contact::getFirstName()	{ return (this->firstName); }
std:: string Contact::getLastName()		{ return (this->lastName); }
std:: string Contact::getNickName()		{ return (this->nickName); }
std:: string Contact::getPhone()		{ return (this->phone); }

std::string Contact::toString() {
	return "\n-------Contact-------\nFirst Name: " + this->firstName + "\n" +
			"Last Name: " + this->lastName + "\n" +
			"Nick Name: " + this->nickName + "\n" +
			"Phone: " + this->phone + "\n" +
			"Secret: " + this->secret;
}

bool Contact::equals(Contact other){
	if (firstName == other.getFirstName()
		&& lastName == other.getLastName()
			&& nickName == other.getNickName()
				&& phone == other.getPhone())
		return (true);
	return (false);
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string secret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phone = phone;
	this->secret = secret;
}

Contact::Contact()
{
	this->firstName = NO_DECLARATION;
	this->lastName = NO_DECLARATION;
	this->nickName = NO_DECLARATION;
	this->phone = NO_DECLARATION;
}

Contact::~Contact()
{
}
