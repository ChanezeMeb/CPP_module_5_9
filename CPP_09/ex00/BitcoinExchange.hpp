#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

//Creer une classe car la forme canonique est demande.
//Voici le flux 

// main()
// └── BitcoinExchange("data.csv")  // ctor public
//     └── load_csv("data.csv")     // privé : remplit _db map

// └── btc.process("input.txt")     // public : traite TOUT fichier
//     ├── boucle getline(ligne) {
//     │   ├── parse ligne → date|qty  // istringstream privé
//     │   ├── validate_date(date)     // static public/util
//     │   ├── validate_qty(qty)       // static public/util
//     │   ├── get_closest_rate(date)  // privé : upper_bound → prix
//     │   └── qty * rate → cout       // format sujet
//     │   }
//     └── erreurs "bad input"/"too large"
std::map<std::string, double> load_csv(const std::string& filename);
bool validate_date(const std::string& date);
bool validate_qty(double qty);
void parse_line(const std::string& line, std::string& date_out, double& qty_out);
void process(const std::string& filename);
double get_closest_rate(const std::string& date); //prix retourne

#endif