#include <iostream>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

int main() {
    HashTable<MyString, string> table = HashTable<MyString, string>();
    table.add(MyString("DDdD"), "dssda");
    table.add(MyString("DD2dD"), "dssda2");
    table.add(MyString("DD3dD1"), "dssda3");
    table.add(MyString("4"), "4");

    string res = table.get(MyString("DD3dD1"));
    cout << res << endl;
}

