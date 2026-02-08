#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <ctime>
# include <vector>
# include <iostream>
# include <iterator>
# include <algorithm>
# include <sys/time.h>

class PmergeMe{
private:

	std::vector <int> execVecAlgorithm(std::list<int> num);
	std::list   <int> execListAlgorithm(std::list< std::list<int> > jacGroups, std::list<int> num);

	std::list <int> calc_jacobsthallSequence(int listSize);
	std::list < std::list <int> > generateGroups(int listSize);

	void execVecAlgorithmHelper(std::vector<int> *c, std::vector<std::vector<int> > a);

	void	binInsertVec(std::vector<int> *c, int end, int insert);
	void	binInsertList(std::list<int> *c, int end, int insert);

	std::list< std::list    <int> >		sortListOfList(std::list< std::list<int> > c);
	std::vector< std::vector<int> >		sortVecOfVec(std::vector< std::vector<int> > c);

	std::list<int> lisOftListAt(std::list< std::list<int> >& l, int index);
	int		listAt(std::list<int> &l, int index);

	void	displayValues(std::list<int> val);
	void	displayValues(std::vector<int> val);
	void	displayValues(std::list< std::list<int> > val);
	void	displayValues(std::vector< std::vector<int> > val);

	void	removeVec(std::vector< std::vector<int> > *c, int removeVal);

	PmergeMe();
	PmergeMe(const PmergeMe &other);


	/**
	 * @brief funtion will separate the input into duos to the
	 * execution of the algorithm
	 */
	template <typename OuterContainer>
	void populate(OuterContainer *out, std::list<int>& num) {
		typedef typename OuterContainer::value_type InnerContainer;

		while (!num.empty())
		{
			InnerContainer b;
			b.push_back(num.front());
			num.pop_front();

			if (!num.empty())
			{
				int temp = num.front();
				// sorting the duos
				if (b.front() < temp)
				{
					// swapping elements
					temp = b.front();
					b.pop_back();
					b.push_back(num.front());
					b.push_back(temp);
				}
				else
					b.push_back(temp);
				num.pop_front();
			}
			out->push_back(b);
		}
	};

public:
	PmergeMe(std::list<int> num);
	~PmergeMe();
};

#endif
