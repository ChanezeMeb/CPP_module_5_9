/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:28:19 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/03 16:07:46 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _signed;
    public :
        //Forme canonique
        Form();
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        //Forme avec parametres
        Form(const std::string &name, int gradeToSign, int gradeToExecute);

        //Getters
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        
        //Methode
        void beSigned(const Bureaucrat &bureaucrat);

        //Exceptions
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
};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif