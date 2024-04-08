#include <iostream>
#include <string>
#include <memory>

#include "../include/Interface.h"
#include "../include/DataProcessor.h"

using namespace std;
using namespace Interface;

int main() {
    string fileName;
    int input = -1;
    auto dataProcessor = make_unique<DataProcessor>();

    input = mainMenu();
    while (input != 2) {
        fileName = getString("Enter file name: ");
        if (dataProcessor->readInput(fileName) == 0) {
            dataProcessor->createDatFile(fileName);
            waitEnter(true);
            clearScreen();
            dataProcessor->searchItem();
            input = mainMenu();
            dataProcessor = make_unique<DataProcessor>();
        }
    }

    return 0;
}