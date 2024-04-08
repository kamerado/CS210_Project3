#include <iostream>
#include <sstream>
#include <limits>
#include <filesystem>

#include "../include/Interface.h"
#include "../include/DataProcessor.h"

using namespace std;
using namespace Interface;

void Interface::clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void Interface::waitEnter(bool inputBufferClear) {
    string input;

    cout << "Press enter to continue...";
    if (!inputBufferClear) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input.
        getline(cin, input); // Wait for enter.
    } else {
        getline(cin, input); // Wait for enter.
    }
}

string Interface::stringToLower(string inStr) {
    stringstream outStr;

    for (char i: inStr) {
        outStr << static_cast<char>(tolower(i));
    }

    return outStr.str();
}

int Interface::mainMenu() {
    int input = -1;

    while (input == -1) {
        cout << string(20, '*') << endl;
        cout << "1. Enter file name" << endl;
        cout << "2. Exit" << endl;

        input = getInt();
    }

    clearScreen();
    return input;
}

int Interface::searchItemMenu() {
    int input = -1;

    while (input == -1) {
        cout << string(15, '*') << endl;
        cout << "1. Search item" << endl;
        cout << "2. Main menu" << endl;
        input = getInt();
    }

    clearScreen();
    return input;
}

string Interface::getString(string prompt) {
    string input;

    cout << prompt;
    cin >> input;

    return input;
}

int Interface::getInt() {
    int input;

    try { // Try
        cin >> input; // Get in input from user.
        if (cin.fail()) { // Check if the input failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            throw string("Please enter numeric values only.\n"); // Throw exception.
        } else if ((input < 1) || (input > 2)) { // If user inputs invalid value.
            throw string("Please enter 1 or 2.\n"); // Throw excpetion.
        }
    } catch (string error) { // Catch exception.
        input = -1; // Set input to intitial value do when program exits, loop will continue until correct input is entered.
        clearScreen();
        cout << error; // Display error message to user.
    }

    return input;
}