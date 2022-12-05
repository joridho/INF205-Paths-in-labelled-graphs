#ifndef COMPARINGPATHS_H
#define COMPARINGPATHS_H
#include <iostream>

namespace comp
/*
* Initialzing the functions compare_paths and compare, defined in threading-paths.cpp
*/
{
    int compare(int argc, char** argv, int start_index, int end_index, std::vector<std::string> p_paths, std::vector<std::string> q_paths, int q_num);
    int compare_paths(int argc, char** argv);
}

#endif