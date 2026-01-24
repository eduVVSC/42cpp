#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <iterator>
# include <ctime>

class PmergeMe{
private:
	displayValues(std::list<int> val);
	std::vector <int> execVecAlgorithm(std::list<int> num);
	std::list   <int> execListAlgorithm(std::list<int> num);

	std::vector <int> execVecAlgorithmHelper(std::vector<int> &c, std::vector<std::vector<int>> a);
	std::list   <int> execListAlgorithmHelper(std::list<int> &c, std::list<std::list<int>> a);

	void	insertVec(std::vector<int> &c, int insert);
	void	insertList(std::list<int> &c, int insert);

	PmergeMe();
	PmergeMe(const PmergeMe &other);

public:
	PmergeMe(std::list<int> num);
	~PmergeMe();
}

#endif
