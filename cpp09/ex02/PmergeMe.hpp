#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <sys/time.h>

class PmergeMe{
private:

	std::vector <int> execVecAlgorithm(std::list<int> num);
	std::list   <int> execListAlgorithm(std::list<int> num);

	void execVecAlgorithmHelper(std::vector<int> *c, std::vector<std::vector<int> > a);
	void execListAlgorithmHelper(std::list<int> *c, std::list<std::list<int> > a);

	void	insertVec(std::vector<int> *c, int pos, int insert);

	void	binInsertVec(std::vector<int> *c, int end, int insert);
	void	binInsertList(std::list<int> *c, int end, int insert);

	std::list< std::list    <int> >		sortListOfList(std::list< std::list<int> > c);
	std::vector< std::vector<int> >		sortVecOfVec(std::vector< std::vector<int> > c);

	int		listAt(std::list<int> l, int index);
	int		vecAt(std::vector<int> v, int index);

	void	displayValues(std::list<int> val);
	void	displayValues(std::vector<int> val);
	void	displayValues(std::list< std::list<int> > val);
	void	displayValues(std::vector< std::vector<int> > val);

	void	removeVec(std::vector< std::vector<int> > *c, int removeVal);

	PmergeMe();
	PmergeMe(const PmergeMe &other);


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
