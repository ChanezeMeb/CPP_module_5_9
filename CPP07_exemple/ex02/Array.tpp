#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(0), _n(0) {}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_data;
}

template <typename T>
Array<T>::Array(const Array<T> &copy) : _data(0), _n(copy._n)
{
	if (_n > 0)
	{
		this->_data = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			this->_data[i] = copy._data[i];
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _n(n)
{
	if (_n > 0)
		_data = new T[_n];
}


template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete [] this->_data;
		this->_n = rhs._n;
		this->_data = 0;
		if (this->_n > 0)
		{
			this->_data = new T[this->_n];
			for (unsigned int i = 0; i < this->_n; i++)
				this->_data[i] = rhs._data[i];
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_n)
		throw (std::out_of_range("Index out of range"));
	return (this->_data[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_n)
		throw (std::out_of_range("Index out of range"));
	return (this->_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_n);
}

#endif
