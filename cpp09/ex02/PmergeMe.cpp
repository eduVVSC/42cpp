
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
		if (j1 >= listSize / 2)
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
		std::cout << " ----- group ----- " << std::endl;
		std::cout << add.front() << " - " << add.back() << std::endl;
		groups.push_back(add);
	}
	return (groups);
}

std::vector< std::vector<int> > PmergeMe::generateGroupsVector(int vectorSize)
{
	std::list<int> jacobsthal = calc_jacobsthallSequence(vectorSize);
	std::vector< std::vector<int> > groups;
	std::vector<int> add;

	add.push_back(1); add.push_back(1); // adding [1, 1]
	groups.push_back(add);
	// * groups are formated of [ j(i) + 1 -j (i+1) ] then reverse the order
	for (size_t i = 1; i < jacobsthal.size() - 1; i++)
	{
		add.clear();
		add.push_back( listAt(jacobsthal, i) + 1 ); // * j(i) + 1
		add.push_back( listAt(jacobsthal, i + 1)  ); // * j(i + 1)
		std::cout << " ----- group ----- " << std::endl;
		std::cout << add.front() << " - " << add.back() << std::endl;
		groups.push_back(add);
	}
	return (groups);
}



// ====================== At methods ====================== //

int PmergeMe::listAt(std::list<int>& l, int index)
{
	if (index < 0 || index >= static_cast<int>(l.size()))
		throw std::out_of_range("Index out of bounds");

	std::list<int>::iterator it = l.begin();
	std::advance(it, index);
	return *it;
}

std::list<int> PmergeMe::lisOftListAt(std::list< std::list<int> >& l, int index)
{
    if (index < 0 || index >= static_cast<int>(l.size()))
        throw std::out_of_range("Index out of bounds");

    std::list< std::list<int> >::iterator it = l.begin();
    std::advance(it, index);
    return *it;
}

// ====================== Vector algorithm methods ====================== //


/**
 * @brief Start the vector with the Jacobsthal groups and execute the algorithm
 * similar to the list implementation
 *
 * @param jacGroups Jacobsthal groups for insertion order
 * @param num with the numbers entered by the user
 * @return vector with sorted numbers
 */
std::vector<int> PmergeMe::execVecAlgorithm(std::vector< std::vector<int> > jacGroups, std::list<int> num)
{
	std::vector< std::vector<int> >::iterator groupIter;
	std::vector< std::vector<int> >::iterator tempIter;
	std::vector< std::vector<int> >  temp;
	std::vector< std::vector<int> >  a;
	std::vector< int >  gpNow;
	std::vector< int >  odd;
	std::vector< int >  c;

	populate(&a, num);			// displayValues(a);
	a = sortVecOfVec(a);		displayValues(a);

	if (a.back().size() == 1)
	{
		odd = a.back();
		a.pop_back();
	}

	// * 1 interaction is always add a0 - a1 - a2
	for (groupIter = jacGroups.begin(); groupIter != jacGroups.end(); groupIter++)
	{
		gpNow = *groupIter;

		int from = gpNow.back();	// greater than until
		int until = gpNow.front();

		// * insert As
		temp.insert(temp.begin(), a.back()); 
		a.pop_back();	
		c.push_back(temp.front().front());
		
		for (int i = from; i > until; i--)
		{
			if (a.size() == 0)
				break;

			temp.push_back(a.back()); 
			a.pop_back();
			c.push_back(temp.back().front()); // A(n) to vector C
		}

		//displayValues(c);

		// * insert Bs (reverse order)
		for (tempIter = temp.begin(); tempIter != temp.end(); tempIter++)
		{
			//displayValues(c);
			std::vector<int>::iterator it = std::upper_bound(c.begin(), c.end(), (*tempIter).front());
			int pos = std::distance(c.begin(), it);

			binInsertVec(&c, pos, (*tempIter).back());
		}
		
		//displayValues(c);
		temp.clear();
	}
	if (odd.size() > 0)
		binInsertVec(&c, c.size(), odd.back());
		
	std::cout << "\nSORTED FINAL LIST:" << std::endl;
	displayValues(c);
	return (c);
}

// ====================== list algorithm methods ====================== //

/**
 * @brief Start the list with the three numbers(a0,b0 and a1) and call the recursive
 * function to execute the algorithm
 *
 * @param num with the numbers entered by the user
 * @return list with sorted numbers
 */
std::list<int> PmergeMe::execListAlgorithm(std::list< std::list<int> > jacGroups, std::list<int> num)
{
	std::list< std::list<int> >::iterator groupIter;
	std::list< std::list<int> >::iterator tempIter;
	std::list< std::list<int> >  temp;
	std::list< std::list<int> >  a;
	std::list< int >  gpNow;
	std::list< int >  odd;
	std::list< int >  c;

	populate(&a, num);			//displayValues(a);
	a = sortListOfList(a);		displayValues(a);

	if (a.front().size() == 1)
	{
		odd = a.front();
		a.pop_front();
	}

	// * 1 interaction is always add a0 - a1 - a2
	for (groupIter = jacGroups.begin(); groupIter != jacGroups.end(); groupIter++)
	{
		gpNow = *groupIter;

		int from = gpNow.back();	// greater than until
		int until = gpNow.front();
		//std::cout << "--------- GROUP " << from << " " << until << " --------- "  << std::endl;
		//std::cout << "--------- GROUP " << gpNow.front() << " " << gpNow.back() << " --------- "  << std::endl;

		// * insert As
 		temp.push_front(a.front()); a.pop_front();	c.push_back(temp.front().front());
		//std::cout << " - Inserting A" << std::endl;
		for (int i = from; i > until; i--) // ! problem, never getting inside the loop error in the logic of from and until
		{
			if (a.size() == 0)
				break ;

			//std::cout << "1st loop: " << a.front().front() <<  std::endl;
			temp.push_back(a.front()); a.pop_front();
			c.push_back(temp.back().front()); // A(n) to list C
		}
		// std::cout << "OUT" << std::endl;
		// std::cout << "temp: " << temp.front().front() << " - " << temp.front().back() << std::endl;
		// std::cout << "list after A:" << std::endl;

		//displayValues(c);

		// std::cout << "\n - Inserting B" << std::endl;
		// * insert Bs (reverse order than originaly on the array)
		for (tempIter = temp.begin(); tempIter != temp.end(); tempIter++)
		{
			//displayValues(c);
			std::list<int>::iterator it = std::upper_bound(c.begin(), c.end(), (*tempIter).front());
			int pos = std::distance(c.begin(), it);

			binInsertList(&c, pos, (*tempIter).back());
		}
		// std::cout << "list after B:" << std::endl;
		//displayValues(c);
		temp.clear();
	}
	if (odd.size() > 0)
		binInsertList(&c, c.size(), odd.back());
		
	std::cout << "\nSORTED FINAL LIST:" << std::endl;
	displayValues(c);
	// binInsertList(&c, c.size() - 1, odd.front());
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

/**
 * @brief Binary insert with the improvement given from the merge insert
 * algorithm where the end is given based on the position in c from the
 * greatest number in the duo
 */
void	PmergeMe::binInsertVec(std::vector<int> *c, int end, int insert)
{
	int start = 0;
	int pos = c->size(); // default: insert at end // ! check it later

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int valueAt = c->at(mid);

		if (valueAt >= insert)
		{
			pos = mid;      // Found a position where we could insert
			end = mid - 1;  // Look for earlier position
		}
		else
			start = mid + 1;
	}
	c->insert(c->begin() + pos, insert);
}

/**
 * @brief Binary insert with the improvement given from the merge insert
 * algorithm where the end is given based on the position in c from the
 * greatest number in the duo
 */
void	PmergeMe::binInsertList(std::list<int> *c, int end, int insert)
{
	// std::cout << "\n-- INSIDE BINARY INSERT --" << std::endl;
	// std::cout << "end =" <<  end << std::endl;
	// std::cout << "c size =" <<  c->size() << std::endl;
	int start = 0;
	int pos = end; // default: insert at end  // ! check it later, maybe it will be (end + 1)

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
	std::list< std::list<int> > groups = generateGroups(num.size());
	std::vector< std::vector<int> > groupsV = generateGroupsVector(num.size());

	time_t startTime, endTime;
	long long startMs,endMs;

	std::cout << "----- List algorithm -----" << std::endl;

	startTime = time(NULL);		startMs = getTimeMs();
	printTime("Start time: ", startTime);

	execListAlgorithm(groups, num);

	endTime = time(NULL);		endMs = getTimeMs();
	printTime("End time:   ", endTime);
	std::cout << "Elapsed:    " << (endMs - startMs) << " ms" << std::endl << std::endl;

	std::cout << "----- Vector algorithm -----" << std::endl;
	startTime = time(NULL);		startMs = getTimeMs();
	printTime("Start time: ", startTime);

	execVecAlgorithm(groupsV, num);

	endTime = time(NULL);		endMs = getTimeMs();
	printTime("End time:   ", endTime);
	std::cout << "Elapsed:    " << (endMs - startMs) << " ms" << std::endl;
}

// ====================== never used stuff ====================== //

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }

PmergeMe::~PmergeMe() {}
