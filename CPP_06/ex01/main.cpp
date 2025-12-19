/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:10:06 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 08:46:27 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.value = 42;
    
    Data *originalPtr = &data;
    uintptr_t raw;
    Data *autrePtr;
    
    raw = Serializer::serialize(originalPtr);
    std::cout << originalPtr << std::endl;
    std::cout << raw << std::endl;
    
    autrePtr = Serializer::deserialize(raw);
    std::cout << autrePtr << std::endl;
    std::cout << raw << std::endl;
    
    return 0;
}