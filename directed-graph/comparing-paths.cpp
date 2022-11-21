#include <iostream>
#include <fstream>

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

    // Finne en praktisk måte å sammenligne på 

}