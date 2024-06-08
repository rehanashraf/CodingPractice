/*
 * printstringfromparagraph.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: rehanashraf
 */

// C++ program to extract words from
// a strung using stringstream
#include<iostream>
#include <sstream>
using namespace std;

void printWords(string str)
{
    // word variable to store word
    string word;

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word)
        cout << word << endl;
}

// Driver code
int runPrintWords()
{
    string s = "sky is blue";
    printWords(s);
    return 0;
}
