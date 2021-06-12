#include <iostream>
#include <fstream>
#include <utility>

class MyString;

using namespace std;

static bool goodHashFunction = true;


class MyString {
public:
    string str;
    bool operator==(const MyString &anotherStr) const;
    bool operator!=(const MyString &anotherStr) const;
    explicit MyString(string str);
    explicit MyString();

    size_t goodHash(string str) const;
    size_t badHash(string str) const;
};

namespace std {
    template<>
    struct hash<MyString> {
        size_t operator()(const MyString &x) const {
            size_t hash;
            if (goodHashFunction){
                hash = x.goodHash(x.str);
               // cout << "good";
            } else {
                hash = x.badHash(x.str);
               // cout << "bad";

            }
            return hash;
        }
    };
}

bool MyString::operator==(const MyString &anotherStr) const {
    return str == anotherStr.str;
}

bool MyString::operator!=(const MyString &anotherStr) const {
    return !operator==(anotherStr);
}

MyString::MyString(string str) {
    this->str = std::move(str);
}

MyString::MyString() {
   this->str = "";
}

size_t MyString::goodHash(string str) const{
    const int aConst = 923452125;
    const int bConst = 942765847;
    unsigned int long long longHash = 0;
    for (int i = 0; i < str.size(); ++i) {
        longHash += str[i] * aConst;
    }
    return longHash % bConst;
}

size_t MyString::badHash(string str) const {
    int hash = 0;
    for (int i = 0; i < str.size(); ++i) {
        hash += str[i];
    }
    return hash;
}
