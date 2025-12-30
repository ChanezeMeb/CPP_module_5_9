/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:59:41 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/30 11:54:33 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"

template <typename T>
typename MutanStack<T>::iterator MutanStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutanStack<T>::iterator MutanStack<T>::end()
{
    return this->c.end();
}