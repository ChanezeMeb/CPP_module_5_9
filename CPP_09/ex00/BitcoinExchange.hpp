#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

std::map<std::string, double> load_csv(const std::string& filename);
bool validate_date(const std::string date);
bool validate_qty(int qty);


#endif