
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool isValidPhoneNum(std::string numb)
{
	if (numb.length() != 9)
		return (false);
	for (size_t i = 0; i < numb.length(); i++)
	{
		if (isalpha(numb[i]))
		{
			std::cout << "going out here 1\n";
			return (false);
		}
		else if(!isalnum(numb[i]))
		{
			std::cout << "going out here 2\n";
			return (false);
		}
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
			std::cout << "Wrong phone number given, needs to have only numbers and 9 numbers without spaces." << std::endl;
		else
			break;
	} while (1);

	Contact c(fName, lName, nName, number);
	pb->addContact(c);

	std::cout << "Contact created!!" << std::endl;
}

void search(PhoneBook pb)
{
	int		val;

	if (pb.getManyContact() == 0)
	{
		std::cout << "There are still no contacts added to the Phonebook!" << std::endl;
		return ;
	}
	pb.displayPhoneList();
	do
	{
		std::cout << "Enter contact index to see more info: ";
		std::cin >> val;
		if (val > pb.getManyContact() || val < pb.getManyContact())
			std::cout << "Wrong number given, need to be between 0 and 7! Try again." << std::endl;
	} while (val < pb.getManyContact() || val > pb.getManyContact());
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
	} while (1);
	return (0);
}
