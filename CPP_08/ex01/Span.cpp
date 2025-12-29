/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:02:52 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/29 17:12:37 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data)
{}

Span &operator=(const Span &other)
{}

Span::~Span()
{}


        std::vector<int> _data;
        
        

        void addNumber(int nb);
        
        template <typename Iterator>
        void addNumber(Iterator first, Iterator last);
        
        unsigned int shortestSpan();
        unsigned int longestSpan();
        unsigned int size() const;