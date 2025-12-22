/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 07:20:19 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/22 07:42:54 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
    private :
        T   *_array;
        unsigned int _n;
    public :
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        
        //operator[] est la surcharge des crochets qui permet
        //d'acceder aux elements comme un tableau natif
        //Exemple : arr[2] = 42; int x = arr[2]. Il retourne
        //une reference T& pour permettre lecture et ecriture directement.
        T &operator[](unsigned int n); //pour modifier non const
        const T &operator[](unsigned int n) const; //pour lire const
        unsigned int size() const;
};

#include <Array.tpp>

#endif ARRAY_HPP