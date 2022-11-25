#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
    assert(argc >= 2);

    std::ifstream ind(argv[1]);

    if(!ind)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
        return EXIT_FAILURE;
    }
    
    string l; 
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
    string line; 

    for (int m = 0; m < t-1; m++) {
        getline(indata, line); 

        string s1{line};
        char b = line[0]; 
        string path = s1.substr(2); 
        
        if (b == 'p') {p_paths.push_back(path);}
        else if (b == 'q') {q_paths.push_back(path);}

    }

    int r = 0; 
    for (string i : p_paths){
        r = r +1;
    }

    for (string i : q_paths)
    {
        for (int h = 0; h < r; h++)
        {
            if (i == p_paths[h] && p_paths[h] != "")
            {
                cout << "Path " << i << " occurs in both q and p" << endl;
                p_paths[h] = "";
            }
        }
    }
}
