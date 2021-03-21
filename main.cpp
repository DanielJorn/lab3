#include <iostream>
#include "my_string.h"
#include "hash_table.h"

using namespace std;

int main() {
    LinkedList<string> list = LinkedList<string>();
    string str = "134";
    string str2 = "1342";
    string str3 = "13422";
    str.c_str();
    list.add(str);
    list.add(str2);
    list.add(str3);
    cout << list.get(1) << endl;
}

