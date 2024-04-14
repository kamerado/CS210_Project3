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
    auto dataProcessor = make_shared<DataProcessor>();
    
    searchFile(dataProcessor);

    input = mainMenu();
    while (input != 5) {
        switch (input) {
            case 1:
                dataProcessor->displayCount();
                break;
            case 2:
                dataProcessor->displayHistogram();
                break;
            case 3:
                dataProcessor->searchItem();
                break;
            case 4:
                searchFile(dataProcessor);
                break;
            case 5:
                break;
            default:
                cout << "Please enter valid input. (1-5)" << endl;
                break;
        }
        input = mainMenu();
        
        // if (dataProcessor->readInput(fileName) == 0) {
        //     dataProcessor->createDatFile(fileName);
        //     waitEnter(true);
        //     clearScreen();
        //     
        //     input = mainMenu();
        //     dataProcessor = make_unique<DataProcessor>();
        // }
    }

    return 0;
}