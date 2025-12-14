/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:46:56 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/14 14:46:57 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    srand(time(NULL));
    std::cout << "\n=== TEST 1: Presidential Pardon - Succes ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);  // Peut tout faire
        PresidentialPardonForm pardon("Arthur");
    
        std::cout << pardon << std::endl;  // Affiche le formulaire
    
        boss.signForm(pardon);      // Boss signe
        boss.executeForm(pardon);   // Boss execute
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Robotomy Request - Succes ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);  // Peut tout faire
        RobotomyRequestForm robotomy("Pierre");
    
        std::cout << robotomy << std::endl;  // Affiche le formulaire
    
        boss.signForm(robotomy);      // Boss signe
        boss.executeForm(robotomy);   // Boss execute
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Shrubbery Creation Form - Succes ===" << std::endl;
    try
    {
        Bureaucrat random("Random", 100); 
        ShrubberyCreationForm shrubbery("Feuille");
    
        std::cout << shrubbery << std::endl;  // Affiche le formulaire
    
        random.signForm(shrubbery);
        random.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Presidential Pardon - Sans signature ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);  // Peut tout faire
        PresidentialPardonForm pardon("Arthur");
    
        std::cout << pardon << std::endl;  // Affiche le formulaire
    
        boss.executeForm(pardon);   // Boss execute
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Robotomy Request - Sans signature ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);  // Peut tout faire
        RobotomyRequestForm robotomy("Pierre");
    
        std::cout << robotomy << std::endl;  // Affiche le formulaire
    
        boss.executeForm(robotomy);   // Boss execute
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Shrubbery Creation Form - Sans signature ===" << std::endl;
    try
    {
        Bureaucrat random("Random", 100); 
        ShrubberyCreationForm shrubbery("Feuille");
    
        std::cout << shrubbery << std::endl;  // Affiche le formulaire
    
        random.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Presidential Pardon - Grade insuffisant ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 150);
        PresidentialPardonForm pardon("Arthur");
    
        std::cout << pardon << std::endl;  // Affiche le formulaire
    
        boss.signForm(pardon);      // Boss signe
        boss.executeForm(pardon);   // Boss execute
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 8: Robotomy Request - Grade trop bas ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 150);
        RobotomyRequestForm robotomy("Pierre");
    
        std::cout << robotomy << std::endl;  // Affiche le formulaire
    
        boss.signForm(robotomy);      // Boss signe
        boss.executeForm(robotomy);   // Boss execute
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 9: Shrubbery Creation Form - Grade pile poil ===" << std::endl;
    try
    {
        Bureaucrat random("Random", 145); 
        ShrubberyCreationForm shrubbery("Feuille");
    
        std::cout << shrubbery << std::endl;  // Affiche le formulaire
    
        random.signForm(shrubbery);
        random.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 10: Shrubbery Creation Form - Grade trop bas ===" << std::endl;
    try
    {
        Bureaucrat random("Random", 146); 
        ShrubberyCreationForm shrubbery("Feuille");
    
        std::cout << shrubbery << std::endl;  // Affiche le formulaire
    
        random.signForm(shrubbery);
        random.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 11: Robotomy - Grade trop bas pour executer ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1); 
        Bureaucrat worker("Worker", 100);
        RobotomyRequestForm robot("Target");
    
        std::cout << robot << std::endl;  // Affiche le formulaire
    
        boss.signForm(robot);
        worker.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 12: Grade 137 peut executer Shrubbery ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);           // Pour signer
        Bureaucrat executor("Executor", 137); // Grade pile poil pour exécuter
        ShrubberyCreationForm shrub("garden");
    
        std::cout << shrub << std::endl;
    
        boss.signForm(shrub);
        executor.executeForm(shrub);  // Doit marcher ✅
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 13: Robotomy multiple fois (random 50%) ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Marvin");
        
        boss.signForm(robot);
        
        std::cout << "\n--- Tentative 1 ---" << std::endl;
        boss.executeForm(robot);
        
        std::cout << "\n--- Tentative 2 ---" << std::endl;
        boss.executeForm(robot);
        
        std::cout << "\n--- Tentative 3 ---" << std::endl;
        boss.executeForm(robot);
        
        std::cout << "\n--- Tentative 4 ---" << std::endl;
        boss.executeForm(robot);
        
        std::cout << "\n--- Tentative 5 ---" << std::endl;
        boss.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 14: Plusieurs fichiers Shrubbery ===" << std::endl;
    try
    {
        Bureaucrat gardener("Gardener", 100);
        
        ShrubberyCreationForm shrub1("home");
        ShrubberyCreationForm shrub2("garden");
        ShrubberyCreationForm shrub3("park");
        
        std::cout << "\n--- Fichier 1: home_shrubbery ---" << std::endl;
        gardener.signForm(shrub1);
        gardener.executeForm(shrub1);
        
        std::cout << "\n--- Fichier 2: garden_shrubbery ---" << std::endl;
        gardener.signForm(shrub2);
        gardener.executeForm(shrub2);
        
        std::cout << "\n--- Fichier 3: park_shrubbery ---" << std::endl;
        gardener.signForm(shrub3);
        gardener.executeForm(shrub3);
        
        std::cout << "\nVerifie que 3 fichiers ont ete crees:" << std::endl;
        std::cout << "  - home_shrubbery" << std::endl;
        std::cout << "  - garden_shrubbery" << std::endl;
        std::cout << "  - park_shrubbery" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}