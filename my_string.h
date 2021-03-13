#include <iostream>

using namespace std;

class MyString {
public:
    string str;
};

namespace std {
    template<>
    struct hash<MyString> {
        size_t operator()(const MyString &x) const {
            return x.str.size();
        }
    };
}