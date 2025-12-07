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
    return 0;
}