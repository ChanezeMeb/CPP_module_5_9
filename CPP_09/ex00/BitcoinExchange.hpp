#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

//Creer une classe car la forme canonique est demande.

std::map<std::string, double> load_csv(const std::string& filename);
bool validate_date(const std::string date);
bool validate_qty(int qty);


#endif