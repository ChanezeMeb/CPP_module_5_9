/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:54:04 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/21 21:46:18 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T &x)
{
    std::cout << x << std::endl;
}

void incrementInt(int &x)
{
    x++;
}

void upper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main(void)
{
    std::cout << "=== Test avec int ===" << std::endl;
    int arr_int[] = {1, 2, 3, 4};
    iter(arr_int, 4, print<int>);
    
    std::cout << "\n=== Test avec modification ===" << std::endl;
    int arr_int2[] = {10, 20, 30};
    std::cout << "Avant:" << std::endl;
    iter(arr_int2, 3, print<int>);
    iter(arr_int2, 3, incrementInt);
    std::cout << "Apres increment:" << std::endl;
    iter(arr_int2, 3, print<int>);
    
    std::cout << "\n=== Test avec char ===" << std::endl;
    char arr_char[] = {'a', 'b', 'c'};
    std::cout << "Avant:" << std::endl;
    iter(arr_char, 3, print<char>);
    iter(arr_char, 3, upper);
    std::cout << "Apres upper:" << std::endl;
    iter(arr_char, 3, print<char>);
    
    std::cout << "\n=== Test avec string ===" << std::endl;
    std::string arr_str[] = {"hello", "world", "42"};
    iter(arr_str, 3, print<std::string>);
    
    std::cout << "\n=== Test avec float ===" << std::endl;
    float arr_float[] = {1.1f, 2.2f, 3.3f};
    iter(arr_float, 3, print<float>);

    return 0;
}