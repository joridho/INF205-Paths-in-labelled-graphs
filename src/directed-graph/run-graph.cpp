// Created by Martin Thomas Horsch, associate professor at intitute for data science, 
// faculty of science and technology, NMBU
// written with the following license: https://creativecommons.org/licenses/by-nc-sa/4.0/

// These changes were made:
//    - Use of graph-benchmark 
//    - Add the results to results.dat 
//    - Altered the code to fit to the header file created
// Some comments were added to the whole code, but nothing else were altered. 

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include "graph.h"
#include "query.h"
#include "graph-benchmark.h"
#include "run-graph.h"

using namespace run;

/*
* Run graph creates an object g of the Graph class and stores the graph g in indata.
* Then an object q of the Query class is stored in inquery in q. 
* Indata and inquery is files defined in the input
*/

// // ./generate-graph <number of nodes> <query path length> <graph file> <query file> <result-file>

int run::run_graph(int argc, char** argv)
{
   assert(argc >= 6);
   
   if (atoi(argv[5]) == 1)
   {
      bench::graph_benchmark(argc, argv);
   }

   std::ofstream ("results.dat");  // initializing of file where the results will be written to 

   std::ifstream indata(argv[3]); 
   if(!indata)
   {
      std::cerr << "Error! File " << argv[3] << " cannot be read.\n";
      return EXIT_FAILURE;
   }
   graph::Graph g;  // object g of Graph class 
   indata >> g;
   indata.close();
   
   std::ifstream inquery(argv[4]); 
   if(!inquery)
   {
      std::cerr << "Error! File " << argv[4] << " cannot be read.\n";
      return EXIT_FAILURE;
   }
   graph::Query q; // object q of Query class 
   inquery >> q; 
   inquery.close(); 
   
   g.query(&q, &std::cout);  // apply query q to graph g
   return 0;
}

int main(int argc, char** argv)
{
   run::run_graph(argc, argv);
}