#ifndef INTERFACE_H
#define INTERFACE_H

using namespace std;
#pragma once

namespace Interface {
    void clearScreen();
    void waitEnter(bool inputBufferClear);
    string stringToLower(string inStr);
    int mainMenu();
    int searchItemMenu();
    string getString(string prompt);
    int getInt();
};


#endif