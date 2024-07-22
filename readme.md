# Benchmark Algorithm

## Description

Benchmark Algorithm est un projet en C++ conçu pour évaluer et comparer les performances de divers algorithmes sur une variété de jeux de tests. Ce projet vise à offrir une solution modulaire et extensible pour tester et analyser les algorithmes en termes de temps d'exécution.

## Fonctionnalités

- Ajoutez facilement de nouveaux algorithmes et jeux de tests grâce à une architecture flexible.
- Générez des rapports sur les performances détaillés.
- Support de multiples jeux de tests, générés aléatoirement ou écrits à la main.
- Modularité sur les types d'entrée et de sortie avec la possibilité d'implémenter facilement une fonction de comparaison et d'affichage de résultats pour les jeux de tests.

## Fonctionnalités prévues

- Ajout de structures de données comme les arbres, linked lists, etc., avec leurs fonctions de vérification dédiées.
- Mesure de la quantité de mémoire consommée.
- Interface graphique.

## Configuration

### Ajouter un nouvel algorithme

- Faites une copie du fichier **"Algorithm/TemplateAlgorithm.cpp"**, par exemple, **"AlgorithmeA.cpp"**.
- Remplacez toutes les occurrences de **TemplateAlgorithm** par un nom de classe unique.
- Implémentez votre algorithme dans la méthode **`run`** (Pour l'entrée de l'algorithme, voir [ici](#modifier-le-type-de-données-dentrée-et-de-sortie)).
- Dans le fichier **"Algorithm/Algorithm.h"**, à l'avant-dernière ligne, incluez le fichier avec `#include "AlgorithmA.cpp"`.
- Instanciez la classe dans le fichier **"main.cpp"**, dans le vecteur `algorithms` avec `new AlgorithmA<Input, Output>("name")`.

### Ajouter un nouveau jeu de tests

- Dans le fichier **"main.cpp"**, il y a un vecteur `testCases` qui permet d'ajouter de nouveaux jeux de tests.
- Vous pouvez les ajouter manuellement avec `TC(Input, result)`
- Vous pouvez les générer automatiquement si vous avez créé une fonction de génération, voir [ici](#crée-une-fonction-de-génération-de-jeu-de-test)

### Modifier le type de données d'entrée et de sortie

Dans le fichier **"main.cpp"**, vous trouverez deux déclarations `typedef`: `Input` et `Output`.  
Vous pouvez modifier ces déclarations comme bon vous semble.

Si vous souhaitez passer plusieurs données d'entrée à votre algorithme, utilisez un [`tuple<...>`](https://en.cppreference.com/w/cpp/utility/tuple).  
Avec un `tuple`, vous pouvez récupérer les valeurs comme ceci: `int n = get<0>(data)`, `vector<int> array = get<1>(data)` dans le cas où votre déclaration de `tuple` est `tuple<int, vector<int>>`.

### Personnaliser la fonction de comparaison et d'affichage de résultats pour les jeux de tests

La personnalisation de ces fonctions se fait dans le fichier **"main.cpp"**.

- `customWriteFunction`: Implémentez la logique pour permettre d'écrire dans la console la réponse donnée par un algorithme à un jeu de test. Elle est utilisée dans le cas où un algorithme ne donne pas la réponse attendue d'un jeu de test.
- `customVerifyFunction`: Implémentez la logique pour permettre de vérifier le résultat de sortie d'un algorithme et la réponse attendue. Cela peut être utile pour les cas où l'ordre des réponses d'un vecteur n'a pas d'importance, ou pour l'utilisation de types personnalisés (Tree / LinkedList, etc.).

Pour que ces fonctions soient utilisées, vous devez pour chaque instance d'un jeu de test:

- Faire appel à la méthode `setWriteFunction(maWriteFunction)` pour la fonction d'écriture.
- Faire appel à la méthode `setVerifyFunction(verifyFunction)` pour la fonction de vérification.

### Créer une fonction de génération de jeu de test

Vous pouvez vous baser sur la fonction `generateRandomData` pour créer une fonction personnalisée permettant de générer des jeux de test pour le problème que résout vos algorithmes.

## Utilisation

Une fois que vous avez configuré les différentes parties décrites ci-dessus comme bon vous semble, vous devez simplement compiler le fichier **"main.cpp"** et exécuter le fichier résultant.

## Licence

Ce projet est sous la licence [MIT License](./LICENCE).
