#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int g1[4] = {10, 100, 1000, 1000}; 
    int g2[3] = {10, 100, 1000}; 
    int q1[7] = {3, 4, 5, 6, 7, 8, 9}; 
    int q2[4] = {10, 100, 1000, 1000}; 
    
    // Lage en fil 
    ofstream ("TimeRunGraph.dat");
    std::ofstream file1;
    file1.open("TimeRunGraph.dat", std::ios::out | std::ios::app);


    for (int i : q1)
    {
        file1 << "Time for graph with {10, 100, 1000, 1000} number of nodes and with a query length of " << i << endl;
        for (int j : g1)
        {
            // kjøre graph-benchmark 

            auto t0 = std::chrono::high_resolution_clock::now();
            // kjøre run-graph 
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
            // skrive t til filen 
            file1 << t << endl;
        }
        file1 << "\n";
    }


    for (int i : g2)
    {
        file1 << "Time for graph with " << i << " number of nodes and with a query length of {10, 100, 1000, 1000} " << endl;
        for (int j : q2)
        {
            // kjøre graph-benchmark 

            auto t0 = std::chrono::high_resolution_clock::now();
            // kjøre run-graph 
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
            // skrive t til filen 
            file1 << t << endl;
        }
        file1 << "\n";
    }






    // teste comparing paths 

    // manipulere results.dat
    // results med {10, 100, 1000, 10000} paths som er funnet 
    // results med 100 paths funnet, men {0, 0.25, 0.50, 0.75, 1} prosent er like 

    // ny fil for comparing paths 1
    ofstream ("TimeComparingGraph1.dat");
    std::ofstream file2;
    file2.open("TimeComparingGraph1.dat", std::ios::out | std::ios::app);
    // lage en overskrift i filen 
    file2 << "Time for comparing-paths with different amounts of paths found" << endl;
    //fil liste_med_results {results10.dat, results100.dat, results1000.dat, results10000.dat}


    for (int i : q1)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        // kjøre comparing paths 
        auto t1 = std::chrono::high_resolution_clock::now();
        double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
        // skrive t til filen 
        file2 << t << endl;
    }

    // ny fil for comparing paths 2
    ofstream ("TimeComparingGraph2.dat");
    std::ofstream file3;
    file3.open("TimeComparingGraph2.dat", std::ios::out | std::ios::app);
    // lage en overskrift i filen 
    file3 << "Time for comparing-paths with 100 paths found but with different amount of similiar paths" << endl;
    //fil liste_med_results {results0.dat, results25.dat, results50.dat, results75.dat, results100.dat}
    for (int i : q1)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        // kjøre comparing paths 
        auto t1 = std::chrono::high_resolution_clock::now();
        double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
        // skrive t til filen 
        file3 << t << endl;
    }


    // trenger en god ide på hvordan endre på graph-benchmark fra denne mappa 

    // memory leak? 

    // cmake?? 

    return 0;
}


/*
Hva skal måles:
* tida det tar å sette sammen paths med forskjellig
    - antall noder på graph
    - forskjellig query path length
    - disse to variert om hverandre 

* tida det tar å sammenligne paths 
    - basert på hvor mange paths som er funnet
        10
        100
        1000
        10000
    - basert på hvor mange like paths det er 
        0%      100
        25%     100
        50%     100
        75%     100
        100%    100
        Om det ikke er en signifikant forskjell her er det ikke vits i å teste videre
* korrelere noder, query length og antall paths funnet 
*/