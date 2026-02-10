
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
    std::cout << "\n====== inside smaller values ======"<< std::endl;
    std::cout << "size of sorted list and smaller and pairs " << sortedList->size() << " " << smaller->size() << " " << pairs->size() << std::endl;
	

    bool oddNumbers = (smaller->size() > pairs->size());
    // Insert first loser at front
    if (!pairs->empty())
        sortedList->insert(sortedList->begin(), (*pairs)[0].back());
    
    std::vector< std::vector<int> > jacGroups = generateGroupsVector(pairs->size());
    size_t lastInserted = 0;
    
    for (size_t g = 1; g < jacGroups.size(); g++)
    {
		
        int from = jacGroups[g].back();
        int until = jacGroups[g].front();
    
		std::cout << "- From AND until " << from << " " << until << std::endl;
        
        for (int i = from; i >= until && i > static_cast<int>(lastInserted); i--)
        {
            if (i >= static_cast<int>(pairs->size()))
                continue;
            
            int winner = (*pairs)[i].front();  // ✓ Now correct because pairs are reordered!
            int loser = (*pairs)[i].back();
			std::cout << "- inserting looser " << loser << " paired with " << winner << std::endl;
            
            // Find winner's position in sortedList
            std::vector<int>::iterator it = 
                std::lower_bound(sortedList->begin(), sortedList->end(), winner);
            int winnerPos = std::distance(sortedList->begin(), it);
			
			std::cout << "< loop insert > ";
            binInsertVec(sortedList, winnerPos, loser);  // ✓ Your original signature!
        }
        lastInserted = from;
    }
    
    // Handle odd element
    if (oddNumbers)
    {
		std::cout << "< odd insert > ";
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
    std::cout << " --====== inside execVecAlgorithm ====== -- "<< std::endl;
	std::cout << "num :"<< std::endl;	displayValues(*num);

    if (num->size() <= 1)
        return (*num);
    
    std::vector< std::vector<int> > pairs;
    std::vector<int> greater;
    std::vector<int> smaller;
    
    populate(&pairs, &greater, &smaller, num);
	
	std::cout << "greater :"<< std::endl;	displayValues(greater);

    std::cout << "pairs :"<< std::endl;	displayValues(pairs);

    greater = execVecAlgorithm(&greater);    
    pairs = reorderPairs(pairs, greater);
    
    insertSmallerValues(&greater, &smaller, &pairs);
    
    return greater;
}

// ====================== list algorithm methods ====================== //

/**
 * @brief Start the list with the three numbers(a0,b0 and a1) and call the recursive
 * function to execute the algorithm
 *
 * @param num with the numbers entered by the user
 * @return list with sorted numbers
 */
std::list<int> PmergeMe::execListAlgorithm(std::list<int> *num)
{
	(void) num;
	return (*num);
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

	std::cout << "inserting : " << insert << " at " << pos << std::endl; 
	c->insert(c->begin() + pos, insert);
}

/**
 * @brief Binary insert with the improvement given from the merge insert
 * algorithm where the end is given based on the position in c from the
 * greatest number in the duo
 */
void PmergeMe::binInsertList(std::list<int> *c, int end, int insert)
{
    int start = 0;
    int pos = end;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;
        
        // Get iterator to mid position
        std::list<int>::iterator midIt = c->begin();
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
    
    std::list<int>::iterator it = c->begin();
    std::advance(it, pos);
    c->insert(it, insert);
}

// ====================== Constructor used  ====================== //

PmergeMe::PmergeMe(std::list<int> *num)
{
	time_t startTime, endTime;
	long long startMs,endMs;

	// std::cout << "----- List algorithm -----" << std::endl;

	// startTime = time(NULL);		startMs = getTimeMs();
	// printTime("Start time: ", startTime);

	// execListAlgorithm(num);

	// endTime = time(NULL);		endMs = getTimeMs();
	// printTime("End time:   ", endTime);
	// std::cout << "Elapsed:    " << (endMs - startMs) << " ms" << std::endl << std::endl;

	std::cout << "----- Vector algorithm -----" << std::endl;
	startTime = time(NULL);		startMs = getTimeMs();
	printTime("Start time: ", startTime);

	std::vector<int> v (num->begin(), num->end());
	displayValues(execVecAlgorithm(&v)); // ! change it 

	endTime = time(NULL);		endMs = getTimeMs();
	printTime("\n\nEnd time:   ", endTime);
	std::cout << "Elapsed:    " << (endMs - startMs) << " ms" << std::endl;
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
		if (j1 >  std::ceil(listSize / 2))
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
	std::cout << "vector size is " << vectorSize << std::endl;
	std::list<int> jacobsthal = calc_jacobsthallSequence(vectorSize);
	std::vector< std::vector<int> > groups;
	std::vector<int> add;

	add.push_back(1); add.push_back(1); // adding [1, 1]
	groups.push_back(add);
	
	std::cout << " ----- group ----- " << std::endl;
	std::cout << add.front() << " - " << add.back() << std::endl;
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


// ====================== never used stuff ====================== //

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }

PmergeMe::~PmergeMe() {}

// ====================== Utils Methods ====================== //

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
