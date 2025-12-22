/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 07:20:23 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/22 09:02:18 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
    this->_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(0), _n(other._n)
{
    
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{

}

template <typename T>
Array<T>::~Array()
{
    
}

//operator[] est la surcharge des crochets qui permet
//d'acceder aux elements comme un tableau natif
//Exemple : arr[2] = 42; int x = arr[2]. Il retourne
//une reference T& pour permettre lecture et ecriture directement.

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (this->_n > index)
		throw 
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_n);
}