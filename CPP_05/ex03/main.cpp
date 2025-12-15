/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:46:56 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/15 13:44:39 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    srand(time(NULL));
    std::cout << "\n=== TEST 1: Intern creates Presidential Pardon ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Intern intern;
        
        AForm* form = intern.makeForm("presidential pardon", "Arthur");
        
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Robotomy Request - Succes ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Eloise");
    
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Shrubbery Creation Form - Succes ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Intern intern; 
        AForm* form = intern.makeForm("shrubbery creation", "Anne");
    
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Unknown Form - Succes ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Intern intern; 
        AForm* form = intern.makeForm("does'nt exist", "Anne");
    
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}