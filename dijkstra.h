/*-----------------------
  fichier dijkstra.h
  Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
------------------------*/
// This code is contributed by Aditya Kumar (adityakumar129) et modifier par Emilie et Maryline
//lien : https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
// Programme C++ pour le chemin le plus court source unique de Dijkstra
// algorithme.Le programme est pour la matrice d'adjacence
// représentatant le graphe.
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <bits/stdc++.h>
using namespace std;
// Nombre de sommets dans le graphe
#define V 58

// Une fonction utilitaire pour trouver le sommet avec le minimum
// de distance
int minDistance(int dist[], bool sptSet[])
{
	// Initialise la valeur min à l'infini
	int min = INT_MAX;
	int min_index = 0;
	for (int i = 0; i < V; i++)
		if (sptSet[i] == false && dist[i] <= min)
		{
			min = dist[i], min_index = i;
		}
	return min_index;
}

// Fonction pour imprimer le chemin le plus court de la source à j en utilisant
// tableau parent
void printPath(int parent[], int j, vector<int> *chemin)
{
	// Cas de base : si j est la source
	if (parent[j] == -1)
	{
		return;
	}
	printPath(parent, parent[j], chemin);
	chemin->push_back(j);
}

// Une fonction utilitaire pour imprimer la distance construite
vector<int> printSolution(int dist[], int n, int parent[], int src, int dest, int *distance)
{
	vector<int> chemin;
	chemin.push_back(src);
	for (int i = 0; i < n; i++)
	{
		if (i == dest)
		{
			*distance = dist[i];
			printPath(parent, i, &chemin);
		}
	}
	return chemin;
}
// Fonction qui implémente la source unique de Dijkstra
// algorithme du plus court chemin pour un graphe représenté à l'aide
// de la représentation matricielle d'adjacence
vector<int> dijkstra(int graph[V][V], int src, int dest, int *distance)
{
	// Le tableau de sortie. dist[i] tiendra le plus court
	// distance de src à i
	int dist[V];
	// sptSet[i] sera vrai si le sommet i est inclus dans
	// l'arbre du chemin le plus court ou distance la plus courte de src à i
	// est finalisé
	bool sptSet[V] = {false};

	// Tableau parent pour stocker l'arborescence des chemins les plus courts
	int parent[V];
	for (int toto = 0; toto < V; toto++)
	{
		parent[toto] = -1;
	}

	// Initialise les distance à l'INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

	// La distance du sommet source à lui-même est toujours 0
	dist[src] = 0;

	// Trouve le chemin le plus court pour tous les sommets
	for (int count = 0; count < V - 1; count++)
	{

		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{

			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v] && v != src)
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	vector<int> chemin = printSolution(dist, V, parent, src, dest, distance);
	return chemin;
}
#endif

