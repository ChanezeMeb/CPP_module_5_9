/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:28:16 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/01 14:41:41 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
    std::cout << "Form parametric constructor" << std::endl;
    if (gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150)
        throw GradeTooLowException();
    if (gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _signed(other._signed)
{
    std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Form copy assigment" << std::endl;
    if(this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
}

const std::string Form::getName() const
{
    return this->_name;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

bool Form::isSigned() const
{
    return this->_signed;
}

const char* Form::GradeTooHighException::what() const throw()
{
      return ("Grade too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
      return ("Grade too low !");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << std::boolalpha;
    os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << ", sign " << form.isSigned() << ".";
    return os;
}