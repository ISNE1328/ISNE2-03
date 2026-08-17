#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "tree.h"

using namespace std;

string cleanWord(const string& str) {
    string cleaned = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main()
{
    string filename;
    cout << "Enter text filename: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return 1;
    }

    Tree<string> mytree;
    string line;
    int lineNumber = 0;

    while (getline(inFile, line)) {
        lineNumber++;
        stringstream ss(line);
        string rawWord;

        while (ss >> rawWord) {
            string word = cleanWord(rawWord);
            if (!word.empty()) {
                mytree.insert(word, lineNumber);
            }
        }
    }

    inFile.close();

    cout << " Cross-Reference List (Alphabetical Order)" << endl;

    mytree.inorder();

    return 0;
}