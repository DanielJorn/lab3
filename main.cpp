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
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("32"), "val33");
    table.add(MyString("32"), "val33");
    table.add(MyString("322"), "val313");
    table.add(MyString("32"), "val33");
    table.add(MyString("32"), "val33");
    table.add(MyString("43"), "val23");
    table.add(MyString("43"), "val33");
    table.add(MyString("43"), "val33");
    table.add(MyString("43"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("31233"), "val33");
    table.add(MyString("31233"), "val33");
    table.add(MyString("31233"), "val33");
    table.add(MyString("31233"), "val33");
    table.add(MyString("31233"), "val33");
    table.add(MyString("31233"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("331"), "val33as");
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");
    table.add(MyString("33"), "val33");


    string res = table.get(MyString("331"));
    cout << res << endl;
}

