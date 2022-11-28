
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <string>

#include "comparing-paths.h" 

using namespace std;


int main ()
{
    string res1[4] = {"results/results10.dat", "results/results100.dat", 
                    "results/results1000.dat", "results/results10000.dat"};

    // ny fil for comparing paths 1
    ofstream ("TimeComparingGraph1.dat");
    std::ofstream file1;
    file1.open("TimeComparingGraph1.dat", std::ios::out | std::ios::app);

    // lage en overskrift i filen 
    file1 << "Time for comparing-paths with different amounts of paths found" << endl;
    //fil liste_med_results {results10.dat, results100.dat, results1000.dat, results10000.dat}
    
    char* file;
    char* b;

    for (string i : res1)
    {   
        cout << i << endl;
        string f(i);
        file = &f[0];

        string bm("0");
        b = &bm[0];
        char* argv[2] = {b, file};

        auto t0 = std::chrono::high_resolution_clock::now();

        comp::compare_paths(2,argv);

        auto t1 = std::chrono::high_resolution_clock::now();
        double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;

        file1 << t << endl;
    }



    // ny fil for comparing paths 2
    ofstream ("TimeComparingGraph2.dat");
    std::ofstream file2;
    file2.open("TimeComparingGraph2.dat", std::ios::out | std::ios::app);
    // lage en overskrift i filen 
    file2 << "Time for comparing-paths with 100 paths found but with different amount of similiar paths" << endl;

    string res2[5] = {"results/results0.dat", "results/results25.dat", "results/results50.dat", 
                        "results/results75.dat", "results/results100p.dat"};
    for (string j : res2)
    {
        cout << j << endl;
        //char* file;
        string f(j);
        file = &f[0];

        //char* b;
        string bm("0");
        b = &bm[0];
        char* argv[2] = {b, file};

        auto t0 = std::chrono::high_resolution_clock::now();
        comp::compare_paths(2,argv);
        auto t1 = std::chrono::high_resolution_clock::now();
        double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;
        // skrive t til filen 
        file2 << t << endl;
    }


    return 0;
}