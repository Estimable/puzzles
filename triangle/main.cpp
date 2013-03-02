#include <algorithm>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: triangle <filename>");
        exit(1);
    }

    ifstream inputFile(argv[1]);
    if (inputFile.is_open())
    {
        vector<int> first;
        vector<int> second;
        vector<int> *currRow = &first;
        vector<int> *prevRow = &second;

        string line;
        string value;
        while (inputFile.good())
        {
            getline(inputFile, line);
            stringstream lineParser(line);
            int index = 0;
            swap(prevRow, currRow);
            currRow->clear();
            while(getline(lineParser, value, ' '))
            {
                if (prevRow->empty()) currRow->push_back(atoi(value.c_str()));
                else if (index == 0) currRow->push_back(atoi(value.c_str()) + prevRow->front());
                else if (index == prevRow->size()) currRow->push_back(atoi(value.c_str()) + prevRow->back());
                else currRow->push_back(max(prevRow->at(index - 1), prevRow->at(index)) + atoi(value.c_str()));
                index++;
            }
        }
        inputFile.close();
        int maximum = 0;
        for(int i : *currRow) maximum = max(maximum, i);
        printf("Result: %d\n", maximum);
    }
    else
    {
        printf("Unable to open file '%s'", argv[1]);
    }
}