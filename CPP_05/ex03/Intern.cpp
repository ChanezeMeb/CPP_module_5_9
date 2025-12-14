/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:45:15 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/14 16:04:39 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::CreateShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::CreateRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::CreatePresidentialPardonForm(const std::string &target)
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

AForm* Intern::makeForm(const std::string& forName, const std::string& target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (*creators[4])(const s)
}
