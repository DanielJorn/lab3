#include <iostream>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

int main() {
    HashTable<MyString, string> table = HashTable<MyString, string>();
    table.add(MyString("1"), "val1");
    table.add(MyString("2"), "val2");
    table.add(MyString("22"), "val22");
    table.add(MyString("33"), "val33");
    table.add(MyString("44"), "val44");
    table.add(MyString("3"), "val3");
    table.remove(MyString("33"));

    string res = table.get(MyString("2"));
    cout << res << endl;
}

