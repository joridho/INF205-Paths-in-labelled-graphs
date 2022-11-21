#include <iostream>
#include <fstream>
#include <vector>

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

    cout << "test" << endl;

    std::vector<std::string> similar_paths;
    string line;
    while (indata) {
        getline(indata, line);
        cout << line << "\n";
    }

    // Finne en praktisk måte å sammenligne på 
}