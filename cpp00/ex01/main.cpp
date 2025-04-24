
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool isValidPhoneNum(std::string numb)
{
	if (numb.length() != 9)
		return (false);
	for (size_t i = 0; i < numb.length(); i++)
	{
		if (isalpha(numb[i]))
			return (false);
		else if(!isalnum(numb[i]))
			return (false);
	}
	return (true);
}

bool is_only_num(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (isalpha(input[i]))
			return (false);
		else if(!isalnum(input[i]))
			return (false);
	}
	return (true);
}


void add(PhoneBook *pb)
{
	std::string fName;
	std::string lName;
	std::string nName;
	std::string number;

	std::cout << "Enter contact first name: ";
	std::getline(std::cin, fName);

	std::cout << "Enter contact last name: ";
	std::getline(std::cin, lName);

	std::cout << "Enter contact nick name: ";
	std::getline(std::cin, nName);

	std::cout << "Enter contact phone: ";
	do
	{
		std::getline(std::cin, number);
		if (!isValidPhoneNum(number))
			std::cout << "Wrong phone number given, need to be only 9 numbers: ";
		else
			break;
	} while (1);

	Contact c(fName, lName, nName, number);
	pb->addContact(c);

	std::cout << "Contact created!!" << std::endl;
}

void search(PhoneBook pb)
{
	std::string	s;
	int		val;

	val = 10;
	if (pb.getManyContact() == 0)
	{
		std::cout << "There are still no contacts added to the Phonebook!" << std::endl;
		return ;
	}

	pb.displayPhoneList();

	do {
		std::cout << "Enter contact index to see more info: ";
		std::getline(std::cin, s);
		if (!is_only_num(s))
			std::cout << "String with something different than numbers!	" << std::endl;
		else
		{
			val = atoi(s.c_str());
			if (val < 0 || val > (pb.getManyContact() - 1))
				std::cout << "Wrong number given!" << pb.getManyContact() << std::endl;
		}
	} while (val < 0 || val > (pb.getManyContact() - 1));
	pb.displayContactInfo(val);
}

int main()
{
	PhoneBook	p1;
	std::string	action;

	std::cout << "------------------------------" << std::endl;
	std::cout << "Welcome to my PhoneBook!!" << std::endl;
	std::cout << "------------------------------" << std::endl;
	do {
		std::cout << "Enter action: ";
		std::getline(std::cin, action);
		if (action == "EXIT")
			return (0);
		else if (action == "ADD")
			add(&p1);
		else if (action == "SEARCH")
			search(p1);
		std::cout << "--------ended while loop--------" << std::endl;
	} while (1);
	return (0);
}
