#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "my_string.h"
#include "hash_table.h"

using namespace std;
using namespace std::chrono;

int timee() {
    milliseconds ms = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );
    return ms.count();
}

string stringUpperCase(string str);

void processWords(string &str, HashTable<MyString, string> table);

void outputWord(string word, HashTable<MyString, string> table);

int main() {

    ifstream inFile("dict_processed.txt");
    string testString = "I don't know what to write in my test string";
    testString.c_str();
    if (!inFile)
        cout << "File cannot be opened." << endl;
    else {
        HashTable<MyString, string> table = HashTable<MyString, string>();
        while (!inFile.eof()) {
            string currentString;
            getline(inFile, currentString);
            int wordLength = currentString.find(';');
            string currentWord = currentString.substr(0, wordLength);
            MyString str = MyString(currentWord);
            goodHashFunction = true;
            table.add(str, currentString);
        }


        cout << "Type a sentence to get definition: ";
        string sentence = testString;
        //getline(cin, sentence);
        processWords(sentence, table);
        table.showStatistics();
        inFile.close();
        inFile.open("dict_processed.txt");
        HashTable<MyString, string> table2 = HashTable<MyString, string>();
        while (!inFile.eof()) {
            string currentString;
            getline(inFile, currentString);
            int wordLength = currentString.find(';');
            string currentWord = currentString.substr(0, wordLength);
            MyString str = MyString(currentWord);
            goodHashFunction = false;
            table2.add(str, currentString);
        }


        cout << "Type a sentence to get definition: ";
        string sentence2 = testString;
        //getline(cin, sentence);
        processWords(sentence2, table2);
        table2.showStatistics();
    }

}

string stringUpperCase(string str) {
    string result;
    for (char c : str) result += char(toupper(c));
    return result;
}

void processWords(string &str, HashTable<MyString, string> table) {
    string delim = " ";

    int start = 0;
    int end = 0;
    while (end < str.size()) {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != string::npos)) {
            start++;
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == string::npos)) {
            end++;
        }

        int wordLength = end - start;
        if (wordLength != 0) {
            string word = str.substr(start, wordLength);
            outputWord(word, table);
            str.replace(start, end - start + 1, "");
            end = start;
        }
    }
}

void outputWord(string word, HashTable<MyString, string> table) {
    string wordUpperCase = stringUpperCase(word);
    cout << "=================================" << endl;
    cout << "Definition of word " << word << ": " << endl;
    string res = table.get(MyString(wordUpperCase));
    if (res != "") {
        cout << res << endl;
    } else cout << "none" << endl;
}