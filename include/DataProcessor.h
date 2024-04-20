#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <string>
#include <map>

/*

    name: Kameron Coolong
    date: 4/20/2024

    DataProcessor.h

*/

using namespace std;

class DataProcessor {
    public:
        // Define default constructor.
        DataProcessor();

        // Member methods.
        int readInput(string fileName);
        void createDatFile(string inFileName);
        void searchItem();
        void displayCount();
        void displayHistogram();

    private:
        // Define map to store data.
        map<string, int> dict;
};


#endif