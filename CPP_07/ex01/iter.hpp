/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:40:53 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/21 20:57:43 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t len, F f)
{
    if (!array || len == 0)
        return;
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

#endif