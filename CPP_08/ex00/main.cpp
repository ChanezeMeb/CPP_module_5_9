/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:10:14 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/29 11:49:59 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main (void)
{
    std::cout << "=== Test avec vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(8);
    std::vector<int>::iterator it = easyfind(vec, 5);
    std::cout << "La valeur trouvee est : " << *it << std::endl;
    
    try
    {
        std::vector<int> vec;
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(8);
        std::vector<int>::iterator it = easyfind(vec, 9);
        std::cout << "La valeur trouvee est : " << *it << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::vector<int> vec;
        std::vector<int>::iterator it = easyfind(vec, 9);
        std::cout << "La valeur trouvee est : " << *it << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "=== Test avec list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(2);
    lst.push_back(95);
    lst.push_back(84);
    std::list<int>::iterator ite = easyfind(lst, 84);
    std::cout << "La valeur trouvee est : " << *ite << std::endl;

    try
    {
        std::list<int> lst;
        lst.push_back(2);
        lst.push_back(95);
        lst.push_back(84);
        std::list<int>::iterator ite = easyfind(lst, 5);
        std::cout << "La valeur trouvee est : " << *ite << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}