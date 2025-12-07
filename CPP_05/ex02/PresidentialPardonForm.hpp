#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string _target;
    public :
         //Forme canonique
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        //Forme avec parametres
        PresidentialPardonForm(const std::string &target);

        virtual void execute(Bureaucrat const &executor) const;
};

#endif