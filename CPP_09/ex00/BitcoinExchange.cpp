/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamebar <chamebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:10 by chamebar          #+#    #+#             */
/*   Updated: 2026/01/07 12:18:22 by chamebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <string>

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
	std::ifstream file(filename.c_str());
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

//Fonction permettant de recuperer la date precedente si une
//date provenant d'input.txt n'existe pas dans data.csv
double BitcoinExchange::get_closest_rate(const std::string& date)
{
	std::map<std::string, double>::iterator it = _db.upper_bound(date);
	if (it == _db.begin())
		throw std::runtime_error("Error : no rate before date");
	--it;
	return it->second;
} //prix retourne

//Verifie si une annee est bissextile
static bool leap_year(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

bool validate_date(const std::string& date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	int day_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (leap_year(year))
	{
		day_in_month[2] = 29;
	}
	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > day_in_month[month])
		return false;
	return true;
}

// trim la date pour bien avoir un format 
// "2022-10-20" et non " 2022-10-20 " car sinon 
//validate date ne fonctionne pas (mauvaise longueur)
std::string trim(const std::string& date)
{
	std::string newDate;
	size_t start, end;
	start = date.find_first_not_of(" \t");
	end = date.find_last_not_of(" \t");
	if (start == std::string::npos)
		return "";
	newDate = date.substr(start, end - start + 1);
	return newDate;
}

//Recupere la date ainsi que les quantite tout en trimant la date
void parse_line(const std::string& line, std::string& date_out, double& qty_out)
{
		std::istringstream iss(line);
		std::getline(iss, date_out, '|');
		date_out = trim(date_out);
		iss >> qty_out;
}

//Permet de lire le fichier input
//De proceder au parsing et affiche le resultat
void BitcoinExchange::process(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error : Could not open file.");
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
		if (qty < 0)
		{
			std::cerr << "Error : not a positive number." << std::endl;
			continue;
		}
		if (qty > 1000)
		{
			std::cerr << "Error : too large number." << std::endl;
			continue;
		}
		price = get_closest_rate(date); 
		std::cout << date << " => " << qty << " = " << qty * price << std::endl;
	}
}
