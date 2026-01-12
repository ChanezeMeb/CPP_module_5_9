/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:43 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/12 17:37:18 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
    private :
        std::vector<int> _vector;
        std::deque<int> _deque;
        int _odd; //Element qui reste en cas de tableau impair
        int _size; //taille du tableau
        std::vector<std::pair<int, int> > makePairs(); //fonction pour faire des pairs
        void mergeSort(std::vector<std::pair<int, int> > &pairs);
        void separateChain(std::vector<std::pair<int, int> > &pair, std::vector<std::pair<int, int> > &mainChain, std::vector<std::pair<int, int> > &pending);
        std::vector<int> jacobSthal(int n); //fonction qui calcule l'indice de jacobsthal
        std::vector<int> insertionOrder(int n);
        void parsing(char**argv); //fonction parsing
    public :
        void displayBefore(); // mettre template dans ces fonctions ?
        void displayAfter();
        void timeVector();
        void timeDeque();
};

// class PmergeMe
// {
// private:
//     std::vector<int> _vector;
//     std::deque<int> _deque;
//     int _odd;
//     int _size;
    
//     // TEMPLATES pour éviter duplication
//     template <typename Container>
//     std::vector<std::pair<int, int>> makePairs(Container& cont);
    
//     template <typename T>
//     void mergeSort(std::vector<std::pair<T, T>>& pairs);
    
//     template <typename T>
//     void merge(std::vector<std::pair<T, T>>& pairs,
//                std::vector<std::pair<T, T>>& left,
//                std::vector<std::pair<T, T>>& right);
    
//     template <typename Container>
//     void separateChains(std::vector<std::pair<int, int>>& pairs,
//                         Container& main,
//                         Container& pend);
    
//     std::vector<int> generateJacobsthal(int n);
//     std::vector<int> generateInsertionOrder(int n);
    
//     template <typename Container>
//     void insertPending(Container& main,
//                        Container& pend,
//                        std::vector<int>& order);
    
//     template <typename Container>
//     void fordJohnsonRecursive(Container& container);

// public:
//     int parsing(int argc, char **argv);
//     void process();
//     void processDeq();
// };

#endif

//Fonction a implementer dans la classe
//L'algorithme de Ford-Johnson qui va se decouper en plusieurs fonctions

//Etape 1 :
//Fonction qui va creer les pairs et les trier ?

//Etape 2 :
//Fonction qui va separer en deux tableaux ? main et pend ?

//Etape 3 : 
//Utilisation de Jacobsthal ?

//Etape 4 :
//Insertion dans l'ordre ?

//Affichage de deque et vector avant et apres le tri
//displayBefore()
//displayAfter()

//Affichage du temps que met chaque container pour trier
//timeVector()
//timeDeque()