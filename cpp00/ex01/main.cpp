
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook p1;
	Contact c1("Eduardo", "Vasconcelos", "duds", "912232513");
	Contact c2("Henri", "Courie", "hanrita", "912445245");

	std::cout << c1.toString() << std::endl;
	std::cout << c2.toString() << std::endl;
	std::cout << c1.equals(c2) << std::endl;

	std::cout << "bf contact 1" << std::endl;
	p1.addContact(c1);
	std::cout << "bf contact 2" << std::endl;
	p1.addContact(c2);
	std::cout << "bf contact 1" << std::endl;
	p1.addContact(c1);
	std::cout << "bf contact 2" << std::endl;
	p1.addContact(c2);
	p1.addContact(c1);
	std::cout << "bf contact 2" << std::endl;
	p1.addContact(c2);
	p1.addContact(c1);
	std::cout << "bf contact 2" << std::endl;
	p1.addContact(c2);
	p1.displayPhoneList();
	p1.addContact(c2);
	p1.displayPhoneList();
}
