/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:10:06 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 10:41:37 by chamebar         ###   ########.fr       */
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
    
    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Original value: " << originalPtr->value << std::endl;

    raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized (raw) " << raw << std::endl;
    
    autrePtr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << autrePtr << std::endl;
    std::cout << "Deserialized value: " << autrePtr->value << std::endl;
    
    return 0;
}