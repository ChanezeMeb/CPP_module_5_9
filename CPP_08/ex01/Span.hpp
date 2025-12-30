/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:02:55 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/30 13:35:22 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>

class Span
{
    private :
        unsigned int _maxSize;
        std::vector<int> _data;
    public :
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int nb);
        
        template <typename Iterator>
        void addNumber(Iterator first, Iterator last);
        
        unsigned int shortestSpan();
        unsigned int longestSpan();
        unsigned int size() const;
};

//distance calcule le nombre d'elements entre deux iterateurs
template <typename Iterator>
void Span::addNumber(Iterator first, Iterator last)
{
	size_t count = std::distance(first, last);
	if (_data.size() + count > _maxSize)
		throw std::exception();
    for (Iterator it = first; it != last; ++it)
        addNumber(*it);
}

#endif