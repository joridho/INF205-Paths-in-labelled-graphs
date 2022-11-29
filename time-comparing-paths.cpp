
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
    // creating a file for adding the time it takes to run comparing-paths.cpp with different amounts of paths found
    ofstream ("TimeComparingGraph1.dat");
    std::ofstream file1;
    file1.open("TimeComparingGraph1.dat", std::ios::out | std::ios::app);

    file1 << "Time for comparing-paths with different amounts of paths found" << endl;
    
    char* file;
    char* b;
    string res1[4] = {"results/results10.dat", "results/results100.dat", 
                    "results/results1000.dat", "results/results10000.dat"};  // the name of the pre-made files with results

    for (string i : res1)
    {   
        for (int z=0; z<10; z++) 
        {
            string f(i);
            file = &f[0];

            string bm("0");
            b = &bm[0];
            char* argv[2] = {b, file};

            // Starts to take the time 
            auto t0 = std::chrono::high_resolution_clock::now();
            comp::compare_paths(2,argv);
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;

            file1 << t << "\t";  // The time is written to the file 
        }
        file1 << "\n";
    }



    // creating a file for adding the time it takes to run comparing-paths.cpp with different amounts of equal paths found
    ofstream ("TimeComparingGraph2.dat");
    std::ofstream file2;
    file2.open("TimeComparingGraph2.dat", std::ios::out | std::ios::app);
    file2 << "Time for comparing-paths with 100 paths found but with different amount of similiar paths" << endl;

    string res2[5] = {"results/results0.dat", "results/results25.dat", "results/results50.dat", 
                        "results/results75.dat", "results/results100p.dat"};   // the name of the pre-made files with results
    for (string j : res2)
    {
        for (int z=0; z<5000; z++) 
        {
            string f(j);
            file = &f[0];

            string bm("0");
            b = &bm[0];

            char* argv[2] = {b, file};

            // Starts to take the time 
            auto t0 = std::chrono::high_resolution_clock::now();
            comp::compare_paths(2,argv);
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;

            file2 << t << "\t"; // The time is written to the file
        }
        file2 << "\n";
    }


    return 0;
}