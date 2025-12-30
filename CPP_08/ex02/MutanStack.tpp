/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:59:41 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/30 11:04:47 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"

iterator MutanStack::begin()
{
    return this->c.begin();
}

iterator MutanStack::end()
{
    return this->c.end();
}