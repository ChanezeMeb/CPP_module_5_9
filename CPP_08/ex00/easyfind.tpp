/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:42:49 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/05 18:33:52 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Un iterateur en C++ est une abstraction d'un pointeur qui permet de parcourir
//les elements d'un conteneur de maniere uniforme et securisee
//Il en existe different type en fonction du type de conteneur
//vector list et deque auront des iterateurs differents.

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == n)
            return (it);
    }
    throw std::exception();
}

//find algo qui cherche n entre begin et end

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
        if (it == container.end())
            throw std::exception();
    return (it);
}