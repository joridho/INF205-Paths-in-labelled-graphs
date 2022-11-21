#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
    //assert(argc >= 2);

    //std::ifstream indata(argv[1]);
    //if(!indata)
    //{
    //    std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
    //    return EXIT_FAILURE;
    //}

    //cout << "test" << endl;

    std::ifstream indata("results.dat");
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

        //std::cout << similar_paths[k] <<"\n";
        //for 
        int l =1;

        for (int h = k; h< r; h++){

            if (k == h){
                continue;
                }
                
            if (similar_paths[k] == similar_paths[h]){
                l +=1;
                similar_paths[h] = to_string(h);
                //&similar_paths[h].pop_back();
                }

        }
        if (l>1){
            cout << similar_paths[k] << " " << "occurs" << " " << l << " " <<  "times" << "\n"; 
        };
    


        //if (similar_paths[k] == similar_paths[0] && k!=0 ){

        //like_nodes.push_back(similar_paths[0]);
        //like_nodes.push_back(similar_paths[k]);
        //e = e +1; 
       }
    }
    
    //std::cout << like_nodes[0];

    //for (int o; o < e; o++){
    //    std::cout << like_nodes[o] <<"\n";
    //}

    // Finne en praktisk måte å sammenligne på 
//}