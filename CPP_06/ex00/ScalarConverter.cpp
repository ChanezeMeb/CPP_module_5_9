/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:48:38 by chamebar          #+#    #+#             */
/*   Updated: 2025/12/17 13:53:36 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Objectif de l'exercice convertir une entree (string). Les 4 sorties obligatoire sont char, int, float, double
// Decoupage en 4 etapes pour faire l'exercice

// Etape 1 : Est ce que l'entree est exploitable ? exemple inexploitable : --42 / 12f3. Si l'entree n'est pas valide afficher tout impossible
// Faire une fonction isValid qui verifie.

// Etape 2 : Est-ce un pseudo litteral ? Si oui gestion differente si non passage a l'etape 3.


// Etape 3 : Identification du type de depart. On ne convertit pas pour l'instant on regarde juste si au depart c'etait un char, un int, un float, ou un double.

// Regles simpes d'identification :

// longueur == 1 && pas un chiffre  --> char
// fini par f 						--> float
// contient un . 					--> double
// sinon 							--> int

// Etape 4 : On convertit dans cette etape. Si la string etait un char : 'a' -> char c = 'a' puis on convertit le reste. int -> (static_cast<int>(c)), float -> (static_cast<float>(c)), double -> (static_cast<double>(c))