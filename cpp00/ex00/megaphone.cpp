
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for (size_t i = 1; i < ac; i++)
			std::cout << av[i];
	return (0);
}

