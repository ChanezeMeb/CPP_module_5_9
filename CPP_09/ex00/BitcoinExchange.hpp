#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, double> _db;
		void load_csv(const std::string& filename);
		double get_closest_rate(const std::string& date); //prix retourne
	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
};

bool validate_date(const std::string& date);
bool validate_qty(double qty);
void parse_line(const std::string& line, std::string& date_out, double& qty_out);
void process(const std::string& filename);

#endif

//ex01 diviser par 0 interdit

// Pour l'exercice 02 echelle de jacobstall + merge insertion sort