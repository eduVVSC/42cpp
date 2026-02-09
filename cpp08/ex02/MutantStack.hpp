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
    typedef typename container::const_iterator const_iterator;
    
    // Non-const versions
    iterator begin() {
        return this->c.begin();
    }
    
    iterator end() {
        return this->c.end();
    }
    
    // Const versions
    const_iterator begin() const {
        return this->c.begin();
    }
    
    const_iterator end() const {
        return this->c.end();
    }
    
    MutantStack() : stack() { }
    MutantStack(const MutantStack &src) : stack(src) { }
    ~MutantStack() { }
    
    MutantStack &operator=(const MutantStack &src) {
        if (this != &src)
            stack::operator=(src);
        return *this;
    }
};

#endif