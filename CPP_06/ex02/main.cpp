/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:27:55 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 10:28:27 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    srand(time(NULL)); //permet une generation aleatoire a chaque execution
    Base* random = generate();

    std::cout << "Identify by pointer : ";
    identify(random);

    std::cout << "Identify by reference : ";
    identify(*random);

    delete random;
    return 0;
}