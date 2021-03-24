#include <iostream>
#include <fstream>
#include <string>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

int main() {
    ifstream inFile("dict_processed.txt");
    if (!inFile)
        cout << "File cannot be opened." << endl;
    else
    {
        HashTable<MyString, string> table = HashTable<MyString, string>();
        while (!inFile.eof())
        {
            string currentString;
            getline(inFile, currentString);
            int wordLength = currentString.find(';');
            string currentWord = currentString.substr(0, wordLength);
            table.add(MyString(currentWord), currentString);
        }


        string res = table.get(MyString("ABALONE"));
        cout << res << endl;
    }
    
}