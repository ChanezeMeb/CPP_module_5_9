#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	public:
		Array();
		~Array();
		Array(const Array &copy);
		explicit Array(unsigned int n);
		Array &operator=(const Array &rhs);
		
		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;
		unsigned int size() const;

	private:
		T				*_data;
		unsigned int	_n;
};

#include "Array.tpp"

#endif
