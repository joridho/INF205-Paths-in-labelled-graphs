// executable should be called as follows:
//
// ./generate-graph <number of nodes> <query path length> <graph file> <query file>
//
// for example: ./graph-benchmark 1000 10 kb.dat query.dat

#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "graph-benchmark.h"

using namespace bench;

int bench::graph_benchmark(int argc, char** argv)
{
    assert(argc >= 6);  // ./generate-graph <number of nodes> <query path length> <graph file> <query file>
    
    long graph_size = std::atol(argv[1]);
    assert(graph_size > 0);
    
    int query_size = std::atoi(argv[2]);
    assert(query_size > 0);

    // generate query file
    std::ofstream qout(argv[4]);
    if(!qout) return EXIT_FAILURE;
    for(int i = 0; i < query_size; i++)
        qout << '<' << "r" << 2*i << "> ";
    qout << "<>\n";
    for(int i = 0; i < query_size; i++)
        qout << '<' << "r" << 2*i+1 << "> ";
    qout << "<>\n";
    qout.close();
    
    // graph partition size
    long p = graph_size / (1+query_size);  
    
    // layer-to-layer decay factor
    double l = std::pow(1.4427*p, -1.0/(2.0*query_size));
    
    // random seed from chrono

    std::srand(
        std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()
        ).count()
    );


    // generate graph file
    std::ofstream gout(argv[3]);
    if(!gout) return EXIT_FAILURE;
    std::cout.flush();
    
    bool* covered = new bool[graph_size];
    for(long i = 0; i < graph_size; i++) covered[i] = false;
    
    // layer i from 0 to query_size-1:
    //    each has the nodes from p*i to p*i + (p-1)
    //    node j from layer i
    // layer i+1 from 1 to query_size
    //    node k from layer i+1
    // connection probability given by q
    for(int i = 0; i < query_size; i++)
    {
        // individual connection probability
        double q = 1.0 - std::pow(1.0 - std::pow(l, i+1.0), 1.0/(p*std::pow(l, i)));
        
        for(long j = p*i; j < p*(i+1); j++)
            for(long k = p*(i+1); k < p*(i+2); k++)
            {
                if(q > (double)std::rand()/RAND_MAX)
                {
                // edge from node j to node k labelled "relation 2i"
                covered[j] = true;
                covered[k] = true;
                gout << "<n" << j << ">\t<r" << 2*i << ">\t<n" << k << ">\n";
                }
                if(q > (double)std::rand()/RAND_MAX)
                {
                // edge from node j to node k labelled "relation 2i+1"
                covered[j] = true;
                covered[k] = true;
                gout << "<n" << j << ">\t<r" << 2*i+1 << ">\t<n" << k << ">\n";
                }
            }
        gout << "\n";
    }    

    // remaining nodes
    for(long i = 0; i < graph_size; i++)
        if(!covered[i])
        {
            long j = i + (long)((graph_size-i-1) * std::rand()/(double)RAND_MAX);
            assert((j >= i) && (graph_size > j));
            while(covered[j])
            {
                j++;
                if(j == graph_size) j = 0;
            }
            covered[i] = true;
            covered[j] = true;
            gout << "<n" << i << ">\t<r" << 2*query_size << ">\t<n" << j << ">\n";
        }
    
    gout << "\n<>\n";
    gout.close();
    return 0;
}









