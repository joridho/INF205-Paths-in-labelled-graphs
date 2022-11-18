#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include "graph.h"
#include "query.h"

// The main function:
// The program terminates if the arguments are less than 3???
// The program opens up the file as indata that the user puts as arguments**
// If the user has not put a file, the program terminates and prints out an error message
// Makes a object g of the Graph class
// Stores graph in indata in g
//closes file indata
//
// The program opens up the file as inquery that the user puts as arguments**
// If the user has not put a file, the program terminates and prints out an error message
// Makes a object q of the Query class
// Stores query in inquery in q 
// closes file inquery
// apply query q to graph g
// what happens then??
//
// // ./generate-graph <number of nodes> <query path length> <graph file> <query file>
int main(int argc, char** argv)
{
   assert(argc >= 3);
   
   std::ifstream indata(argv[1]);
   if(!indata)
   {
      std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
      return EXIT_FAILURE;
   }
   graph::Graph g;
   indata >> g;
   indata.close();
   // std::cout << "\nContent of graph g:\n" << g << "\n";
   
   std::ifstream inquery(argv[2]);
   if(!inquery)
   {
      std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
      return EXIT_FAILURE;
   }
   graph::Query q; 
   inquery >> q; 
   inquery.close(); 
   
   g.query(&q, &std::cout);  // apply query q to graph g
}
