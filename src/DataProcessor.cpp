#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <map>

#include "../include/DataProcessor.h"
#include "../include/Interface.h"

using namespace std;
using namespace Interface;

DataProcessor::DataProcessor() {
    map<string, int> dict;
}

// Print main menu.
void DataProcessor::searchItem() {
    string name;
    int input = -1;

    input = searchItemMenu();
    while (input != 2) {
        name = getString("Enter item name: ");

        if (this->dict.find(name) == this->dict.end()) {
            cout << "Item not found." << endl;
        } else {
            cout << this->dict.find(name)-> first << " " << this->dict.find(name)->second << endl;
        }
        waitEnter(false);
        clearScreen();

        input = searchItemMenu();
    }
}

// read input file contents into map, counting the number of occurances.
int DataProcessor::readInput(string fileName) {
    ifstream inFile;
    string name;
    int occurance;

    clearScreen();

    // Open file.
    cout << "Opening " << fileName << "." << endl;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Could not open file: " << fileName << endl;
        return -1;
    }

    // Read file into map.
    inFile >> name;
    while (!inFile.fail()) {
        if (this->dict.find(name) == this->dict.end()) {
            this->dict.insert(pair<string, int>(name, 1));
        } else {
            this->dict.find(name)->second += 1;
        }

        inFile >> name;
    }

    cout << "Successfully read " << fileName << endl << endl; 

    // Close file.
    inFile.close();
    return 0;
}

void DataProcessor::createDatFile(string inFileName) {
    ofstream outFile;
    string outFileName = inFileName.substr(0, inFileName.size()-3) + "dat";

    // Open output file.
    cout << "Opening " << outFileName << "." << endl;
    outFile.open(outFileName);
    if (!outFile.is_open()) {
        cout << "Could not open file: " << outFileName << endl;
        return;
    }

    // Load map data into dat file.
    for (auto i = this->dict.begin(); i != this->dict.end(); i++) {
        outFile << i->first << " " << i->second << endl;
    }

    cout << "Successfully generated " << outFileName << endl << endl;

    // Close file.
    outFile.close();
}

void DataProcessor::displayCount() {
    for (auto i = this->dict.begin(); i != this->dict.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }
    waitEnter(false);
    clearScreen();
}

void DataProcessor::displayHistogram() {
    for (auto i = this->dict.begin(); i != this->dict.end(); i++) {
        cout << i->first << " " << string(i->second, '*') << endl;
    }
    waitEnter(false);
    clearScreen();
}