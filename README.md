
# CPP Modules 05 - 09 : Concepts Avancés de la Programmation C++

## 📖 À propos

Ce repository contient mes solutions pour les modules CPP 05 à 09 de l'école 42 Paris. Ces cinq modules constituent une progression vers les concepts avancés de la programmation orientée objet en C++98, couvrant la gestion des exceptions, les casting spécialisés, la programmation générique par templates, la Standard Template Library, et les algorithmes sophistiqués.

## 🎓 Modules inclus

### Module 05 : Exception, essayer/attraper/lancer, RAII

Maîtrise complète de la gestion des exceptions en C++. Ce module introduit le paradigme du try/catch/throw et les principes fondamentaux de RAII (Resource Acquisition Is Initialization), essentiels pour écrire du code robuste et sécurisé en matière de gestion des ressources. Vous apprendrez comment les exceptions modifient le flux d'exécution et comment les utiliser pour signaler les conditions d'erreur de manière appropriée.

**Concepts clés :** Exceptions, try/catch/throw, std::exception, hiérarchie d'exceptions, RAII, garanties d'exception

### Module 06 : Casting C++, RTTI

Exploration des quatre types de casting C++ : static_cast, dynamic_cast, const_cast et reinterpret_cast. Ce module vous enseigne comment utiliser le casting de type de manière sûre et correcte, ainsi que les principes du RTTI (Run-Time Type Information) pour déterminer le type d'un objet à l'exécution. Vous comprendrez les implications de performance et de sécurité de chaque approche.

**Concepts clés :** static_cast, dynamic_cast, const_cast, reinterpret_cast, RTTI, typeid, polymorphisme de type

### Module 07 : Template, specialisation de template

Introduction à la programmation générique par templates. Ce module couvre les templates de fonctions et de classes, permettant d'écrire du code réutilisable pour différents types de données sans sacrifier la sécurité des types. Vous apprendrez également la spécialisation de templates pour optimiser le code pour des types particuliers.

**Concepts clés :** Templates génériques, spécialisation, instanciation de templates, paramètres templates, templates implicites

### Module 08 : STL containers, itérateurs

Découverte en profondeur de la Standard Template Library. Ce module enseigne comment utiliser efficacement les conteneurs STL (vector, list, deque, map, set) et les itérateurs pour manipuler les données. Vous apprendrez les différences de performance et les cas d'usage appropriés pour chaque conteneur.

**Concepts clés :** Conteneurs STL (vector, list, map, set), itérateurs, complexité algorithmique, allocateurs, adaptateurs de conteneurs

### Module 09 : Algorithmes STL, functors, complexité O(n)

Maîtrise des algorithmes fournis par la STL pour effectuer des opérations courantes sur les conteneurs. Ce module couvre les algorithmes de tri, recherche, transformation, et les functors (objets fonction) pour personnaliser le comportement des algorithmes. L'analyse de la complexité O(n) devient critique à ce stade.

**Concepts clés :** Algorithmes STL (sort, find, for_each, transform), functors, objets fonction, complexité, prédicats

## 🛠️ Technologie et environnement

- **Langage :** C++98 (avec STL)
- **Compilateur :** c++
- **Système d'exploitation :** Linux (testé sur Ubuntu et Linux de l'école 42)
- **Restrictions importantes :**
  - ❌ Pas de `using namespace std;` dans les fichiers `.hpp` (headers)
  - ✅ Les `using namespace` sont acceptés dans les fichiers `.cpp`
  - ✅ La meilleure pratique est d'utiliser `std::` explicitement
  - ❌ Pas de C++11 ou versions ultérieures
  - ✅ STL autorisée et fortement recommandée (modules 08-09)

## 📋 Instructions de compilation

### Prérequis
- c++ avec support C++98
- make (optionnel, mais recommandé)
- Linux/Unix (macOS compatible)

### Compilation simple
```bash
# Naviguer vers le dossier du module
cd cpp05  # ou cpp06, cpp07, cpp08, cpp09

# Compiler avec make
make

# Exécuter
./executable_name

# Nettoyer
make clean    # Supprime les fichiers .o
make fclean   # Supprime tout (exécutable + .o)
make re       # Recompile tout
