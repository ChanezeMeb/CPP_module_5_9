/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:18:54 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/01 12:19:45 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ## Résumé visuel

// ┌─────────────────────────────────────┐
// │  main()                             │
// │  ┌───────────────────────────────┐  │
// │  │ try {                         │  │
// │  │   checkGrade(151);            │  │
// │  │ }                             │  │
// │  └───────────────┬───────────────┘  │
// │                  │                  │
// │  ┌───────────────▼───────────────┐  │
// │  │ checkGrade(int grade)         │  │
// │  │   if (grade > 150)            │  │
// │  │     throw Exception(); ◄──────┼──┐ throw lance l'exception
// │  └───────────────┬───────────────┘  │
// │                  │                  │
// │                  │ L'exception      │
// │                  │ remonte          │
// │                  ▼                  │
// │  ┌───────────────────────────────┐  │
// │  │ catch (exception& e) {        │  │
// │  │   cout << e.what();           │  │ catch l'attrape
// │  │ }                             │  │
// │  └───────────────────────────────┘  │
// └─────────────────────────────────────┘

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

    std::cout << "\n=== TEST 5bis: incrementGrade (invalide) ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << "Avant: " << bob << std::endl;
        
        bob.incrementGrade();  // 2 -> 1
        std::cout << "Après increment: " << bob << std::endl;
        
        bob.incrementGrade();  // 1 -> 0
        std::cout << "Après 2e increment: " << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 6bis: decrementGrade (invalide) ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 150);
        std::cout << "Avant: " << bob << std::endl;
        
        bob.decrementGrade();  // 150 -> 151
        std::cout << "Après decrement: " << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
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

    std::cout << "\n=== TEST 8: Exception - Grade trop bas (construction) ===" << std::endl;
    try
    {
        Bureaucrat invalid("Invalid", 151);  // Grade invalide !
        std::cout << invalid << std::endl;  // Ne s'affiche pas
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 9: Grade limite valide (1 et 150) ===" << std::endl;
    try
    {
        Bureaucrat best("Best", 1);
        Bureaucrat worst("Worst", 150);
        
        std::cout << best << std::endl;
        std::cout << worst << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 10: Catches multiples (spécifiques) ===" << std::endl;
    try
    {
        Bureaucrat test("Test", 0);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "GradeTooHighException attrapée: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "GradeTooLowException attrapée: " << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Autre exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== FIN DES TESTS ===" << std::endl;
    
    return 0;
}