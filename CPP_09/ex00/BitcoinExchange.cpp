#include "BitcoinExchange.hpp"

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
