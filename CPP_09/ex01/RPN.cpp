/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:21:55 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/08 11:01:03 by chamebar         ###   ########.fr       */
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
	std::istringstream iss(str);
	std::string token;
	while (iss >> token)
	{
		if (token.size() != 1)
			std::cerr << "Error : digit must be < 10" << std::endl;
		if (!(std::isdigit(token[0]) || token[0] == '+' || token[0] == '-' ||token[0] == '*' || token[0] == '/'))
			std::cerr << "Error : token is not + - * / or digit" << std::endl;
		if (std::isdigit(token[0]))
		{
			_stack.push(token[0] + '0');
		}
		if ((token[0] == '+' || token[0] == '-' ||token[0] == '*' || token[0] == '/') && _stack.size() < 2)
			std::cerr << "Error : Miss operande" << std::endl;
		if (token[0] == '+' || token[0] == '-' ||token[0] == '*' || token[0] == '/')
		{
			int b = _stack.top(); //assigne le top a int b
			_stack.pop(); //supprime le nombre
			int a = _stack.top();
			_stack.pop();
			if (token[0] == '+')
				_stack.push(a + b);
			else if (token[0] == '-')
				_stack.push(a - b);
			else if (token[0] == '*')
				_stack.push(a * b);
			else if (token[0] == '/')
			{
				if (b == 0)
					std::cerr << "Division by zero is impossible." << std::endl;
				_stack.push(a / b);
			}			
		}			
	}
	if (_stack.size() != 1)
		std::cerr << "Operators are missing" << std::endl;
	std::cout << _stack.top() << std::endl;
}