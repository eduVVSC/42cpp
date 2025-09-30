#ifndef EASYDINF_HPP
# define EASYDINF_HPP

# include <exception>
# include <iostream>
# include <string>
# include <typeinfo>
# include <algorithm>

class NotFoundException : public std::exception {
private:
	std::string message;
public:
	NotFoundException(const std::string& msg){
		this->message = msg;
	}

	virtual const char* what() const throw(){
		return (this->message.c_str());
	}

	~NotFoundException() throw(){}
};


template < typename T >
typename T::iterator easyfind(T &array, int num){

	typename T::iterator it;

	it = std::find(array.begin(), array.end(), num);

	if (it == array.end())
		throw NotFoundException("The wanted number was not found!");

	return (it);
}

#endif
