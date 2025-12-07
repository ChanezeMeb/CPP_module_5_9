/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:33:54 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/03 17:18:24 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== TEST FORM ===" << std::endl;
    
    std::cout << "\n=== TEST 1 : Constructeur valide===" << std::endl;
    {
        Form form("testform", 50, 20);
        std::cout << form << std::endl;
    }

    std::cout << "\n=== TEST 2 : Constructeur par defaut===" << std::endl;
    {
        Form defaultForm;
        std::cout << defaultForm << std::endl;
    }

    std::cout << "\n=== TEST 3 : Constructeur par copie===" << std::endl;
    {
        Form test("test", 25, 15);
        std::cout << "Original : " << test << std::endl;

        Form copy(test);
        std::cout << "Copie : " << copy << std::endl;
    }

    std::cout << "\n=== TEST 4: Opérateur d'affectation ===" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        Form a("FormA", 50, 25);
        Form b("FormB", 100, 75);
        
        boss.signForm(a);
        
        std::cout << "Avant affectation:" << std::endl;
        std::cout << "  " << a << std::endl;
        std::cout << "  " << b << std::endl;
        
        b = a;  // b garde son nom mais prend le statut de a
        
        std::cout << "Après affectation (b = a):" << std::endl;
        std::cout << "  " << a << std::endl;
        std::cout << "  " << b << std::endl;
    }

    //Tests exceptions SFP
    
    std::cout << "\n=== TEST 5: Exception - Grade to sign trop haut ===" << std::endl;
    try
    {
        Form invalid("Invalid", 0, 50);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Exception - Grade to sign trop bas ===" << std::endl;
    try
    {
        Form invalid("Invalid", 151, 50);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Exception - Grade to execute trop haut ===" << std::endl;
    try
    {
        Form invalid("Invalid", 50, 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 8: Exception - Grade to execute trop bas ===" << std::endl;
    try
    {
        Form invalid("Invalid", 50, 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    //Tests interaction bureaucrat + form

     std::cout << "\n=== TEST 9: Bureaucrat signe un formulaire (succès) ===" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        Form formA("FormA", 100, 50);  // Bob peut signer (50 < 100)
        
        std::cout << "Avant signature : " << formA << std::endl;
        bob.signForm(formA);
        std::cout << "Après signature : " << formA << std::endl;
    }

    std::cout << "\n=== TEST 10: Bureaucrat ne peut pas signer (grade insuffisant) ===" << std::endl;
    {
        Bureaucrat intern("Intern", 100);
        Form formB("FormB", 50, 25);  // Intern ne peut pas signer (100 > 50)
        
        std::cout << "Avant tentative : " << formB << std::endl;
        intern.signForm(formB);  // Va échouer
        std::cout << "Après tentative : " << formB << std::endl;
    }
    
     std::cout << "\n=== TEST 11: Plusieurs bureaucrates signent différents formulaires ===" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat employee("Employee", 75);
        Bureaucrat intern("Intern", 150);
        
        Form easyForm("EasyForm", 100, 100);
        Form mediumForm("MediumForm", 50, 50);
        Form hardForm("HardForm", 1, 1);
        
        // Boss peut tout signer
        boss.signForm(easyForm);
        boss.signForm(mediumForm);
        boss.signForm(hardForm);
        
        std::cout << std::endl;
        
        // Employee peut signer les formulaires faciles
        employee.signForm(easyForm);  // Déjà signé mais peut re-signer
        
        std::cout << std::endl;
        
        // Intern ne peut rien signer
        intern.signForm(easyForm);
    }

    std::cout << "\n=== TEST 12: Signer un formulaire déjà signé ===" << std::endl;
    {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 40);
        Form form("TestForm", 100, 50);
        
        alice.signForm(form);
        std::cout << "Statut après Alice : " << form << std::endl;
        
        bob.signForm(form);  // Déjà signé
        std::cout << "Statut après Bob : " << form << std::endl;
    }

    std::cout << "\n=== TEST 13: Grades limites (1 et 150) ===" << std::endl;
    {
        Form formMin("FormMin", 1, 1);
        Form formMax("FormMax", 150, 150);
        
        Bureaucrat best("Best", 1);
        Bureaucrat worst("Worst", 150);
        
        std::cout << formMin << std::endl;
        std::cout << formMax << std::endl;
        
        best.signForm(formMin);
        best.signForm(formMax);
        
        worst.signForm(formMin);
        worst.signForm(formMax);
    }

    std::cout << "\n=== TEST 14: beSigned() appelé directement ===" << std::endl;
    try
    {
        Bureaucrat jim("Jim", 75);
        Form form("DirectForm", 100, 50);
        
        std::cout << "Avant beSigned : " << form << std::endl;
        form.beSigned(jim);  // Appel direct
        std::cout << "Après beSigned : " << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
    
     std::cout << "\n=== TEST 15: beSigned() échoue (grade insuffisant) ===" << std::endl;
    try
    {
        Bureaucrat lowGrade("LowGrade", 100);
        Form form("HardForm", 50, 25);
        
        std::cout << "Avant beSigned : " << form << std::endl;
        form.beSigned(lowGrade);  // Va lancer une exception
        std::cout << "Cette ligne ne s'affiche pas" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    
    return 0;
}