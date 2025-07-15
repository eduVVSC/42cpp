#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;

	iterator begin() {
		return (stack::c.begin());
	}

	iterator end() {
		return (stack::c.end());
	}

	MutantStack() : stack() { }

	MutantStack(const stack &src) : stack(src) { }

	~MutantStack() { }

	stack &operator=(const stack &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}
};

#endif
