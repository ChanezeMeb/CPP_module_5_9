/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:10:17 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/30 13:22:01 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

//Le but de l'exercice est de faire un template generique qui va chercher
//un int dans tous les conteneurs STL (vector, list etc...)

template <typename T>
typename T::iterator easyfind(T& container, int n);

#include "easyfind.tpp"

#endif