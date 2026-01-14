/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:43 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/14 10:38:06 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>

class PmergeMe
{
    private :
        std::vector<int> _vector;
        std::deque<int> _deque;
        int _odd; //Element qui reste en cas de tableau impair

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
        
        std::vector<int> jacobSthal(int n); //fonction qui calcule l'indice de jacobsthal
        std::vector<int> insertionOrder(int n);
        void parsing(char**argv); //fonction parsing
    public :
        PmergeMe(char** argv);
        void processVec();
        void processDeq();
        void displayBefore(); 
        void displayAfterVec();
        void displayAfterDeq();
        void timeVector();
        void timeDeque();

        //Forme canonique
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
};

#endif

//j'ai deja _odd pour l'element impair. Pourquoi avoir besoin de mergeVec alors qu'on a deja mergeSortVec ? Je peux appeler en recursif non ? pourrais tu  me reexpliquer la suite de Jacobsthal, insertPendVec et le binary sreach ? Pourquoi avoir besoin de argc ? Si dans le main je mets if argc < 2 error je n'en ai plus besoin par la suite.