#include <iostream>

class MyString;

using namespace std;

class MyString {
public:
    string str;
    bool operator==(const MyString &anotherStr) const;
    bool operator!=(const MyString &anotherStr) const;
    explicit MyString(string str);
    explicit MyString();
};

namespace std {
    template<>
    struct hash<MyString> {
        size_t operator()(const MyString &x) const {
            return x.str.size();
        }
    };
}

bool MyString::operator==(const MyString &anotherStr) const {
    int thisHash = hash<MyString>()(*this);
    int anotherHash = hash<MyString>()(anotherStr);
    return thisHash == anotherHash;
}

bool MyString::operator!=(const MyString &anotherStr) const {
    return !operator==(anotherStr);
}

MyString::MyString(string str) {
    this->str = str;
}

MyString::MyString() {
   this->str = "";
}
