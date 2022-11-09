#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
using std::vector;



struct {
    int num_nodes;
    vector<int> adj[];
} GraphVariable; 



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

  for (int v = 0; v < num_nodes; ++v) { //For hver vertex v ... 
		cout << "\n Adjacency list of vertex " << v
			<< "\n head ";
		for (auto x : adj[v]) //.. vil koden iterere gjennom lista i adj[v]
			cout << "-> " << x;
		printf("\n");
	}

}

int main() {
    GraphVariable.num_nodes = 6;
    GraphVariable.adj[GraphVariable.num_nodes];
    CreateGraphCircle(GraphVariable.adj, GraphVariable.num_nodes);
}



