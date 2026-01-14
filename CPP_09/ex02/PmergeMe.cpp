/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:40 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/14 16:40:41 by chamebar         ###   ########.fr       */
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
        this->_odd = other._odd;
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **argv) : _odd(-1)
{
    parsing(argv);
}

//Parsing
void PmergeMe::parsing(char**argv)
{
    for (int i = 1; argv[i]; i++)
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.size(); j++)
        {
            if(!isdigit(str[j]))
                throw PmergeMe::ErrParse();
        }
        long nb = std::atol(str.c_str());
            
        if (nb < 0 || nb > INT_MAX)
            throw PmergeMe::ErrParse();
            
        for (size_t k = 0; k < _vector.size(); k++)
        {
            if (_vector[k] == nb)
                throw PmergeMe::ErrDup();
        }    
        _vector.push_back(nb);
        _deque.push_back(nb);
        
    }
}

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            throw PmergeMe::ArgMissing();
        }
        PmergeMe test(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

