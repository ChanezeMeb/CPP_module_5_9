/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:09:10 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 07:29:35 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer()
{
    std::cout << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Serializer copy constructor" << std::endl;
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    std::cout << "Serializer copy assignement" << std::endl;
    (void)other;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor" << std::endl;
}

static uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

static uintptr_t deserialize(uintptr_t raw)
{
    return (reinterpret_cast<uintptr_t>(raw));
}


