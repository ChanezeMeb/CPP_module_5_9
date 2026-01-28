/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:40 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/28 18:54:58 by chamebar         ###   ########.fr       */
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

void PmergeMe::displayBefore()
{
    std::cout << "Before : ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

//==============================================VECTOR=====================================================

//fonction qui calcule l'indice de jacobsthal
//Les indices Jacobsthal indiquent les moments où 
//une insertion coûte le moins cher en comparaisons
std::vector<int> PmergeMe::jacobSthalVec(int n)
{
    std::vector<int> seq;
    if (n <= 0)
        return seq;
    
    int a = 0;
    int b = 1;
    
    while(true)
    {
        int c = b + 2 * a;
        if (c > n)
            break;
        a = b;
        b = c;
    }

    return seq;
}

//Permet d'avoir l'ordre d'insertion optimal a l'aide de
//la suite de Jacobsthal
//Rempli le tableau order
std::vector<int> PmergeMe::insertionOrderVec(int n)
{
    std::vector<int> jacob = jacobSthalVec(n);
    std::vector<int> order;

    int prev = 0;
    for (size_t i = 0; i < jacob.size(); i++)
    {
        int j = jacob[i];
        for (int k = j; k > prev; k--)
        {
            order.push_back(k);
        }
        prev = j;
    }
    for (int k = prev + 1; k <= n; k++)
        order.push_back(k);

    return order;
}

std::vector<std::pair<int, int> > PmergeMe::makePairsVec()
{
    std::vector<std::pair<int, int> > pairs;
    pairs.reserve(_vector.size() / 2);
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        int a = _vector[i];
        int b = _vector[i+1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    if (_vector.size() % 2 != 0)
        _odd = _vector.back();
    return pairs;
} //fonction pour faire des pairs

//Fonction qui trie les pairs 
void PmergeMe::mergeSortVec(std::vector<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    
    //utiliser reserve pour eviter la reallocation de la memoire ??    
        
    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    mergeSortVec(left);
    mergeSortVec(right);

    //Fusion
    size_t i = 0, j = 0, k = 0;

    // i avance dans left j dans right et k dans pairs
    while (i < left.size() && j < right.size())
    {
        if (left[i].first <= right[j].first)
            pairs[k++] = left[i++];
        else
            pairs[k++] = right[j++];
    }

    while (i < left.size())
        pairs[k++] = left[i++];
        
    while (j < right.size())
        pairs[k++] = right[j++]; 
     
}

void PmergeMe::separateVec(std::vector<std::pair<int, int> > &pair, std::vector<int> &mainChain, std::vector<int> &pend)
{
    if (pair.empty())
        return;
    //reserver l'espace
    mainChain.reserve(pair.size());
    pend.reserve(pair.size());

    //Premier element special
    mainChain.push_back(pair[0].second);
    mainChain.push_back(pair[0].first);
    pend.push_back(pair[0].second); 

    //Le plus grand dans mainChain le plus petit dans pend
    for (size_t i = 1; i < pair.size(); i++)
    {
        mainChain.push_back(pair[i].first);
        pend.push_back(pair[i].second);        
    }
}

void PmergeMe::insertPendVec(std::vector<int> &mainChain, std::vector<int> &pend)
{
    if (pend.empty())
        return;
    
    int n = pend.size();
    std::vector<int> order = insertionOrderVec(n);
    
    for (size_t i = 1; i < order.size(); i++)
    {
        int index = order[i];
        int value = pend[index - 1]; //conversion 1-based 0-based

        //recupere la position a laquelle je dois inserer value
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (_odd != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), _odd);
        mainChain.insert(pos, _odd);
    }
}

void PmergeMe::processVec()
{
    //Affichage avant
    displayBefore();
    
    //Debut du chrono
    clock_t start = clock();
    
    //Algorithme de tri
    std::vector<std::pair<int, int> > pairs = makePairsVec();
    mergeSortVec(pairs);
    
    std::vector<int> mainChain;
    std::vector<int> pend;
    separateVec(pairs, mainChain, pend);

    insertPendVec(mainChain, pend);
    
    //Fin du chrono
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After : ";
    for (size_t i = 0; i < mainChain.size(); i++)
        std::cout << mainChain[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;
    
}


//==============================================DEQUE=====================================================

//fonction qui calcule l'indice de jacobsthal
//Les indices Jacobsthal indiquent les moments où 
//une insertion coûte le moins cher en comparaisons
std::deque<int> PmergeMe::jacobSthalDeq(int n)
{
    std::deque<int> seq;
    if (n <= 0)
        return seq;
    
    int a = 0;
    int b = 1;
    
    while(true)
    {
        int c = b + 2 * a;
        if (c > n)
            break;
        a = b;
        b = c;
    }

    return seq;
}

//Permet d'avoir l'ordre d'insertion optimal a l'aide de
//la suite de Jacobsthal
//Rempli le tableau order
std::deque<int> PmergeMe::insertionOrderDeq(int n)
{
    std::deque<int> jacob = jacobSthalDeq(n);
    std::deque<int> order;

    int prev = 0;
    for (size_t i = 0; i < jacob.size(); i++)
    {
        int j = jacob[i];
        for (int k = j; k > prev; k--)
        {
            order.push_back(k);
        }
        prev = j;
    }
    for (int k = prev + 1; k <= n; k++)
        order.push_back(k);

    return order;
}

std::deque<std::pair<int, int> > PmergeMe::makePairsDeq()
{
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        int a = _deque[i];
        int b = _deque[i+1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    if (_deque.size() % 2 != 0)
        _odd = _deque.back();
    return pairs;
} //fonction pour faire des pairs

//Fonction qui trie les pairs 
void PmergeMe::mergeSortDeq(std::deque<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    
    //utiliser reserve pour eviter la reallocation de la memoire ??    
        
    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    mergeSortDeq(left);
    mergeSortDeq(right);

    //Fusion
    size_t i = 0, j = 0, k = 0;

    // i avance dans left j dans right et k dans pairs
    while (i < left.size() && j < right.size())
    {
        if (left[i].first <= right[j].first)
            pairs[k++] = left[i++];
        else
            pairs[k++] = right[j++];
    }

    while (i < left.size())
        pairs[k++] = left[i++];
        
    while (j < right.size())
        pairs[k++] = right[j++]; 
     
}

void PmergeMe::separateDeq(std::deque<std::pair<int, int> > &pair, std::deque<int> &mainChain, std::deque<int> &pend)
{
    if (pair.empty())
        return;

    //Premier element special
    mainChain.push_back(pair[0].second);
    mainChain.push_back(pair[0].first);
    pend.push_back(pair[0].second); 

    //Le plus grand dans mainChain le plus petit dans pend
    for (size_t i = 1; i < pair.size(); i++)
    {
        mainChain.push_back(pair[i].first);
        pend.push_back(pair[i].second);        
    }
}

void PmergeMe::insertPendDeq(std::deque<int> &mainChain, std::deque<int> &pend)
{
    if (pend.empty())
        return;
    
    int n = pend.size();
    std::deque<int> order = insertionOrderDeq(n);
    
    for (size_t i = 1; i < order.size(); i++)
    {
        int index = order[i];
        int value = pend[index - 1]; //conversion 1-based 0-based

        //recupere la position a laquelle je dois inserer value
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }
    
    if (_odd != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), _odd);
        mainChain.insert(pos, _odd);
    }
}

void PmergeMe::processDeq()
{
    //Affichage avant
    displayBefore();
    
    //Debut du chrono
    clock_t start = clock();
    
    //Algorithme de tri
    std::deque<std::pair<int, int> > pairs = makePairsDeq();
    mergeSortDeq(pairs);
    
    std::deque<int> mainChain;
    std::deque<int> pend;
    separateDeq(pairs, mainChain, pend);

    insertPendDeq(mainChain, pend);
    
    //Fin du chrono
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After : ";
    for (size_t i = 0; i < mainChain.size(); i++)
        std::cout << mainChain[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;
    
}
        

// int main(int argc, char **argv)
// {
//     try
//     {
//         if (argc < 2)
//         {
//             throw PmergeMe::ArgMissing();
//         }
//         PmergeMe test(argv);
//         test.processVec();
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return 0;
// }

