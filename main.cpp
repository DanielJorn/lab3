#include <iostream>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

int main() {
    HashTable<MyString, string> table = HashTable<MyString, string>();
    table.add(MyString("DDdD"), "dssda");
    table.add(MyString("DD2dD"), "dssda2");
    string res = table.get(MyString("DDd2D"));
    cout << res << endl;
}

