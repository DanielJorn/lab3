#include <iostream>
#include "linked_list.h"
#include "my_string.h"

using namespace std;

int main() {
    LinkedList<string> list = LinkedList<string>();
    MyString str = MyString();
    str.str = "dsd";
    int hash = std::hash<MyString>()(str);
    cout << "hash is " << hash << endl;
    list.add("test adding worked");
    string result = list.get("test adding worked");
    cout << result << endl;
}
