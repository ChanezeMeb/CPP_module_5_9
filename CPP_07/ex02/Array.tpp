/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 07:20:23 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/22 13:27:42 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
    this->_array = new T[_n];
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(0), _n(other._n)
{
    if (_n > 0)
	{
		this->_array = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete [] this->_array;
		this->_n = other->_n;
		this->_array = new T[this->_n];
		for (unsigned int i = 0; i < this->_n; i++)
			this->_array[i] = other->_array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete [] this->_array;
}

//operator[] est la surcharge des crochets qui permet
//d'acceder aux elements comme un tableau natif
//Exemple : arr[2] = 42; int x = arr[2]. Il retourne
//une reference T& pour permettre lecture et ecriture directement.

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_n)
		throw std::exception();
	return this->_array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_n)
		throw std::exception();
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_n);
}