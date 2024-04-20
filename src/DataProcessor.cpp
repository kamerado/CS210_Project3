#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <map>

#include "../include/DataProcessor.h"
#include "../include/Interface.h"

/*

    name: Kameron Coolong
    date: 4/20/2024

    DataProcessor.cpp

*/

using namespace std;
using namespace Interface;

DataProcessor::DataProcessor() {
    map<string, int> dict;
}

// Print main menu.
void DataProcessor::searchItem() {
    string name;
    int input = -1;

    input = searchItemMenu(); // Display search item menu to get input.
    while (input != 2) {
        name = getString("Enter item name: "); // get item name to search for.

        if (this->dict.find(name) == this->dict.end()) { // If item name does not exist,
            cout << "Item not found." << endl; // Display error message.
        } else { // Else.
            cout << this->dict.find(name)-> first << " " << this->dict.find(name)->second << endl; // Display item with count.
        }
        waitEnter(false); // Wait enter,
        clearScreen(); // Clear screen.

        input = searchItemMenu(); // Display search item menu to get user input.
    } // Else exit.
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

    // Close file.
    inFile.close();
    return 0;
}

void DataProcessor::createDatFile(string inFileName) { // Create .dat file.
    ofstream outFile; // Open output file stream.
    string outFileName = inFileName.substr(0, inFileName.size()-3) + "dat"; // Generate new file name.

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

    // Close file.
    outFile.close();
}

void DataProcessor::displayCount() { // Display the item counts.
    for (auto i = this->dict.begin(); i != this->dict.end(); i++) {
        cout << i->first << " " << i->second << endl; // Display item name and count.
    }
    waitEnter(false); // Wait for enter to user can view results.
    clearScreen(); // Clear screen.
}

void DataProcessor::displayHistogram() { // Display a historgram of the item counts.
    for (auto i = this->dict.begin(); i != this->dict.end(); i++) { // For each item in dictionary,
        cout << i->first << " " << string(i->second, '*') << endl; // Display item name and count.
    }
    waitEnter(false); // Wait for enter so user can view results.
    clearScreen(); // Clear screen.
}