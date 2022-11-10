// A simple representation of graph using STL
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;
using std::vector;


// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) { //For hver vertex v ... 
		cout << "\n Adjacency list of vertex " << v
			<< "\n head ";
		for (auto x : adj[v]) //.. vil koden iterere gjennom lista i adj[v]
			cout << "-> " << x;
		printf("\n");
	}
}

void CreateGraphCircle(vector<int> adj[], int num_nodes){
	int num_edges = num_nodes - 1;
    for (int u = 0; u < num_nodes; ++u){
        if (u == num_nodes - 1){
        adj[0].push_back(u);
        adj[u].push_back(0);
        }
    else{
        int v = u + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
    }
}

void PrintGraph(vector<int> adj[], int num_nodes) {
    for (int v = 0; v < num_nodes; ++v) { //For hver vertex v ... 
		cout << "\n Adjacency list of vertex " << v
			<< "\n head ";
		for (auto x : adj[v]) //.. vil koden iterere gjennom lista i adj[v]
			cout << "-> " << x;
		printf("\n");
	}

}

// Driver code
int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, V);
	return 0;
}

