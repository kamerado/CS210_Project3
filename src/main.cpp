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
    
    searchFile(dataProcessor); // Search file.

    input = mainMenu(); // Display menu,
    while (input != 5) { // While user not exit.
        switch (input) {
            case 1:
                dataProcessor->displayCount(); // If user enters 1, display counts,
                break;
            case 2:
                dataProcessor->displayHistogram(); // If user enters 2, display histograms,
                break;
            case 3:
                dataProcessor->searchItem(); // If user enters 3, go to search item,
                break;
            case 4:
                searchFile(dataProcessor); // If user enters 4, get new file,
                break;
            case 5: // If 5, exit.
                break;
            default: // Display error message.
                cout << "Please enter valid input. (1-5)" << endl;
                break;
        }
        input = mainMenu(); // Display menu to get user input.
    }

    return 0; // Return 0.
}