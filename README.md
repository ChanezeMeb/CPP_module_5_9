# CPP Modules 00 - 04 : Fondamentaux de la Programmation Orientée Objet

## 📖 À propos

Ce repository contient mes solutions pour les modules CPP 00 à 04 de l'école 42 Paris. Ces cinq modules constituent une introduction progressive et complète aux concepts fondamentaux de la programmation orientée objet en C++98, couvrant les namespaces, les classes, l'héritage, le polymorphisme, et les bonnes pratiques du langage C++.

## 🎓 Modules inclus

### Module 00 : Namespace, classe, fonction membre, stdio stream, initialisation de liste
Premiers pas en C++ avec introduction aux namespaces et aux classes. Couverture des flux d'entrée/sortie et de l'initialisation des membres.

**Concepts clés :** Namespaces, classes basiques, membres publics/privés, constructeurs, destructeurs

### Module 01 : Mémoire, pointeurs, références
Gestion complète de la mémoire, distinction entre pointeurs et références, allocation dynamique avec `new` et `delete`.

**Concepts clés :** Allocation mémoire, pointeurs, références, heap vs stack, memory leaks

### Module 02 : Polyaddition, héritage, polymorphisme ad-hoc
Introduction à l'héritage de classes et surcharge d'opérateurs pour implémenter le polymorphisme ad-hoc.

**Concepts clés :** Héritage simple, surcharge d'opérateurs, constructeur de copie, opérateur d'assignation

### Module 03 : Héritage
Approfondissement de l'héritage avec classes virtuelles et polymorphisme de type.

**Concepts clés :** Héritage multiple, fonctions virtuelles, destructeurs virtuels

### Module 04 : Polymorphisme en sous-typage
Polymorphisme en sous-typage avec classes abstraites et interfaces, substituabilité de Liskov.

**Concepts clés :** Classes abstraites, fonctions pures virtuelles, polymorphisme dynamique

## 🛠️ Technologie et environnement

- **Langage :** C++98
- **Compilateur :** c++
- **Système d'exploitation :** Linux (testé sur Ubuntu et Linux de l'école 42)
- **Restrictions importantes :**
  - ❌ Pas de `using namespace std;` dans les fichiers `.hpp` (headers)
  - ✅ Les `using namespace` sont acceptés dans les fichiers `.cpp`
  - ✅ La meilleure pratique est d'utiliser `std::` explicitement (ex: `std::cout`)
  - ❌ Pas de C++11 ou versions ultérieures

## 📋 Instructions de compilation

### Prérequis
- c++ avec support C++98
- make (optionnel, mais recommandé)
- Linux/Unix (macOS compatible)

### Compilation simple
```bash
# Naviguer vers le dossier du module
cd cpp00  # ou cpp01, cpp02, etc.

# Compiler avec make
