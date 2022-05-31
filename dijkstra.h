// C++ program for Dijkstra's single source shortest path
// algorithm.The program is for adjacency matrix
// representation of the graph.
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 58

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++)
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;
	return min_index;
}

// Function to print shortest path from source to j using
// parent array
void printPath(int parent[], int j,vector<int> *chemin)
{
	// Base Case : If j is source
	if (parent[j] == -1){
		return;
	}
	printPath(parent, parent[j],chemin);
	cout << j << " ";
	chemin->push_back(j);
}

// A utility function to print the constructed distance
// array
vector<int> printSolution(int dist[], int n, int parent[],int src,int dest)
{
	//int src = 0;
	vector<int> chemin;
	chemin.push_back(src);
	//cout << "Vertex\t Distance\tPath";
	for (int i = 0; i < n; i++) {
		if(i==dest){
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],
			src);
		printPath(parent, i,&chemin);
		}
	}
	return chemin;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
vector<int> dijkstra(int graph[V][V], int src,int dest)
{
	// The output array. dist[i] will hold the shortest
	// distance from src to i
	int dist[V];
	// sptSet[i] will true if vertex i is included / in
	// shortest path tree or shortest distance from src to i
	// is finalized
	bool sptSet[V] = { false };

	// Parent array to store shortest path tree
	int parent[V];
	for(int toto=0;toto<V; toto++){
			parent[toto] = -1;
		}

	// Initialize all distances as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0 ; count < V - 1 ; count++) {
		
		int u = minDistance(dist, sptSet);
		
		sptSet[u] = true;
	
		for (int v = 0; v < V; v++){

			if (!sptSet[v] && graph[u][v]
				&& dist[u] + graph[u][v] < dist[v]
				&& v != src) {
				if (v == src){cout<<"toto "<<v;}
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
				// cout<<u<<" "<<v<<"  "<<dist[v]<<"  \n";
			}
			//cout<<parent[v]<<"    ";
		}
		
	}
	//cout<<"\n"<<dist[1];
	// print the constructed distance array
	vector<int> chemin = printSolution(dist, V, parent,src,dest);
	return chemin;
}

// This code is contributed by Aditya Kumar (adityakumar129)
