/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:09:10 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 11:12:17 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//uintptr = unsigned int pointeur : C'est un type assez grand pour
// contenir un pointeur. Il garantit de stocker l'adresse de
// l'objet sans perte de donnees.

//reinterpret_cast sert à réinterpréter les bits d’un objet comme 
//un autre type, sans changer les bits eux-mêmes.

// +------------+                  +----------------+
// |  Data* ptr | --serialize-->   | uintptr_t raw  |
// | 0x7FF1234  |                  | 0x7FF1234      |
// +------------+                  +----------------+
//        ^                                 |
//        |                                 v
//        +---deserialize-------------------+
//        |                                 |
//        |                                 |
//        v                                 v
// +------------+                  +----------------+
// |  Data* ptr |                  | uintptr_t raw  |
// | 0x7FF1234  |                  | 0x7FF1234      |
// +------------+                  +----------------+

// serialize(ptr)   : reinterpret_cast<uintptr_t>(ptr)
// deserialize(raw) : reinterpret_cast<Data*>(raw)


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

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}


