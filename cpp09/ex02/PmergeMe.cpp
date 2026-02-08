
#include "PmergeMe.hpp"

static long long getTimeMs()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}

static void printTime(const char* label, time_t t)
{
	char buffer[64];
	std::tm* tm_info = std::localtime(&t);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
	std::cout << label << buffer << std::endl;
}

void PmergeMe::displayValues(std::list<int> val)
{
	for (std::list<int>::iterator it = val.begin(); it != val.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

void PmergeMe::displayValues(std::vector<int> val)
{
	for (std::vector<int>::iterator it = val.begin(); it != val.end(); it++)
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

void PmergeMe::displayValues(std::vector< std::vector<int> > val)
{
	for (std::vector< std::vector<int> >::iterator it = val.begin(); it != val.end(); it++)
	{
		std::cout << (*it).front();
		if ((*it).back() != (*it).front())
			std::cout << " - " << (*it).back();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// ====================== JacobStahll methods ====================== //

/**
 * @brief function will generate the jacobsthallSequence needed to
 * be used to divide the groups to sort the list of elements
 */
std::list<int> PmergeMe::calc_jacobsthallSequence(int listSize)
{
	std::list<int> jacobsthal;
	int curr = 1;
	int j0 = 0;
	int j1 = 1;

	if (listSize <= 0)
		return (jacobsthal);
	jacobsthal.push_back(j1);  // Start with J(1) = 1

	while (true)
	{
		curr = j1 + 2 * j0;  // Jacobsthal recurrence: J(n) = J(n-1) + 2*J(n-2)

		// checking the before, because the value could be between the interval
		// could be in the between of the smaller and greater than listSize
		if (j1 >= listSize)
			break;

		jacobsthal.push_back(curr);
		j0 = j1;
		j1 = curr;
	}

	return jacobsthal;
}

std::list< std::list<int> > PmergeMe::generateGroups(int listSize)
{
	std::list<int> jacobsthal = calc_jacobsthallSequence(listSize);
	std::list< std::list<int> > groups;
	std::list<int> add;

	add.push_back(1); add.push_back(1); // adding [1, 1]
	groups.push_back(add);
	// * groups are formated of [ j(i) + 1 -j (i+1) ] then reverse the order
	for (size_t i = 1; i < jacobsthal.size() - 1; i++)
	{
		add.clear();
		add.push_back( listAt(jacobsthal, i) + 1 ); // * j(i) + 1
		add.push_back( listAt(jacobsthal, i + 1)  ); // * j(i + 1)
		// std::cout << " ----- group ----- " << std::endl;
		// std::cout << add.front() << " - " << add.back() << std::endl;
		groups.push_back(add);
	}
	return (groups);
}


// ====================== At methods ====================== //

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

int PmergeMe::vecAt(std::vector<int> v, int index)
{
	std::vector<int>::iterator it;
	int	i = 0;

	for (it = v.begin(); it != v.end(); it++)
	{
		if (i == index)
			return (*it);
		i++;
	}
	return (*it); // will never hit here
}

// ====================== Vector algorithm methods ====================== //

void PmergeMe::execVecAlgorithmHelper(std::vector<int> *c, std::vector<std::vector<int> > a)
{
	if (a.empty())
		return ;

	std::vector<int> duo1 = a.back();	a.pop_back();
	std::vector<int> duo2 = a.back();	a.pop_back(); // add validation

	std::cout << " --------------- " << std::endl;
	displayValues(*c);
	// * 1 - insert the first element of the next duo
	 c->push_back(duo1.front()); // adding duo1 greatest(a1) - duo1 only has the smallest value now
	// * 2 - insert the second element of the 2nd closest duo
	binInsertVec(c,  c->size() - 1, duo2.back()); // adding duo2 smallest(b2) - duo 2 only have the greatest value now
	// * 3 - insert the second element of the closest duo
	binInsertVec(c,  c->size() - 1, duo1.back()); // adding duo1 smallest(b1) - duo 1 is empty
	// * 4 - insert the first(remaining) element of the 2nd closest duo
	binInsertVec(c,  c->size() - 1, duo2.front()); // adding duo2 greatest(a2) - duo 2 is empty
	duo1.clear(); duo2.clear();
	execVecAlgorithmHelper(c, a); // recursive call to the algorithm
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
	std::vector< int >  odd;

	populate(&a, num);
		displayValues(a);
	a = sortVecOfVec(a);
		displayValues(a);

	if (a.back().size() == 1)
	{
		odd = a.back();
		a.pop_back();
	}
	if (a.size() > 2)
	{
		std::vector<int> addToMain = a.back();
		a.pop_back();
		c.push_back(addToMain.back()); 	// b0
		c.push_back(addToMain.front());	// a0
	}
	//c = [b0 - a0]
	execVecAlgorithmHelper(&c, a);
	displayValues(c);
	std::cout << " --------------- " << std::endl;
	binInsertVec(&c, c.size(), odd.back());
	displayValues(c);
	return (c);
}

// ====================== list algorithm methods ====================== //

void PmergeMe::execListAlgorithmHelper(std::list<int> *c, std::list<std::list<int> > a)
{
	if (a.empty())
		return ;

	std::list<int> duo1 = a.front();	a.pop_front();
	std::list<int> duo2 = a.front();	a.pop_front(); // add validation

	std::cout << " --------------- " << std::endl;
	displayValues(*c);
	// * 1 - insert the first element of the next duo
	c->push_back(duo1.front()); duo1.pop_front(); // adding duo1 greatest(a1) - duo1 only has the smallest value now
	// * 2 - insert the second element of the 2nd closest duo
	displayValues(*c);
	binInsertList(c, c->size() - 1, duo2.back()); duo2.pop_back(); // adding duo2 smallest(b2) - duo 2 only have the greatest value now
	// * 3 - insert the second element of the closest duo
	displayValues(*c);
	binInsertList(c, c->size() - 1, duo1.back()); duo1.pop_back(); // adding duo1 smallest(b1) - duo 1 is empty
	// * 4 - insert the first(remaining) element of the 2nd closest duo
	displayValues(*c);
	binInsertList(c, c->size() - 1, duo2.back()); duo2.pop_back(); // adding duo2 greatest(a2) - duo 2 is empty
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
	displayValues(c);
	//c = [b0 - a0]
	execListAlgorithmHelper(&c, a);
	displayValues(c);
	std::cout << " --------------- " << std::endl;
	binInsertList(&c, c.size() - 1, odd.front());
	displayValues(c);
	return (c);
}

// ====================== Sort container of containers methods ====================== //

/**
 * @brief Function will sort the duos inside the vector
 * in descending order defined by the tail(greater value) of
 * each duo, and if it has a "duo" with only one value, it
 * will be put as first. this is reverse than what is done in
 * the list because of hopw we access it, to make it more efficient
 *
 * @c vector with the duos to be used
 * @return vector of duos ordered
 */
std::vector< std::vector<int> >	PmergeMe::sortVecOfVec(std::vector< std::vector<int> > c)
{
	std::vector< std::vector<int> >::iterator iter;
	std::vector< std::vector<int> > sorted;
	std::vector< int >	smallerDuo;
	int					smallerVal;

	int size = c.size();
	int i = 0;

	while (i < size)
	{
		iter = c.begin();
		smallerDuo = *iter;
		smallerVal = (*iter).front();

		for (; iter != c.end(); iter++)
		{
			if ((*iter).front() > smallerVal && (*iter).size() > 1)
			{
				smallerVal = (*iter).front();
				smallerDuo = *iter;
			}
		}
		removeVec(&c, smallerVal);
		sorted.push_back(smallerDuo);
		i++;
	}
	return (sorted);
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

void	PmergeMe::binInsertVec(std::vector<int> *c, int end, int insert)
{
	int start = 0;
	int pos = c->size(); // default: insert at end

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int valueAt = vecAt(*c, mid);

		if (valueAt >= insert)
		{
			pos = mid;      // Found a position where we could insert
			end = mid - 1;  // Look for earlier position
		}
		else
			start = mid + 1;
	}
	insertVec(c, pos, insert);
}

void	PmergeMe::insertVec(std::vector<int> *c, int pos, int insert)
{
	std::vector<int> temp;

	for (int last = c->size(); last > pos; last--)
	{
		temp.push_back(c->back());
		c->pop_back();
	}

	c->push_back(insert);

	int size = temp.size();
	for (int i = 0; i < size; i++)
	{
		c->push_back(temp.back());
		temp.pop_back();
	}
}

void	PmergeMe::binInsertList(std::list<int> *c, int end, int insert)
{
	int start = 0;
	int pos = c->size(); // default: insert at end

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int valueAt = listAt(*c, mid);

		if (valueAt >= insert)
		{
			pos = mid;      // Found a position where we could insert
			end = mid - 1;  // Look for earlier position
		}
		else
			start = mid + 1;
	}

	// Insert at position 'pos'
	std::list<int>::iterator it = c->begin();
	std::advance(it, pos);
	c->insert(it, insert);
}

// ====================== Remove method ====================== //

void PmergeMe::removeVec(std::vector< std::vector<int> > *c, int removeVal)
{
	std::vector< std::vector<int> > temp;

	while (!c->empty())
	{
		if (c->back().front() != removeVal)
			temp.push_back(c->back());
		c->pop_back();
	}

	while (!temp.empty())
	{
		c->push_back(temp.back());
		temp.pop_back();
	}
}

// ====================== Constructor used  ====================== //

PmergeMe::PmergeMe(std::list<int> num)
{
	time_t startTime, endTime;
	long long startMs,endMs;

	std::cout << "----- List algorithm -----" << std::endl;

	startTime = time(NULL);		startMs = getTimeMs();
	printTime("Start time: ", startTime);

	execListAlgorithm(num);

	endTime = time(NULL);		endMs = getTimeMs();
	printTime("End time:   ", endTime);
	std::cout << "Elapsed:    " << (endMs - startMs) << " ms" << std::endl << std::endl;

	std::cout << "----- Vector algorithm -----" << std::endl;
	startTime = time(NULL);		startMs = getTimeMs();
	printTime("Start time: ", startTime);

	execVecAlgorithm(num);

	endTime = time(NULL);		endMs = getTimeMs();
	printTime("End time:   ", endTime);
	std::cout << "Elapsed:    " << (endMs - startMs) << " ms" << std::endl;
}

// ====================== never used stuff ====================== //

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }

PmergeMe::~PmergeMe() {}
