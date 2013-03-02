#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: reversed-binary <number>";
        exit(1);
    } 

    unsigned int input = atoi(argv[1]); 
    unsigned int output = 0;

    bool firstFound = false;
    unsigned int j = 1;

    /* The problem states that numbers will be 1 < x < 1000000000, so we
       can begin with 2^30 */
    for (unsigned int i = 1073741824; i >= 1; i = i / 2)
    {
        if (firstFound) j = j * 2;
        if ((input & i) == i)
        {
            firstFound = true;
            output = output + j;
        }
    }

    cout << output;
}