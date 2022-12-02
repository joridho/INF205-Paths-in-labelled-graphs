#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <string>

#include "run-graph.h" 
#include "graph-benchmark.h" 

using namespace std;

int main()
{
    int g1[4] = {10, 100, 1000, 10000}; 
    int g2[5] = {10, 100, 1000, 10000, 100000}; 
    int q1[7] = {3, 4, 5, 6, 7, 8, 9}; 
    int q2[5] = {10, 100, 1000, 10000, 100000}; 
    
    // creating file to store the time it takes to run run-graph
    ofstream ("../results/TimeRunGraph.dat");
    std::ofstream file1;
    file1.open("../results/TimeRunGraph.dat", std::ios::out | std::ios::app);


    for (int i : q1)
    {
        file1 << "Time for graph with {10, 100, 1000, 10000} number of nodes and with a query length of " << i << endl;
        for (int j : g1)
        {
            for (int z=0; z<100; z++) 
            {
                // creating char* to use in graph_benchmark and run_graph 
                char* q;
                string qu(to_string(j));
                q = &qu[0];

                char* g;
                string gu(to_string(i));
                g = &gu[0];


                char* graph_file;
                string gf("../results/kbt.dat");
                graph_file = &gf[0];


                char* query_file;
                string qf("../results/queryt.dat");
                query_file = &qf[0];

                char* benchmark;
                string bm("0");
                benchmark = &bm[0];

                char* argv[6] = {benchmark, q, g, graph_file, query_file, benchmark};
                bench::graph_benchmark(6, argv);

                // Starts to take the time 
                auto t0 = std::chrono::high_resolution_clock::now();
                run::run_graph(6, argv);
                auto t1 = std::chrono::high_resolution_clock::now();
                double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;

                file1 << t << "\t";// The time is written to the file 
            }
            file1 << "\n";
        }
        file1 << "\n";
    }


    for (int i : g2)
    {
        file1 << "Time for graph with " << i << " number of nodes and with a query length of {10, 100, 1000, 10000, 100000}; " << endl;
        for (int j : q2)
        {
            if (j>i){continue;}
            for (int z=0; z<100; z++) 
            {

                // creating char* to use in graph_benchmark and run_graph 
                char* q;
                string qu(to_string(j-1));
                q = &qu[0];

                char* g;
                string gu(to_string(i));
                g = &gu[0];


                char* graph_file;
                string gf("../results/kbt.dat");
                graph_file = &gf[0];


                char* query_file;
                string qf("../results/queryt.dat");
                query_file = &qf[0];

                char* benchmark;
                string bm("0");
                benchmark = &bm[0];

                char* argv[6] = {benchmark, q, g, graph_file, query_file, benchmark};
                // kjøre graph-benchmark 
                bench::graph_benchmark(6, argv);

                // Starts to take the time 
                auto t0 = std::chrono::high_resolution_clock::now();
                run::run_graph(6, argv);
                auto t1 = std::chrono::high_resolution_clock::now();
                double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
                

                file1 << t << "\t";// The time is written to the file 
            }
            file1 << "\n";
        }
        file1 << "\n";
    }
    
    return 0;
}


