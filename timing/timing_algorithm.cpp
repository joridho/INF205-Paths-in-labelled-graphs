#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>

using namespace std;

int main()
{
    int g1[4] = {10, 100, 1000, 1000}; 
    int g2[3] = {10, 100, 1000}; 
    int q1[7] = {3, 4, 5, 6, 7, 8, 9}; 
    int q2[4] = {10, 100, 1000, 1000}; 
    
    // Lage en fil 

    while (q1)
    {
        // lage en overskrift i filen 

        while (g1)
        {
            // kjøre graph-benchmark 
            auto t0 = std::chrono::high_resolution_clock::now();
            // kjøre run-graph 
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
            // skrive t til filen 
        }
    }

    while (g2)
    {
        // lage en overskrift i filen 

        while (q2)
        {
            // kjøre graph-benchmark 
            auto t0 = std::chrono::high_resolution_clock::now();
            // kjøre run-graph 
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
            // skrive t til filen 
        }
    }

    // teste comparing paths 

    // ny fil for comparing paths 
    while (q1)
    {
        // lage en overskrift i filen 

        while (g1)
        {
            auto t0 = std::chrono::high_resolution_clock::now();
            // kjøre comparing paths 
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
            // skrive t til filen 
        }
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
        10      q=5
        100     q=5
        1000    q=5
        10000   q=5
        100000  q=5
    - forskjellig query path length
        10      g=10001
        100     g=10001
        1000    g=10001
        10000   g=10001
    - disse to variert om hverandre 
* tida det tar å sammenligne paths 
    - basert på hvor mange paths som er funnet
    - basert på hvor mange like paths det er 
* korrelere noder, query length og antall paths funnet 
*/