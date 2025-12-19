/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:28:00 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 10:27:32 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base destructor" << std::endl;
}

Base* generate(void)
{
    int r = rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
        return;
    }
    else
    {
        std::cout << "C" << std::endl;
        return;
    }
}

void identify(Base& p)
{
    Base *ptr = &p;

    if (dynamic_cast<A*>(ptr))
    {
        std::cout << "A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(ptr))
    {
        std::cout << "B" << std::endl;
        return;
    }
    else
    {
        std::cout << "C" << std::endl;
        return;
    }
}