/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:27:55 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 10:39:18 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    srand(time(NULL)); //permet une generation aleatoire a chaque execution
    
    std::cout << "=== Test 1 ===" << std::endl;
    
    Base* random1 = generate();

    std::cout << "Identify by pointer : ";
    identify(random1);
    std::cout << "Identify by reference : ";
    identify(*random1);
    delete random1;

    std::cout << "=== Test 2 ===" << std::endl;
    
    Base* random2 = generate();

    std::cout << "Identify by pointer : ";
    identify(random2);
    std::cout << "Identify by reference : ";
    identify(*random2);
    delete random2;

    std::cout << "=== Test 3 ===" << std::endl;
    
    Base* random3 = generate();

    std::cout << "Identify by pointer : ";
    identify(random3);
    std::cout << "Identify by reference : ";
    identify(*random3);
    delete random3;
    
    return 0;
}