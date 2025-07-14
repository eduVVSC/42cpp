#ifndef EASYDINF_HPP
# define EASYDINF_HPP

# include <exception>
# include <iostream>
# include <string>
# include <typeinfo>

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

class NotValidTypeException : public std::exception {
private:
	std::string message;
public:
	NotValidTypeException(const std::string& msg){
		this->message = msg;
	}

	virtual const char* what() const throw(){
		return (this->message.c_str());
	}

	~NotValidTypeException() throw(){}
};

template <typename T>
int easyfind(T *array, int num){
	if (typeid(*array) != typeid(int))
		throw NotValidTypeException("The entered array is not an integer holder!");
	while (array)
	{
		if (*array == num)
			return (num);
		array++;
	}
	throw NotFoundException("The wanted number was not found!");
}

#endif
