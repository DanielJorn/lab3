#include <iostream>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

int main() {
    HashTable<MyString, string> table = HashTable<MyString, string>();
    table.get(MyString("DDdD"));
}
