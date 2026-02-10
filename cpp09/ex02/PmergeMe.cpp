
#include "PmergeMe.hpp"

long long PmergeMe::getTimeUs()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

void PmergeMe::printTime(const char* label, time_t t)
{
	char buffer[64];
	std::tm* tm_info = std::localtime(&t);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
	std::cout << label << buffer << std::endl;
}

// ====================== At method ====================== //

int PmergeMe::listAt(std::list<int>& l, int index)
{
	if (index < 0 || index >= static_cast<int>(l.size()))
		throw std::out_of_range("Index out of bounds");

	std::list<int>::iterator it = l.begin();
	std::advance(it, index);
	return *it;
}

// ====================== Vector algorithm methods ====================== //

void PmergeMe::insertSmallerValues(std::vector<int> *sortedList, std::vector<int> *smaller, std::vector< std::vector<int> > *pairs)
{
	// std::cout << "\n====== inside smaller values ======"<< std::endl;
	// displayValues(*sortedList);
	// displayValues(*smaller);
	// displayValues(*pairs);

	bool oddNumbers = (smaller->size() > pairs->size());
	// Insert first loser at front
	if (!pairs->empty())
	{
		sortedList->insert(sortedList->begin(), (*pairs)[0].back());
		// std::cout << " * INSERTED: " << (*pairs)[0].back() << std::endl;
	}

	std::vector< std::vector<int> > jacGroups = generateGroupsVector(pairs->size());
	size_t lastInserted = 0;

	for (size_t g = 1; g < jacGroups.size(); g++)
	{
		// std::cout << "-- first for --"<< std::endl;

		int from = jacGroups[g].back();
		int until = jacGroups[g].front();

		// std::cout << "- From AND until " << from << " " << until << std::endl;

		for (int i = from; i >= until && i > static_cast<int>(lastInserted); i--)
		{
			// std::cout << "-- second for --"<< std::endl;
			// std::cout << i << " i x pair_size() " <<  pairs->size() << std::endl;

			if (i >= static_cast<int>(pairs->size()))
				continue;

			// std::cout << "bf " << std::endl;
			int winner = (*pairs)[i].front();  // ✓ Now correct because pairs are reordered!
			int loser = (*pairs)[i].back();
			// std::cout << "aft " << std::endl;
			// std::cout << "- inserting looser " << loser << " paired with " << winner << std::endl;

			// Find winner's position in sortedList
			std::vector<int>::iterator it =
				std::lower_bound(sortedList->begin(), sortedList->end(), winner);
			int winnerPos = std::distance(sortedList->begin(), it);

			// std::cout << "< loop insert > ";
			// std::cout << " * INSERTED: " << loser << std::endl;
			binInsertVec(sortedList, winnerPos, loser);  // ✓ Your original signature!
		}
		lastInserted = from;
	}

	// Handle odd element
	if (oddNumbers)
	{
		// std::cout << "< odd insert > ";
		binInsertVec(sortedList, sortedList->size() - 1, smaller->back());
	}
}

/**
 * @brief Start the vector with the Jacobsthal groups and execute the algorithm
 * similar to the list implementation
 *
 * @param jacGroups Jacobsthal groups for insertion order
 * @param num with the numbers entered by the user
 * @return vector with sorted numbers
 */
std::vector<int> PmergeMe::execVecAlgorithm(std::vector<int> *num)
{
	// std::cout << " --====== inside execVecAlgorithm ====== -- "<< std::endl;
	// std::cout << "num :"<< std::endl;	displayValues(*num);

	if (num->size() <= 1)
		return (*num);

	std::vector< std::vector<int> > pairs;
	std::vector<int> greater;
	std::vector<int> smaller;

	populate(&pairs, &greater, &smaller, num);

	// std::cout << "greater :"<< std::endl;	displayValues(greater);

	// std::cout << "pairs :"<< std::endl;	displayValues(pairs);

	greater = execVecAlgorithm(&greater);
	pairs = reorderPairs(pairs, greater);

	insertSmallerValues(&greater, &smaller, &pairs);

	return greater;
}

// ====================== list algorithm methods ====================== //

void PmergeMe::insertSmallerValues(std::deque<int> *sortedList, std::deque<int> *smaller, std::deque< std::deque<int> > *pairs)
{
	// std::cout << "\n====== inside smaller values ======"<< std::endl;
	//displayValues(*sortedList);
	//displayValues(*smaller);
	//displayValues(*pairs);

	bool oddNumbers = (smaller->size() > pairs->size());
	// Insert first loser at front
	if (!pairs->empty())
	{
		sortedList->insert(sortedList->begin(), (*pairs)[0].back());
		// std::cout << " * INSERTED: " << (*pairs)[0].back() << std::endl;
	}

	std::deque< std::deque<int> > jacGroups = generateGroupsDeque(pairs->size());
	size_t lastInserted = 0;

	for (size_t g = 1; g < jacGroups.size(); g++)
	{
		// std::cout << "-- first for --"<< std::endl;

		int from = jacGroups[g].back();
		int until = jacGroups[g].front();

		// std::cout << "- From AND until " << from << " " << until << std::endl;

		for (int i = from; i >= until && i > static_cast<int>(lastInserted); i--)
		{
			// std::cout << "-- second for --"<< std::endl;
			// std::cout << i << " i x pair_size() " <<  pairs->size() << std::endl;

			if (i >= static_cast<int>(pairs->size()))
				continue;

			// std::cout << "bf " << std::endl;
			int winner = (*pairs)[i].front();  // ✓ Now correct because pairs are reordered!
			int loser = (*pairs)[i].back();
			// std::cout << "aft " << std::endl;
			// std::cout << "- inserting looser " << loser << " paired with " << winner << std::endl;

			// Find winner's position in sortedList
			std::deque<int>::iterator it =
				std::lower_bound(sortedList->begin(), sortedList->end(), winner);
			int winnerPos = std::distance(sortedList->begin(), it);

			// std::cout << "< loop insert > ";
			// std::cout << " * INSERTED: " << loser << std::endl;
			binInsertDeque(sortedList, winnerPos, loser);  // ✓ Your original signature!
		}
		lastInserted = from;
	}

	// Handle odd element
	if (oddNumbers)
	{
		// std::cout << "< odd insert > ";
		binInsertDeque(sortedList, sortedList->size() - 1, smaller->back());
	}
}

/**
 * @brief Start the list with the three numbers(a0,b0 and a1) and call the recursive
 * function to execute the algorithm
 *
 * @param num with the numbers entered by the user
 * @return list with sorted numbers
 */
std::deque<int> PmergeMe::execDequeAlgorithm(std::deque<int> *num)
{
	//std::cout << " --====== inside execVecAlgorithm ====== -- "<< std::endl;
	//std::cout << "num :"<< std::endl;	displayValues(*num);

	if (num->size() <= 1)
		return (*num);

	std::deque< std::deque<int> > pairs;
	std::deque<int> greater;
	std::deque<int> smaller;

	populate(&pairs, &greater, &smaller, num);

	//std::cout << "greater :"<< std::endl;	displayValues(greater);

	//std::cout << "pairs :"<< std::endl;	displayValues(pairs);

	greater = execDequeAlgorithm(&greater);
	pairs = reorderPairs(pairs, greater);

	insertSmallerValues(&greater, &smaller, &pairs);

	return (greater);
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
	int pos = end + 1;

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
void PmergeMe::binInsertDeque(std::deque<int> *c, int end, int insert)
{
	int start = 0;
	int pos = end;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		// Get iterator to mid position in deque
		std::deque<int>::iterator midIt = c->begin();
		std::advance(midIt, mid);
		int valueAt = *midIt;

		if (valueAt >= insert)
		{
			pos = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	// Insert at the correct position
	std::deque<int>::iterator it = c->begin();
	std::advance(it, pos);
	c->insert(it, insert);
}

// ====================== Constructor used  ====================== //

PmergeMe::PmergeMe(std::vector<int> *num)
{
	time_t startTime, endTime;
	long long startNs, endNs;

	std::cout << "----- Deque algorithm -----" << std::endl;

	startTime = time(NULL);
	startNs = getTimeUs();
	printTime("Start time: ", startTime);

	std::deque<int> d(num->begin(), num->end());
	std::deque<int> resD = execDequeAlgorithm(&d);

	endTime = time(NULL);
	endNs = getTimeUs();
	printTime("End time:   ", endTime);
	std::cout << "Elapsed:    " << (endNs - startNs) << " µs" << std::endl << std::endl;

	std::cout << "----- Vector algorithm -----" << std::endl;

	startTime = time(NULL);
	startNs = getTimeUs();
	printTime("Start time: ", startTime);

	std::vector<int> v(num->begin(), num->end());
	std::vector<int> resV =execVecAlgorithm(&v);

	endTime = time(NULL);
	endNs = getTimeUs();
	printTime("End time:   ", endTime);
	std::cout << "Elapsed:    " << (endNs - startNs) << " µs" << std::endl;
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
		if (j1 >  listSize) // ! do not know if it needs to stay like this
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

std::vector< std::vector<int> > PmergeMe::generateGroupsVector(int vectorSize)
{
	// std::cout << "vector size is " << vectorSize << std::endl;
	std::list<int> jacobsthal = calc_jacobsthallSequence(vectorSize);
	std::vector< std::vector<int> > groups;
	std::vector<int> add;

	add.push_back(1); add.push_back(1); // adding [1, 1]
	groups.push_back(add);

	// std::cout << "| ----- ----- ----- |" << std::endl;
	// std::cout << "| ----- group ----- |" << std::endl;
	// std::cout << "    " << add.front() << " - " << add.back() << std::endl;
	// * groups are formated of [ j(i) + 1 -j (i+1) ] then reverse the order
	for (size_t i = 1; i < jacobsthal.size() - 1; i++)
	{
		add.clear();
		add.push_back( (listAt(jacobsthal, i) + 1) -1 ); // * j(i) + 1  (-1 becuase of index )
		add.push_back( listAt(jacobsthal, i + 1)  - 1); // * j(i + 1) (-1 becuase of index )
		// std::cout << "| ----- group ----- |" << std::endl;
		// std::cout << "    " << add.front() << " - " << add.back() << std::endl;
		groups.push_back(add);
	}
	// std::cout << "| ----- ----- ----- |" << std::endl;

	return (groups);
}

std::deque< std::deque<int> > PmergeMe::generateGroupsDeque(int dequeSize)
{
	// std::cout << "deque size is " << dequeSize << std::endl;
	std::list<int> jacobsthal = calc_jacobsthallSequence(dequeSize);
	std::deque< std::deque<int> > groups;
	std::deque<int> add;

	add.push_back(1); add.push_back(1); // adding [1, 1]
	groups.push_back(add);

	// std::cout << "| ----- ----- ----- |" << std::endl;
	// std::cout << "| ----- group ----- |" << std::endl;
	// std::cout << "    " << add.front() << " - " << add.back() << std::endl;
	// * groups are formated of [ j(i) + 1 -j (i+1) ] then reverse the order
	for (size_t i = 1; i < jacobsthal.size() - 1; i++)
	{
		add.clear();
		add.push_back( (listAt(jacobsthal, i) + 1) -1 ); // * j(i) + 1  (-1 becuase of index )
		add.push_back( listAt(jacobsthal, i + 1)  - 1); // * j(i + 1) (-1 becuase of index )
		// std::cout << "| ----- group ----- |" << std::endl;
		// std::cout << "    " << add.front() << " - " << add.back() << std::endl;
		groups.push_back(add);
	}
	// std::cout << "| ----- ----- ----- |" << std::endl;

	return (groups);
}



// ====================== never used stuff ====================== //

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }

PmergeMe::~PmergeMe() {}

// ====================== Utils Methods ====================== //

void PmergeMe::displayValues(std::deque<int> val)
{
	for (std::deque<int>::iterator it = val.begin(); it != val.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

void PmergeMe::displayValues(std::vector<int> val)
{
	for (std::vector<int>::iterator it = val.begin(); it != val.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

void PmergeMe::displayValues(std::deque< std::deque<int> > val)
{
	for (std::deque< std::deque<int> >::iterator it = val.begin(); it != val.end(); it++)
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
