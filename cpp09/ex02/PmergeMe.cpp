
#include "PmergeMe.hpp"

void PmergeMe::displayValues(std::list<int> val)
{
	for (std::list<int>::iterator it = val.begin(); it != val.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

void PmergeMe::displayValues(std::list< std::list<int> > val)
{
	for (std::list< std::list<int> >::iterator it = val.begin(); it != val.end(); it++)
	{
		std::cout << (*it).front();
		if ( (*it).back() != (*it).front())
			std::cout << " - " << (*it).back();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int PmergeMe::listAt(std::list<int> l, int index)
{
	std::list<int>::iterator it;
	int	i = 0;

	for (it = l.begin(); it != l.end(); it++)
	{
		if (i == index)
			return (*it);
		i++;
	}
	return (*it); // will never hit here
}

// ====================== Vector algorithm methods ====================== //

std::vector<int> PmergeMe::execVecAlgorithmHelper(std::vector<int> *c, std::vector<std::vector<int> > a)
{
	if (a.empty())
		return (*c);

	// std::vector<int> duo1 = a.front();	a.pop_front();
	// std::vector<int> duo2 = a.front();	a.pop_front(); // add validation

	// // * 1 - insert the first element of the next duo
	// c.push_back(duo1.front()); duo1.pop_front(); // adding duo1 greatest - duo1 only has the smallest value now
	// // * 2 - insert the second element of the 2nd closest duo
	// insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 smallest - duo 2 only have the greatest value now
	// // * 3 - insert the second element of the closest duo
	// insertList(c, duo1.back()); duo1.pop_back(); // adding duo1 smallest - duo 1 is empty
	// // * 3 - insert the first(remaining) element of the 2nd closest duo
	// insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 greatest - duo 2 is empty
	// execListAlgorithmHelper(c, a); // recursive call to the algorithm
	return (*c);
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
	std::vector< int > c;

	(void) num;
	// populate(&a, num);
	// // ! deal with odd number here, separate it to go into
	// // ! the recursvie method withtout it
	// if (a.size() > 2)
	// {
	// 	std::list<int> addToMain = a.front();
	// 	a.pop_front();
	// 	c.push_front(a.front());
	// 	addToMain.pop_front();
	// 	c.push_front(a.front());
	// 	addToMain.pop_front(); 		//  c = b0 - a0
	// }
	// execListAlgorithmHelper(&c, a);
	return (c);
}

// ====================== list algorithm methods ====================== //

std::list<int> PmergeMe::execListAlgorithmHelper(std::list<int> *c, std::list<std::list<int> > a)
{
	if (a.empty())
		return (*c);

	std::list<int> duo1 = a.front();	a.pop_front();
	std::list<int> duo2 = a.front();	a.pop_front(); // add validation

	std::cout << " --------------- " << std::endl;
	displayValues(*c);
	// * 1 - insert the first element of the next duo
	c->push_back(duo1.front()); duo1.pop_front(); // adding duo1 greatest(a1) - duo1 only has the smallest value now
	// * 2 - insert the second element of the 2nd closest duo
	displayValues(*c);
	insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 smallest(b2) - duo 2 only have the greatest value now
	// * 3 - insert the second element of the closest duo
	displayValues(*c);
	insertList(c, duo1.back()); duo1.pop_back(); // adding duo1 smallest(b1) - duo 1 is empty
	// * 3 - insert the first(remaining) element of the 2nd closest duo
	displayValues(*c);
	insertList(c, duo2.back()); duo2.pop_back(); // adding duo2 greatest(a2) - duo 2 is empty
	execListAlgorithmHelper(c, a); // recursive call to the algorithm

	return (duo1); // take it of later!
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
		displayValues(a);
	a = sortListOfList(a);
		displayValues(a);

	if (a.front().size() == 1)
	{
		odd = a.front();
		a.pop_front();
	}
	if (a.size() > 2)
	{
		std::list<int> addToMain = a.front();
		a.pop_front();
		c.push_front(addToMain.front()); 	// a0
		c.push_front(addToMain.back()); 	// b0
	}
	//c = [b0 - a0]
	execListAlgorithmHelper(&c, a);
	displayValues(c);
	std::cout << " --------------- " << std::endl;
	insertList(&c, odd.front());
	displayValues(c);
	return (c);
}

/**
 * @brief Function will sort the duos inside the list
 * in ascending order defined by the head(greater value) of
 * each duo, and if it has a "duo" with only one value, it
 * will be put as first
 *
 * @c list with the duos to be used
 * @return list of duos ordered
 */
std::list< std::list<int> >	PmergeMe::sortListOfList(std::list< std::list<int> > c)
{
	std::list< std::list<int> >::iterator iter;
	std::list< std::list<int> > sorted;
	std::list< int >	greatestDuo;
	int					greatestVal;

	int size = c.size();
	int i = 0;

	while (i < size)
	{
		iter = c.begin();
		greatestDuo = *iter;
		greatestVal = (*iter).front();

		for (; iter != c.end(); iter++)
		{
			if ((*iter).front() > greatestVal && (*iter).size() > 1)
			{
				greatestVal = (*iter).front();
				greatestDuo = *iter;
			}
		}
		c.remove(greatestDuo);
		sorted.push_front(greatestDuo);
		i++;
	}
	return (sorted);
}

// ====================== Inserts methods ====================== //

void	PmergeMe::insertVec(std::vector<int> *c, int insert)
{
	(void) c;	(void) insert;
}

void	PmergeMe::insertList(std::list<int> *c, int insert)
{
	int start = 0;
	int end = c->size() - 1;
	int i = c->size() / 2;

	while (start <= end)
	{
		i = (start + end) / 2;

		int valueAt = listAt(*c, i);
		if (valueAt == insert)
			break;
		if (valueAt > insert)
			end = i - 1;
		else if (valueAt < insert)
			start = i + 1;
	}

	if (i == static_cast<int> (c->size() - 1))
		c->push_back(insert);
	else
	{
		std::list<int>::iterator it = c->begin();
		for (int j = 0; j < i; ++j)
		++it;
		c->insert(it, insert);
	}
}
// ====================== Constructor used  ====================== //

PmergeMe::PmergeMe(std::list<int> num)
{
	time_t startTime;
	time_t endTime;

	displayValues(num);
	startTime = time(NULL);
	std::cout << "----- going to exec list algorithm at " << startTime << " -----" << std::endl;
	execListAlgorithm(num);
	endTime = time(NULL);
	std::cout << "----- finished exec list algorithm at " << endTime << " -----" << std::endl;
}

// ====================== never used stuff ====================== //

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }

PmergeMe::~PmergeMe() {}
