/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:06 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/01 14:38:51 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private :
        const std::string _name;
        int _grade;
    public :
        //Forme canonique
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        //Constructeur avec parametres en plus de la forme canonique
        Bureaucrat(const std::string& name, int grade);
        
        //Getters
        const std::string getName() const;
        int getGrade() const;
        
        //Methodes
        void incrementGrade(); //diminue le chiffre
        void decrementGrade(); //augmente le chiffre
        void signForm(Form &form); //bureaucrat qui essaie de signer le formulaire
        
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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif

