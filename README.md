# Projet de Cartographie de Bretagne en C++

## Description du Projet

Ce projet permet de créer une carte interactive de la Bretagne en C++ avec l'utilisation de Qt. Les principaux objectifs du projet sont :

- **Création et Affichage de Points** : Ajoutez des points représentant des villes sur la carte.
- **Tracés de Routes** : Tracez des routes entre les villes pour visualiser les connexions.
- **Calcul de Distance Optimale** : Entrez un point de départ et une destination; le projet calcule la route la plus courte en utilisant les algorithmes de Dijkstra et A*.

## Fonctionnalités Clés

1. **Interface Utilisateur** :
    - Utilise le framework Qt pour une interface graphique intuitive et interactive.
    - Fenêtre principale permettant de saisir la ville de départ et d'arrivée.
    - Affichage des coordonnées géographiques en temps réel.

2. **Algorithmes de Recherche de Chemin** :
    - **Dijkstra** : Algorithme de recherche de chemin le plus court dans un graphe pondéré.
    - **A*** : Algorithme de recherche de chemin plus performant grâce à l'utilisation de heuristiques.

3. **Utilisation de la Base de Données** :
    - **Connexion à la Base de Données** : La carte de Bretagne, les points de villes, les routes et les contours de la Bretagne sont récupérés depuis une base de données.
    - **Gestion des Erreurs** : Gestion des erreurs de connexion et affichage des messages appropriés.

## Organisation des Fichiers du Projet

- **BDD** : Concerne la gestion de la base de données (`BDD.cpp`, `BDD.h`).
- **Carte** : Classe représentant la carte contenant les villes, routes, et contours (`Carte.h`).
- **FenetrePrincipale** : Interface principale où l'utilisateur interagit avec la carte (`FenetrePrincipale.cpp`, `FenetrePrincipale.h`).
- **Algorithmes** : Fichiers contenant les implémentations des algorithmes de Dijkstra (`dijkstra.h`).
- **Vues et Scènes** : Classes pour la gestion des vues et scènes dans l'application Qt (`GrandeVue.h`, `MinieVue.h`, `Scene.h`).
- **Points et Routes** : Définition des points et routes pour la carte (`Point.h`, `Route.h`, `Waypoint.h`, `Ville.h`, `Contour.h`).
- **Utilitaires** : Fichiers et ressources complémentaires nécessaires au projet (`LoginDialog.cpp`, `LoginDialog.h`, `Makefile`, `miniprojet`, `miniprojet.pro`, `north.png`).

## Conclusion

Ce projet permet de visualiser et d'interagir avec une carte de la Bretagne, en offrant des fonctionnalités pour afficher les villes, tracer des routes, et calculer les itinéraires optimaux. Les données géographiques sont récupérées depuis une base de données, assurant une mise à jour dynamique et précise des informations.

### Auteurs : Emilie Le Rouzic & Maryline Le Bot
