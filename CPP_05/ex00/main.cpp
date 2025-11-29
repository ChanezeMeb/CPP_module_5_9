/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:18:54 by chamebar          #+#    #+#             */
/*   Updated: 2025/11/29 22:23:47 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== TEST BUREAUCRAT ===" << std::endl;
    
    std::cout << "\n=== TEST 1 : Constructeur valide===" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
    }

    std::cout << "\n=== TEST 2 : Constructeur par defaut===" << std::endl;
    {
        Bureaucrat defaultBureaucrat;
        std::cout << defaultBureaucrat << std::endl;
    }

    std::cout << "\n=== TEST 3 : Constructeur par copie===" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        std::cout << "Original : " << bob << std::endl;

        Bureaucrat copy(bob);
        std::cout << "Copie : " << copy << std::endl;
    }

    std::cout << "\n=== TEST 4: Opérateur d'affectation ===" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        Bureaucrat jim("Jim", 100);
        
        std::cout << "Avant: " << jim << std::endl;
        jim = bob;  // Opérateur d'affectation
        std::cout << "Après: " << jim << std::endl;
    }

    std::cout << "\n=== TEST 5: incrementGrade (valide) ===" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        std::cout << "Avant: " << bob << std::endl;
        
        bob.incrementGrade();  // 50 -> 49
        std::cout << "Après increment: " << bob << std::endl;
        
        bob.incrementGrade();  // 49 -> 48
        std::cout << "Après 2e increment: " << bob << std::endl;
    }
    
    std::cout << "\n=== TEST 6: decrementGrade (valide) ===" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        std::cout << "Avant: " << bob << std::endl;
        
        bob.decrementGrade();  // 50 -> 51
        std::cout << "Après decrement: " << bob << std::endl;
    }

    std::cout << "\n=== TEST 7: Exception - Grade trop haut (construction) ===" << std::endl;
    try
    {
        Bureaucrat invalid("Invalid", 0);  // Grade invalide !
        std::cout << invalid << std::endl;  // Ne s'affiche pas
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    
    return 0;
}