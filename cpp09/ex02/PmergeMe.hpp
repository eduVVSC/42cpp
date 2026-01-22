#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <iostream>
# include <ctime>

class PmergeMe{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);

public:
	PmergeMe(std::list<int> num);
	~PmergeMe();
}

#endif
