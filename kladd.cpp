#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
using std::vector;



#define nodes = 6;



struct {
    int num_nodes = 6;
    vector<int> adj[6];
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

void MakeMatrix(vector<int> adj[], int num_nodes){
    //initializing
    int rows = num_nodes;
    int columns = num_nodes;
    int matrice[rows][columns] = {0}; //initialize zero matix

    for (int r = 0; r < rows; r++){

        for (int c = 0; c < columns; c++){
        
        //hvis rad og kolonne er like
        if (r == c){
            matrice[r][c] = 0;
        }

        //hvis node r er koblet til node c
        else if (std::count(adj[r].begin(), adj[r].end(), c)) {
            matrice[r][c] = 1;
        }

        //node r er ikke koblet til node c
        else{
            matrice[r][c] = 0;
        }

        //printer ut matrise
        cout << matrice[r][c] << " ";
        }
    cout << endl;
    }

}

int main() {
    CreateGraphCircle(GraphVariable.adj, GraphVariable.num_nodes);
    PrintGraph(GraphVariable.adj, GraphVariable.num_nodes);
    MakeMatrix(GraphVariable.adj, GraphVariable.num_nodes);
}



