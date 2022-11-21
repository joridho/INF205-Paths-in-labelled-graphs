#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char** argv)
{
    assert(argc >= 2);

    std::ifstream indata(argv[1]);

    if(!indata)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
        return EXIT_FAILURE;
    }
    
    std::vector<std::string> similar_paths;
    string line;
    while (indata) {
        getline(indata, line); 
        //cout << line << "\n";
        similar_paths.push_back(line); 
    }

    std::vector<std::string> like_nodes;
    int r = 0;

    for (string i: similar_paths){
        r = r +1;

    }

    int e;
    
    for (int k = 0; k < r; k++){

        int l =1;

        for (int h = k; h< r; h++){
            if (k == h){
                continue;
                }
            if (similar_paths[k] == similar_paths[h]){
                l +=1;
                similar_paths[h] = to_string(h);
            } 
        }

        if (l>1){
            cout << similar_paths[k] << " " << "occurs" << " " << l << " " <<  "times" << "\n"; 
        }
    }
}
