/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:53:29 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/11 12:23:06 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

// personalized exception
class IndexOutOfBounds : public std::exception {
private:
    std::string message;

public:
	// Constructor accepting const char*
	IndexOutOfBounds(const std::string& msg) { this->message = msg; }

	// Override what() method, marked
	virtual const char* what( void ) const throw() { return message.c_str(); }

	virtual ~IndexOutOfBounds() throw() { }
};


template < typename T>
class Array{
private:
	T		*array;
	int	length;

	// can only be used when arrays are of the same size
	void copyItems(const Array &other) {
		for (int i = 0; i < other.size(); i++)
			this->array[i] = other[i];
	}

public:
	// ======= Operators

	T& operator[](int pos){
		if (pos > length || pos < 0)
			throw IndexOutOfBounds("Position entered outside the array.");
		return (array[pos]);
	}

	/// @brief  Allocates memory and copies one array to another
	/// @param other
	Array &operator=(Array const &other) {
		if (this->array != NULL){  // see if this will work
			delete [] this->array;
		}
		this->length = other.size();
		this->array = new T[other.size()];
		copyItems(other);
		return (this);
	}

	// ======= Getter

	int size( void ) const { return (this->length); }

	T& getIndexValue(int index) { return (array[index]); }

	// ======= Constructors
	Array(int n) {
		this->length = n;
		this->array = new T[n];
	}

	Array(const Array &other) {
		*this = *other; // using equal operator asignment
	}

	Array( void ) {
		this->length = 0;
		this->array = new T[0];
	}

	~Array() {}
};


// added to make it easier to test it
template <typename T>
//std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
std::ostream& operator<<(std::ostream& os, Array<T>& arr){
	os << "[";
		for (int i = 0; i < arr.size(); ++i) {
			os << arr.getIndexValue(i);
			if (i != arr.size() - 1)
				os << ", ";
		}
    os << "]";
	return (os);
}

#endif
