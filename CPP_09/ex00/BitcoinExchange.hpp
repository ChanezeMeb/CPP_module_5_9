#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, double> _db;
		
		double get_closest_rate(const std::string& date); //prix retourne
	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void load_csv(const std::string& filename);
		void process(const std::string& filename);
};

std::string trim(const std::string& date);
bool validate_date(const std::string& date);
void parse_line(const std::string& line, std::string& date_out, double& qty_out);

#endif

//ex01 diviser par 0 interdit

// Pour l'exercice 02 echelle de jacobstall + merge insertion sort