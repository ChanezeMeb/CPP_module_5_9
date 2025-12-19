/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:10:06 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/19 07:46:42 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.value = 42;
    
    Serializer::serialize(&data);
    std::cout << &data << std::endl;
    Serializer::deserialize();
    std::cout <<  << std::endl;
    
    return 0;
}