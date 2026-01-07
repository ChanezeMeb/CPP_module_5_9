/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:21:55 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/07 13:29:31 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

 //Je lis ma string token par token en utilisant istringsream ?
 //Puis token[0] doit etre == 1 et doit etre un digit ou + - / * ?
 //Si c'est un operateur mais que ma stack n'a pas deux nombres c'est une erreur 
 //sinon quand j'ai un operateur je fais b = pop a = pop et je calcule a operateur b
 // a la fin je verifie que je n'ai qu'un nombre
 //si plusieurs nombre manque des operateurs
 //si plusieurs stack vide manque des operandes
 //diviser par 0 interdit

void RPN::calculate(const std::string& str)
{
	while (&str != '\0')
	{
		std::istringstream iss(str);
		std::string token;
		iss >> token;
		if (token.size() != 1)
			std::cerr << "Error : digit must be < 10" << std::endl;
		if (!std::isdigit(token[0]) || token[0] != '+' || token[0] != '-' ||token[0] != '*' || token[0] != '/')
			std::cerr << "Error : token is not + - * / or digit" << std::endl;
	}
}