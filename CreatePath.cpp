#include <iostream>
#include <time.h>
using namespace std;



int CreatePath(int nodes) {
    srand(time(0));
    int start_node;
    int len_path;

    while(true){
        start_node = rand() % nodes + 1; 
        len_path = rand() % nodes + 1; 
        if (len_path != nodes) {break;}
    }

    int path[len_path];
    
    if (start_node+len_path <= nodes) {
        int  end_node = start_node + len_path - 1;
        for (int i = start_node; i < end_node  + 1; ++i) {
            path[i-start_node] = i;
        }
    }

    else {
        
        for (int i = start_node; i < nodes + 1; ++i) {
            path[i-start_node] = i;
        }

        int start_idx = (nodes - start_node + 1) - 1;
        int end_node = len_path - (nodes - start_node + 1);

        for (int i = 1; i < end_node + 1; ++i) {
            path[start_idx + i] = i;
        }
    }


    cout << "Start node: " << start_node << "\n";
    cout << "Length of path: " << len_path << "\n";

    for (int i = 0; i < len_path; i++ ) {
        cout << path[i] << "\n";
    }
    
    return 0;
}



int main() {

    int nodes = 10;
    int p;

    p = CreatePath(nodes);

    return 0;
}












