/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:42:49 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/29 11:44:30 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// template <typename T>
// typename T::iterator easyfind(T& container, int n)
// {
//     typename T::iterator it = std::find(container.begin(), container.end(), n);
//         if (it == container.end())
//             throw std::exception();
//     return (it);
// }