
#include "PmergeMe.hpp"

void PmergeMe::displayValues(std::list<int> val)
{
	for (std::list<int>::iterator it = val.begin(); it != val.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

std::vector<int> PmergeMe::execVecAlgorithmHelper(std::vector<int> &c, std::vector<std::vector<int>> a)
{
	if (a.empty())
		return (c);

	std::vector<int> duo1 = a.front();	a.pop_front();
	std::vector<int> duo2 = a.front();	a.pop_front(); // add validation

	// * 1 - insert the first element of the next duo
	c.push_back(duo1.front()); duo1.pop_front(); // adding duo1 greatest - duo1 only has the smallest value now
	// * 2 - insert the second element of the 2nd closest duo
	insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 smallest - duo 2 only have the greatest value now
	// * 3 - insert the second element of the closest duo
	insertList(c, duo1.back()); duo1.pop_back(); // adding duo1 smallest - duo 1 is empty
	// * 3 - insert the first(remaining) element of the 2nd closest duo
	insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 greatest - duo 2 is empty
	execListAlgorithmHelper(c, a); // recursive call to the algorithm
}

/**
 * @brief Start the vector with the three numbers(a0,b0 and a1) and call the recursive
 * function to execute the algorithm
 *
 * @param num with the numbers entered by the user
 * @return list with sorted numbers
 */
std::vector<int> PmergeMe::execVecAlgorithm(std::list<int> num)
{
	std::vector< std::vector<int> >  a;
	std::vector< int >  c;

	populate(&a, num);
	// ! deal with odd number here, separate it to go into
	// ! the recursvie method withtout it
	if (a.size() > 2)
	{
		std::list<int> addToMain = a.front();
		a.pop_front();
		c.push_front(a.front());
		addToMain.pop_front();
		c.push_front(a.front());
		addToMain.pop_front(); 		//  c = b0 - a0
	}
	execListAlgorithmHelper(&c, a);
	return (c);
}

std::list<int> PmergeMe::execListAlgorithmHelper(std::list<int> *c, std::list<std::list<int>> a)
{
	if (a.empty())
		return (*c);

	std::list<int> duo1 = a.front();	a.pop_front();
	std::list<int> duo2 = a.front();	a.pop_front(); // add validation

	// * 1 - insert the first element of the next duo
	c->push_back(duo1.front()); duo1.pop_front(); // adding duo1 greatest - duo1 only has the smallest value now
	// * 2 - insert the second element of the 2nd closest duo
	insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 smallest - duo 2 only have the greatest value now
	// * 3 - insert the second element of the closest duo
	insertList(c, duo1.back()); duo1.pop_back(); // adding duo1 smallest - duo 1 is empty
	// * 3 - insert the first(remaining) element of the 2nd closest duo
	insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 greatest - duo 2 is empty
	execListAlgorithmHelper(c, a); // recursive call to the algorithm
}

/**
 * @brief Start the list with the three numbers(a0,b0 and a1) and call the recursive
 * function to execute the algorithm
 *
 * @param num with the numbers entered by the user
 * @return list with sorted numbers
 */
std::list<int> PmergeMe::execListAlgorithm(std::list<int> num)
{
	std::list< std::list<int> >  a;
	std::list< int >  odd;
	std::list< int >  c;
	
	populate(&a, num);
	// ! sort a

	if (a.back().size() == 1)
	{
		odd = a.back();	
		a.pop_back();
	}	
	if (a.size() > 2)
	{
		std::list<int> addToMain = a.front();
		a.pop_front();
		c.push_front(addToMain.front()); 	// a0 
		c.push_front(addToMain.back()); 	// b0 
	}
	//  c = [b0 - a0]
	// ! need to add the a1 an then go to function 
	execListAlgorithmHelper(&c, a);
	return (c);
}

PmergeMe::PmergeMe(std::list<int> num)
{
	time_t startTime;
	time_t endTime;

	displayValues(num);
	startTime = time(NULL);

}


PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { }

PmergeMe::~PmergeMe() {}
