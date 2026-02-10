#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>
# include <ctime>
# include <cmath>
# include <vector>
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <iostream>
# include <iterator>
# include <algorithm>
# include <sys/time.h>

class PmergeMe{
private:

	long long	getTimeUs();
	void		printTime(const char* label, time_t t);

	std::deque	<int> execDequeAlgorithm (std::deque<int> *num);
	std::vector	<int> execVecAlgorithm (std::vector<int> *num);

	void insertSmallerValues(std::vector<int> *sortedList, std::vector<int> *smaller, std::vector< std::vector<int> > *pairs);
	void insertSmallerValues(std::deque<int> *sortedList, std::deque<int> *smaller, std::deque< std::deque<int> > *pairs);

	std::list	< std::list <int> > 	generateGroups(int listSize);
	std::deque	< std::deque<int> >		generateGroupsDeque(int dequeSize);
	std::vector	< std::vector<int> >	generateGroupsVector(int vectorSize);
	std::list				 <int>		calc_jacobsthallSequence(int listSize);

	void	binInsertVec(std::vector<int> *c, int end, int insert);
	void	binInsertDeque(std::deque<int> *c, int end, int insert);

	int		listAt(std::list<int> &l, int index);

	void	displayValues(std::deque<int> val);
	void	displayValues(std::vector<int> val);
	void	displayValues(std::deque < std::deque<int> > val);
	void	displayValues(std::vector < std::vector<int> > val);

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
	PmergeMe(std::vector<int> *num);
	~PmergeMe();
};

#endif
