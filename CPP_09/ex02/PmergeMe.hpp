/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:43 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/12 17:25:04 by chamebar         ###   ########.fr       */
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
        void merge(std::vector<std::pair<int, int> > &pairs); //merge pour left et right ??
        //merge sort pour left et right ??
        std::vector<int> jacobSthal(int n); //fonction qui calcule l'indice de jacobsthal
        std::vector<int> insertionOrder(int n);
        void parsing(char**argv); //fonction parsing
    public :
        void displayBefore(); // mettre template dans ces fonctions ?
        void displayAfter();
        void timeVector();
        void timeDeque();
};

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