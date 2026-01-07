/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:21:57 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/07 13:03:56 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>

class RPN
{
	private :
		std::stack<int, std::list<int> > _stack;
	public :
		void calculate(const std::string& str);
};

#endif

// Pour l'exercice 02 echelle de jacobstall + merge insertion sort