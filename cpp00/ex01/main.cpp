
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool isValidPhoneNum(std::string numb)
{
	if (numb.length() != 9)
		return (false);
	for (size_t i = 0; i < numb.length(); i++)
	{
		if (numb.at(i) > '9' || numb.at(i) < '0')
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

bool add(PhoneBook *pb)
{
	std::string fName;
	std::string lName;
	std::string nName;
	std::string number;
	std::string secret;

	while (1)
	{
		std::cout << "Enter contact first name: ";
		if (!std::getline(std::cin, fName))
		{
			if (std::cin.eof())
				return (false);
		}
		if (!fName.empty() && (fName != "\n"))
			break ;
	}

	while (1)
	{
		std::cout << "Enter contact last name: ";
		if (!std::getline(std::cin, lName))
		{
			if (std::cin.eof())
				return (false);
		}
		if (!lName.empty() && (lName != "\n"))
			break ;
	}

	while (1)
	{
		std::cout << "Enter contact nick name: ";
		if (!std::getline(std::cin, nName))
		{
			if (std::cin.eof())
				return (false);
		}
		if (!nName.empty() && (nName != "\n"))
			break ;
	}

	std::cout << "Enter contact phone: ";
	while (1)
	{
		if (!std::getline(std::cin, number))
		{
			if (std::cin.eof())
				return (false);
		}
		if (number.empty() || !isValidPhoneNum(number))
			std::cout << "Wrong phone number given, need to be only 9 numbers: ";
		else
			break;
	}

	while (1)
	{
		std::cout << "Enter contact secret: ";
		if (!std::getline(std::cin, secret))
		{
			if (std::cin.eof())
				return (false);
		}
		if (!secret.empty() && (secret != "\n"))
			break ;
	}

	Contact c(fName, lName, nName, number, secret);
	pb->addContact(c);

	std::cout << "Contact created!!" << std::endl;
	return (true);
}

bool search(PhoneBook pb)
{
	std::string	s;
	int		val;

	val = 10;
	if (pb.getManyContact() == 0)
	{
		std::cout << "There are still no contacts added to the Phonebook!" << std::endl;
		return (true);
	}

	pb.displayPhoneList();

	do {
		std::cout << "Enter contact index to see more info: ";
		if (!std::getline(std::cin, s))
		{
			if (std::cin.eof())
				return (false);
		}
		if (!is_only_num(s))
			std::cout << "String with something different than numbers!" << std::endl;
		else
		{
			val = atoi(s.c_str());
			if (val < 0 || val > (pb.getManyContact() - 1))
				std::cout << "Wrong number given!" << std::endl;
		}
	} while (val < 0 || val > (pb.getManyContact() - 1));
	pb.displayContactInfo(val);
	return (true);
}

int main()
{
	PhoneBook	pb;
	std::string	action;

	std::cout << "------------------------------" << std::endl;
	std::cout << "Welcome to my PhoneBook!!" << std::endl;
	std::cout << "------------------------------" << std::endl;
	/*Contact c1("aaaa", "aaaa", "aaaa", "123123123", "aaaa");
	Contact c2("bbbbb", "bbbbb", "bbbbb", "123123123", "bbbbb");
	Contact c3("ccccc", "ccccc", "ccccc", "123123123", "ccccc");
	for (size_t i = 0; i < 8; i++)
	{
		pb.addContact(c1);
	}
	pb.displayPhoneList();
	pb.addContact(c2);
	pb.displayPhoneList();
	pb.addContact(c3);
	pb.displayPhoneList();
	pb.displayContactInfo(1); */

	do {
		std::cout << "Enter action: ";
		if (!std::getline(std::cin, action))
		{
			if (std::cin.eof())
				return (1);
			std::cin.clear();
		}
		if (action == "EXIT")
			return (0);
		else if (action == "ADD")
		{
			if (!add(&pb))
				return (1);
		}
		else if (action == "SEARCH")
		{
			if (!search(pb))
					return (1);
		}
	} while (1);
	return (0);
}
