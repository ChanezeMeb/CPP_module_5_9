/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:02:52 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/29 23:09:58 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <climits>

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data)
{}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int nb)
{
    if (_data.size() >= _maxSize)
        throw std::exception();
    _data.push_back(nb);
}

// template <typename Iterator>
// void Span::addNumber(Iterator first, Iterator last)
// {
//     for (Iterator it = first; it != last; ++it)
//         addNumber(*it);
// }

unsigned int Span::shortestSpan()
{
    int minDiff;
    if (_data.size() < 2)
        throw std::exception();
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    minDiff = INT_MAX;
    for (size_t i = 0; i < tmp.size() -1; ++i)
    {
        minDiff = std::min(minDiff, tmp[i+1]-tmp[i]);
    }
    return static_cast<unsigned int>(minDiff);
}

unsigned int Span::longestSpan()
{
    if (_data.size() < 2)
        throw std::exception();
    std::vector<int>::iterator it_max = std::max_element(_data.begin(), _data.end());
    std::vector<int>::iterator it_min = std::min_element(_data.begin(), _data.end());
    return (*it_max - *it_min);
}

unsigned int Span::size() const
{
    return _data.size();
}