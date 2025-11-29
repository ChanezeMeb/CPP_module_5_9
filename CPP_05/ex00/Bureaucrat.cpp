/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:00 by chamebar          #+#    #+#             */
/*   Updated: 2025/11/29 16:25:02 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException("Grade is too hight");
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException("Grade is too low");
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy assigment" << std::endl;
    if(this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

//Methodes
void incrementGrade(); //diminue le chiffre
void decrementGrade(); //augmente le chiffre
        
        //classes d'exceptions imbriquees 
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();

        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();

        };

const char *Bureaucrat::GradeTooHighException
        
