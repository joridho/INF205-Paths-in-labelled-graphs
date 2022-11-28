#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string.h>

#include "comparing-paths.h"

using namespace comp;

int comp::compare_paths(int argc, char** argv)
{
    assert(argc >= 2);

    std::ifstream ind(argv[1]);

    if(!ind)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
        return EXIT_FAILURE;
    }
    
    std::string l; 
    int t = 0;
    std::vector<std::string> length;
    while (ind) {
        getline(ind, l); 
        length.push_back(l);
        t = t + 1;
    }


    std::ifstream indata(argv[1]);
    if(!indata)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
        return EXIT_FAILURE;
    }

    std::vector<std::string> q_paths;
    std::vector<std::string> p_paths;
    std::string line; 

    for (int m = 0; m < t-1; m++) {
        getline(indata, line); 

        std::string s1{line};
        char b = line[0]; 
        std::string path = s1.substr(2); 
        
        if (b == 'p') {p_paths.push_back(path);}
        else if (b == 'q') {q_paths.push_back(path);}
    }

    int p_num = 0; 
    for (std::string i : p_paths){
        p_num = p_num +1;
    }
    int q_num = 0; 
    for (std::string i : q_paths){
        q_num = q_num +1;
    }

    for (int p = 0; p < p_num; p++)
    {
        int l = 0;
        for (int q = 0; q < q_num; q++)
        {
            if (q_paths[q] == p_paths[p] && q_paths[q] != "")
            {
                l = l + 1;
                //p_paths[p] = "";
                q_paths[q] = "";
            }
        }
        if (l > 0) {
            std::cout << "Path " << p_paths[p] << " occurs " << l << " times in both q and p" << std::endl;
        }
    }
    return 0;
}

// comment out when testing the runtime 
int main(int argc, char** argv)
{
   comp::compare_paths(argc, argv);
}

