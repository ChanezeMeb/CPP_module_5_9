/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:02:49 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/30 13:24:42 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    // Test 10k OBLIGATOIRE
    std::cout << "\n=== Test 10 000 nombres ===" << std::endl;
    Span sp_big(10001);  // capacité 10k+1
    
    std::vector<int> source(10000);
    srand(time(NULL));  // seed random
    
    for (size_t i = 0; i < 10000; ++i) {
        source[i] = rand() % 1000000;  // nombres 0-999999
    }
    
    sp_big.addNumber(source.begin(), source.end());  // range iterator !
    
    std::cout << "shortestSpan : " << sp_big.shortestSpan() << std::endl;
    std::cout << "longestSpan  : " << sp_big.longestSpan() << std::endl;

    return 0;
}

