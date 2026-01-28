/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:43 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/28 18:32:19 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <algorithm>

class PmergeMe
{
    private :
        int _odd; //Element qui reste en cas de tableau impair
        std::vector<int> _vector;
        std::deque<int> _deque;
        //Ford-Johnson VECTOR
        std::vector<std::pair<int, int> > makePairsVec(); //fonction pour faire des pairs
        void mergeSortVec(std::vector<std::pair<int, int> > &pairs);
        void separateVec(std::vector<std::pair<int, int> > &pair, std::vector<int> &mainChain, std::vector<int> &pend);
        void insertPendVec(std::vector<int> &mainChain, std::vector<int> &pend);
        //Ford-Johnson DEQUE
        std::deque<std::pair<int, int> > makePairsDeq(); //fonction pour faire des pairs
        void mergeSortDeq(std::deque<std::pair<int, int> > &pairs);
        void separateDeq(std::deque<std::pair<int, int> > &pair, std::deque<int> &mainChain, std::deque<int> &pend);
        void insertPendDeq(std::deque<int> &mainChain, std::deque<int> &pend);
        
        std::vector<int> jacobSthalVec(int n); //fonction qui calcule l'indice de jacobsthal
        std::vector<int> insertionOrderVec(int n);

        std::deque<int> jacobSthalDeq(int n); //fonction qui calcule l'indice de jacobsthal
        std::deque<int> insertionOrderDeq(int n);
        void parsing(char**argv); //fonction parsing
    public :
        
        void processVec();
        void processDeq();
        void displayBefore(); 

        //Forme canonique
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        //Constructeur avec variable
        PmergeMe(char** argv);
        class ErrParse : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Argument not valid");
                };
        };

        class ErrDup : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Argument duplicate");
                };
        };

        class ArgMissing : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Usage : /PmergeMe arguments");
                };
        };
};


#endif
