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
        int lq = 0;
        std::string equal_path;
        for (int q = 0; q < q_num; q++)
        {
            if (q_paths[q] == p_paths[p] && q_paths[q] != "" && p_paths[p] != "")
            {
                lq = lq + 1;
                equal_path = q_paths[q];
                q_paths[q] = "";
            }
        }

        int lp = 0;
        if (lq > 1)
        {
            for (int z = 0; z < p_num; z++)
            {
                if (p_paths[z] == equal_path)
                {
                    p_paths[z] = "";
                    lp = lp + 1;
                }
            }

            std::cout << equal_path << "     occurs " << lq << " times in q and " <<  lp << " times in p" << std::endl;
        }
    }
    return 0;
}



