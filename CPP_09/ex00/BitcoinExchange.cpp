/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:10 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/05 18:38:12 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>


// Chaque ligne doit avoir un format date | bitcoin
// La date doit etre annee mois jour

//Parsing de la date a faire

//que des nombres verifier que c'est une date possible + annee bisextile

//Parsing des donnees float ou int entre 0 et 1000

// Il faut utiliser un container : map container ?

//La sortie devra etre le resultat de la multiplication entre 
//la valeur du bitcoin dans mon fichier * la valeur du bitcoin dans la database.
// Si la date recherchee n'existe pas dans la database je dois 
//chercher la date la plus proche (inferieure).

//Lecture du fichier ligne par ligne avec getline

//deux fichiers : .csv va etre stocke dans une map puis 
//dans le programme on lit chaque ligne, calcule et affiche.

//std::istringstream est un outil pour parser (découper)
//une chaîne de caractères comme si c'était du clavier (cin), mais sur une string fixe.

//getline peut lire jusqu'a , ou |

//Etape 1 :

//Parsing data.csv => Remplir map avec les donnees de .csv
// Utiliser istringstream / getline jusqu'a , et stocker dans 
// string / double

//Etape 2 :

//Parsing input.txt => Utiliser istringstream / getline jusqu'a |
//Faire la multiplication date => qty * prix = total

// Etape 3 :

// Validation dates/qty + erreurs

// Etape 4 :

// Polish verification date si pas trouve (upper bound)
// Tests


//===========================================================================================

// Forme canonique

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
    {
        this->_db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


//std::ifstream = un flux d’entrée (input stream) qui lit des caractères depuis un fichier sur le disque,
//un peu comme std::cin lit depuis le clavier.
//ifstream file(filename) ouvre le fichier dont le nom est stocke dans filename
//file est un objet representant le fichier ouvert. On peut lire dedans avec getline par exemple

//getline lit jusqu'au \n et stocke dans un std::string

//std::istringstream = un flux d’entrée, mais au lieu de lire dans un fichier
// ou depuis le clavier, il lit dans une string.
void BitcoinExchange::load_csv(const std::string& filename)
{
	std::ifstream file(filename);
	std::string line;
	
	std::getline(file, line);
	while(std::getline(file, line))
	{
		std::string date;
		double price;
		
		std::istringstream iss(line);
		std::getline(iss, date, ',');
		iss >> price;
		
		if(validate_date(date))
			_db[date] = price;
	}
}

double BitcoinExchange::get_closest_rate(const std::string& date)
{

} //prix retourne

bool validate_date(const std::string& date)
{

}

bool validate_qty(double qty)
{

}

void parse_line(const std::string& line, std::string& date_out, double& qty_out)
{

}

void process(const std::string& filename)
{

}
