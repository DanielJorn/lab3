#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

string stringUpperCase(string str);

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
        
       string str = stringUpperCase("neEdless");
       cout << "definition for word needless: ";
       string res = table.get(MyString(str));
       cout << res << endl;
    }
    
}

string stringUpperCase(string str)
{
    string result;
    for (char c : str) result += char(toupper(c));
    return result;
}