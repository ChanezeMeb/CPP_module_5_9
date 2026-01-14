/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:40 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/14 10:42:19 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42

//Forme canonique
PmergeMe::PmergeMe() : _odd(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _odd(other._odd),  _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
        this->_odd = other._odd;
    }
}

PmergeMe::~PmergeMe() {}

//Parsing
void parsing(char**argv)
{
    for (int i = 1; argv[i]; i++)
    {
        std::string str = argv[i];
        for (int j = 0; j < str.size(); j++)
        {
            
        }
    }
    
}

