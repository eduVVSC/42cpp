#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <ctime>
# include <cmath>
# include <vector>
# include <iostream>
# include <iterator>
# include <algorithm>
# include <sys/time.h>

class PmergeMe{
private:

	std::list   <int> execListAlgorithm (std::list<int> *num);
	std::vector	<int> execVecAlgorithm (std::vector<int> *num);
	void insertSmallerValues(std::vector<int> *sortedList, std::vector<int> *smaller, std::vector< std::vector<int> > *pairs);
	
	
	std::list < std::list <int> > 	generateGroups(int listSize);
	std::vector< std::vector<int> > generateGroupsVector(int vectorSize);
	std::list <int> 				calc_jacobsthallSequence(int listSize);

	void	binInsertVec(std::vector<int> *c, int end, int insert);
	void	binInsertList(std::list<int> *c, int end, int insert);

	int		listAt(std::list<int> &l, int index);

	void	displayValues(std::list<int> val);
	void	displayValues(std::vector<int> val);
	void	displayValues(std::list< std::list<int> > val);
	void	displayValues(std::vector< std::vector<int> > val);

	PmergeMe();
	PmergeMe(const PmergeMe &other);


	/**
	 * @brief funtion will separate the input into duos to the
	 * execution of the algorithm
	 */
	template <typename OuterContainer, typename InnerContainer>
	void populate(OuterContainer *out, InnerContainer *greater, InnerContainer *smaller, InnerContainer *num) {
		typename InnerContainer::iterator it, end;
		int val1, val2;

		it = num->begin(); end = num->end();
		while (it != end && (it + 1) != end)  // ✓
		{
			InnerContainer b;
			val1 = *it++;
			val2 = *it;
			if (val1 < val2) // n / 2
			{
				b.push_back(val2); greater->push_back(val2);
				b.push_back(val1); smaller->push_back(val1);
			}
			else
			{
				b.push_back(val1); greater->push_back(val1);
				b.push_back(val2); smaller->push_back(val2);
			}
			out->push_back(b);
			it++;
		}
		if (it != end)
		{
			InnerContainer b;
			b.push_back(*it);
			out->push_back(b);
			smaller->push_back(*it);
		}
	};

	template <typename OuterContainer, typename InnerContainer>
	OuterContainer reorderPairs(OuterContainer &pairs, InnerContainer &sortedGreater)
	{
		OuterContainer reordered;
		
		for (size_t i = 0; i < sortedGreater.size(); i++)
		{
			int winner = sortedGreater[i];
			
			// Find pair with this winner (using == only, doesn't count!)
			for (size_t j = 0; j < pairs.size(); j++)
			{
				if (pairs[j].front() == winner)
				{
					reordered.push_back(pairs[j]);
					break;
				}
			}
		}
		return reordered;
	}

public:
	PmergeMe(std::list<int> *num);
	~PmergeMe();
};

#endif
