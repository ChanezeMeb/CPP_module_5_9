/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:40 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/14 15:04:42 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42

// Entrée: [5, 2, 9, 1, 7, 3, 8, 6]

// ÉTAPE 1 - Créer des paires et trier chaque paire
// -----------------------------------------------
// Paires: [(5,2), (9,1), (7,3), (8,6)]
//          ↓
// Trier chaque paire (plus grand en premier):
// [(5,2), (9,1), (7,3), (8,6)]  ✓ Déjà triées

// ÉTAPE 2 - Trier les paires selon leur plus grand élément (récursivement)
// ------------------------------------------------------------------------
// On trie selon: 5, 9, 7, 8
// Résultat: [(5,2), (7,3), (8,6), (9,1)]

// ÉTAPE 3 - Séparer en mainChain et pend
// ---------------------------------------
// mainChain: [5, 7, 8, 9]  (tous les plus grands)
// pend:      [2, 3, 6, 1]  (tous les plus petits)

// ÉTAPE 4 - Insérer le premier élément de pend
// --------------------------------------------
// Le premier élément de pend (2) correspond au plus grand de la première paire (5)
// On sait que 2 < 5, donc on l'insère directement au début:
// mainChain: [2, 5, 7, 8, 9]

// ÉTAPE 5 - Insérer les autres éléments selon Jacobsthal
// ------------------------------------------------------
// Jacobsthal pour n=3 restants: 3, 2, 1
// (La suite de Jacobsthal: 1, 1, 3, 5, 11, 21...)

// Ordre d'insertion: pend[2], pend[1], pend[0]
//                    = 6,      3,      (déjà inséré)

// Insérer 6 (recherche binaire dans [2,5,7,8]):
// mainChain: [2, 5, 6, 7, 8, 9]

// Insérer 3 (recherche binaire dans [2,5,6]):
// mainChain: [2, 3, 5, 6, 7, 8, 9]

// Résultat final: [1, 2, 3, 5, 6, 7, 8, 9]

//Forme canonique
PmergeMe::PmergeMe() : _odd(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _odd(other._odd),  _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
        this->_odd = other._odd;
    }
}

PmergeMe::~PmergeMe() {}

//Parsing
void PmergeMe::parsing(char**argv)
{
    for (int i = 1; argv[i]; i++)
    {
        std::string str = argv[i];
        for (int j = 0; j < str.size(); j++)
        {
            if(!isdigit(str[j]))
            {
                throw PmergeMe::ErrParse();
            }
        }
        long nb = std::atol(str.c_str());
        for (int k = 0; k < str.size(); k++)
        {
            if (nb < 0 || nb > INT_MAX)
            {
                throw PmergeMe::ErrParse();
            }
        }

        for (size_t l = 0; l < _vector.size(); l++)
        {
            if (_vector[l] = nb)
                throw PmergeMe::ErrDup();
        }
    }
}

