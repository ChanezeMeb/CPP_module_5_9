/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:02:55 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/29 16:40:32 by chamebar         ###   ########.fr       */
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

#endif