/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:48:38 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 11:21:56 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy constructor" << std::endl;
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy assignement" << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor" << std::endl;
}


// Objectif de l'exercice convertir une entree (string). Les 4 sorties obligatoire sont char, int, float, double
// Decoupage en 4 etapes pour faire l'exercice

// Etape 1 : Est ce que l'entree est exploitable ? exemple inexploitable : --42 / 12f3. Si l'entree n'est pas valide afficher tout impossible
// Faire une fonction isValid qui verifie.

bool isPseudoLiteral(const std::string& str);

bool isValid(const std::string& str)
{
    int point = 0;
    int f = 0;
    int sign = 0;
    
    if (str.empty())
        return false;
        
    if (str.length() == 1)
        return true;
        
    if (isPseudoLiteral(str))
        return true;
        
    for (size_t i = 0; i < str.length(); i++)
    {
        char c = str[i];
        
        if (!isdigit(c) && c != '.' && c != 'f' && c != '-' && c != '+')
            return false;
        
        if (c == '.')
            point++;
            
        if (c == 'f')
        {
            f++;
            if (i != str.length() - 1)
                return false;
        }

        if (c == '+' || c == '-')
        {
            sign++;
            if (i != 0)
                return false;
        }
        
        if (point > 1 || f > 1 || sign > 1)
            return false;
    }
    
    return true;
}

// Etape 2 : Est-ce un pseudo litteral ? Si oui gestion differente si non passage a l'etape 3.


bool isPseudoLiteral(const std::string& str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        return true;
    return false;
}

// Etape 3 : Identification du type de depart. On ne convertit pas pour l'instant on regarde juste si au depart c'etait un char, un int, un float, ou un double.
// Structure enum Type dans le .h

// Regles simpes d'identification :

// longueur == 1 && pas un chiffre  --> char
// fini par f 						--> float
// contient un . 					--> double
// sinon 							--> int
Type getType(const std::string& str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return TYPE_CHAR;

    if (str.find('.') != std::string::npos)
    {
        if (str[str.length() - 1] == 'f')
            return TYPE_FLOAT;
        return TYPE_DOUBLE;
    }
    return TYPE_INT;
}

// Etape 4 : On convertit dans cette etape. Si la string etait un char : 
//'a' -> char c = 'a' puis on convertit le reste. 
//int -> (static_cast<int>(c)), float -> (static_cast<float>(c)), double -> (static_cast<double>(c))

// Il y a des fonctions d'affichage et des fonctions de conversion pour separer les responsabilites.

void printChar(char c, bool isPossible = true)
{
    if (!isPossible)
        std::cout << "char : impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : '" << c << "'" << std::endl; 
}

void printInt(int i, bool isPossible = true)
{
    if (!isPossible)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << i << std::endl;
}

void printFloat(float f, bool isPossible = true)
{
    if (!isPossible)
        std::cout << "float : impossibble" << std::endl;
    else
        std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble(double d, bool isPossible = true)
{
    if (!isPossible)
        std::cout << "double : impossibble" << std::endl;
    else
        std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertFromChar(const std::string& str)
{
    char c = str[0];
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void convertFromInt(const std::string& str)
{
    int i;
    std::stringstream ss(str);
    ss >> i;

    if (i < 0 || i > 127)
        printChar('c', false);
    else
        printChar(static_cast<char>(i));
    
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void convertFromFloat(const std::string& str)
{
    float f;
    std::stringstream ss(str);
    ss >> f;

    if (f < 0 || f > 127 || f != static_cast<int>(f))
        printChar('c', false);
    else
        printChar(static_cast<char>(f));

    if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        printInt(0, false);
    else
        printInt(static_cast<int>(f));
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void convertFromDouble(const std::string& str)
{
    double d;
    std::stringstream ss(str);
    ss >> d;

    if (d < 0 || d > 127 || d != static_cast<int>(d))
        printChar('c', false);
    else
        printChar(static_cast<char>(d));

    if (d < INT_MIN || d > INT_MAX)
        printInt(0, false);
    else
        printInt(static_cast<int>(d));
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::convert(std::string& str)
{
    if (!isValid(str))
    {
        printChar('c', false);
        printInt(0, false);
        printFloat(0, false);
        printDouble(0, false);
        return ;
    }

    if (isPseudoLiteral(str))
    {
        //Cas special char et int impossible
        printChar('c', false);
        printInt(0, false);
        
        if (str == "nanf" || str == "+inff" || str == "-inff")
        {
            std::cout << "float : " << str << std::endl;
            std::cout << "double : " << str.substr(0, str.length() - 1) << std::endl;
        }
        else
        {
            std::cout << "float : " << str << "f" << std::endl;
            std::cout << "double : " << str << std::endl;
        }
        return ;
    }
    
    Type type = getType(str);
    
    switch (type)
    {
        case TYPE_CHAR:
            convertFromChar(str);
            break;
        case TYPE_INT:
            convertFromInt(str);
            break;
        case TYPE_FLOAT:
            convertFromFloat(str);
            break;
        case TYPE_DOUBLE:
            convertFromDouble(str);
            break;
    }
}
