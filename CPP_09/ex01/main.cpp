/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:22:32 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/08 10:58:44 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage : ./RPN \"7 2 0 8...\"" << std::endl;
        return 1;
    }
    RPN stack;
    stack.calculate(argv[1]);
    return 0;
}