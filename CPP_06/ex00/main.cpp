/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:48:41 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/18 15:49:14 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Nombre d'argument invalide." << std::endl;
        return 1;
    }
    
    std::string input(argv[1]);
    ScalarConverter::convert(input);
    return 0;
}