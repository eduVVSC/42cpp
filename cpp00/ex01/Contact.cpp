
#include "Contact.hpp"

class Contact
{
	private:
		
		char				*firstName;
		char				*lastName;
		char				*nickName;
		char				*phone;
	public:
		Contact(char *firstName, char *lastName, char *nickName, char *phone);
		Contact();
		~Contact();

		void search(char *name)
		{
			if (name == nullptr)
			{
				std::cout << "No name was entered to searched"<< std::endl;
				return ;
			}
			for (Contact temp : arrayContacts)
			{
				if (strcmp(temp.getName(), this->name) == 0 )
					std::cout << "Name was found " << std::endl;
			}
		}

		char	*getFirstName()
		{
			return (this->firstName);
		}

		char	*getLastName()
		{
			return (this->lastName);
		}
};

Contact::Contact(char *firstName, char *lastName, char *nickName, char *phone)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phone = phone;
}
Contact::Contact()
{
}


Contact::~Contact()
{
}
