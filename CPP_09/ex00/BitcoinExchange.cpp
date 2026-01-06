/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:10 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/06 19:19:05 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <map>


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
	if (!file.is_open())
		throw std::runtime_error("Error : Could not load csv.");
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
	std::map<std::string, double>::iterator it = _db.upper_bound(date);
	if (it == _db.begin())
		throw std::runtime_error("Error : no rate before date");
	--it;
	return it->second;
} //prix retourne

bool validate_date(const std::string& date)
{
	//1) verifier le format (size = 10)
	//2) verifier date[4] et date [7] == -
	//3) diviser en year month day
	//4) verifier year > 2009
	// tableau de max_day_of_month
	//fonction qui verifie si bissextile
	//month compris entre 0 et 12
	// day > 1
	// day doit etre inferieur ou egal a max_day_of_months
}

bool validate_qty(double qty)
{
	if (qty >= 0 && qty <= 1000)
		return true;
	return false;
}

void parse_line(const std::string& line, std::string& date_out, double& qty_out)
{
		std::istringstream iss(line);
		std::getline(iss, date_out, '|');
		iss >> qty_out;
}

void process(const std::string& filename)
{
	std::ifstream file(filename);
	std::string line;
	
	std::getline(file, line);
	while(std::getline(file, line))
	{
		std::string date;
		double qty;
		double price;
		parse_line(line, date, qty);
		if (!validate_date(date))
		{
			std::cerr << "Error : bad input => " << date << std::endl;
			continue;
		}
		if (!validate_qty(qty))
		{
			std::cerr << "Error : bad quantity" << std::endl;
			continue;
		}
		price = get_closest_rate(date); 
		std::cout << date << " => " << qty << " = " << qty * price << std::endl;
	}
}
