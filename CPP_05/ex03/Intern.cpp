/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:45:15 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/15 12:05:47 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern()
{
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern copy assigment" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (Intern::*formCreators[3])(const std::string &target) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cerr << "Error : Form \"" << formName << "\" does'nt exist" << std::endl;
	return (NULL);
}
