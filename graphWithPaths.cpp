
/*
This code creates a graph with n nodes and respected edges. 
Based on the graph two random sequences, p and q, are created 
and compared to find the common nodes.
*/


#include <iostream>
#include <list>
#include <time.h>
using namespace std;


/*
This class initializes the methods needed to
create the paths of the given graph.
*/

class Graph {
  int Vertex;
  list<int>* adj; 

  void printAllPathsUtil(int, int, bool[], int[], int&);

  public:
    Graph(int Vertex);
    void addEdge(int node_a, int node_b);
    void printAllPaths(int start_node, int end_node);
};


/*
This method allocates a value to 
the adjacency list pointer.
*/

Graph::Graph(int Vertex)
{
  this->Vertex = Vertex;
  adj = new list<int>[Vertex];
}


/*
Adds the first node, a, and second node, b, to the
adjacency list. The list will later be used to 
create the graph where node a is connected to 
node b.
*/

void Graph::addEdge(int node_a, int node_b)
{
  adj[node_a].push_back(node_b); 
  adj[node_b].push_back(node_a);

}


/*
This method prints all paths from the given start 
node to the given end node. First it initializes
an empty array, and marks all the vertices as
'not visited'. Sencondly it calls the recursive 
helper function to print all paths.
*/

void Graph::printAllPaths(int start_node, int end_node)
{
  int* path = new int[Vertex];
  int path_index = 0; 

  bool* visited = new bool[Vertex];
	
  for (int i = 0; i < Vertex; i++) 
    visited[i] = false;
	
  printAllPathsUtil(start_node, end_node, visited, path, path_index); 
}


/*
This method is a recursive function that prints all the possible
paths between the chosen inputs, start_node and end_node, initialized
in printAllPaths(). The method starts off by marking the first node,
node_a and storing it in path[]. Afterwards it goes through an if-
loop to determine the rest of the path, and if there is more than
one.
*/

void Graph::printAllPathsUtil(int node_a, int end_node, bool visited[],
							  int path[], int& path_index)
{
  visited[node_a] = true;
  path[path_index] = node_a;
  path_index++;

  //If the current vertex is same as the end node, then print
  //current path[]
  if (node_a == end_node) {
    for (int i = 0; i < path_index; i++)
	  cout << path[i] << " ";
	cout << endl;
	}
	
  // If the current vertex is not the same as the end node, 
  // recur for all the vertices adjacent to current vertex
  else 
	{
	  list<int>::iterator i;
	  for (i = adj[node_a].begin(); i != adj[node_a].end(); ++i)
	    if (!visited[*i])
		  printAllPathsUtil(*i, end_node, visited, path, path_index);
	}

	// Remove current vertex from path[] and mark it as unvisited
	path_index--;
	visited[node_a] = false;
  
}


/*
Main function of the program. This function takes an input 
containing number of nodes. The graph is created by manually 
choosing node a and node b. All the possible paths from a 
random start node and random end node is printed, where one 
of the paths are chosen as a specific sequence. Then two random
sequences are compared to investigate which nodes that are common.
*/
int main()
{
  int nodes;
  cout << "Choose a number of nodes: ";
  cin >> nodes;

  Graph g(nodes);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(2, 1);
  g.addEdge(1, 3);

  int start1 =  rand() % nodes; 
  int end1 = rand() % nodes;
  int start2 =  rand() % nodes; 
  int end2 = rand() % nodes;

  cout << "Following are all different paths from " << start1
    << " to " << end1 << endl;
  g.printAllPaths(start1, end1);

  cout << "Following are all different paths from " << start2
    << " to " << end2 << endl;
  g.printAllPaths(start2, end2);


  return 0;
}
