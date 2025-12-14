/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:28:19 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/03 22:08:25 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _signed;
    public :
        //Forme canonique
        AForm();
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        ~AForm();

        //Forme avec parametres
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);

        //Getters
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        
        //Methode
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public :
                virtual const char *what() const throw();

        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);


#endif