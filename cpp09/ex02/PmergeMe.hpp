#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <iterator>
# include <ctime>

class PmergeMe{
private:
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
					b.push_front(temp);
				else
					b.push_back(temp);
				num.pop_front();
			}
			out->push_back(b);
		}
	};

	std::vector <int> execVecAlgorithm(std::list<int> num);
	std::list   <int> execListAlgorithm(std::list<int> num);

	std::vector <int> execVecAlgorithmHelper(std::vector<int> *c, std::vector<std::vector<int> > a);
	std::list   <int> execListAlgorithmHelper(std::list<int> *c, std::list<std::list<int> > a);

	void	insertVec(std::vector<int> *c, int insert);
	void	insertList(std::list<int> *c, int insert);


	std::list< std::list<int> >	sortListOfList(std::list< std::list<int> > c);

	int		listAt(std::list<int> l, int index);

	void	displayValues(std::list<int> val);
	void	displayValues(std::list< std::list<int> > val);

	PmergeMe();
	PmergeMe(const PmergeMe &other);

public:
	PmergeMe(std::list<int> num);
	~PmergeMe();
};

#endif
