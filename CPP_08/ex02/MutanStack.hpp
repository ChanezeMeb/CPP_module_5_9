/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:46:22 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/30 11:52:36 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

//Stack container LIFO (Last In First Out). Cependant ce container
//n'a pas d'iterator et on va donc devoir creer un container qui herite
//de la classe stack mais qui peut avoir un iterator.

template <typename T>
class MutanStack : public std::stack<T>
{
    public :
        //Le main oblige le typedef. Stack est un template avec T et container (deque)
        //cf le site CPP reference
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        iterator begin();
        iterator end();
        
        
};

#include "MutanStack.tpp"

#endif