/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:17:48 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/21 21:22:29 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    std::cout << "\n=== Tests du sujet ===" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    std::cout << "\n=== Tests avec float ===" << std::endl;
    float f1 = 42.5f;
    float f2 = 21.3f;
    std::cout << "Avant swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    ::swap(f1, f2);
    std::cout << "Après swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    
    std::cout << "\n=== Tests avec char ===" << std::endl;
    char ch1 = 'z';
    char ch2 = 'a';
    ::swap(ch1, ch2);
    std::cout << "ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
    std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;
    return 0;
}
