#include <iostream>
#include "linked_list.h"
#include "my_string.h"

using namespace std;

int main() {
    LinkedList<string> list = LinkedList<string>();

    MyString str = MyString();
    str.str = "dsd";
    MyString str1 = MyString();
    str1.str = "123";

    bool a = str == str1;
    cout << "Hash function working incorrectly " << a << endl;

    list.add("test adding worked");
    string result = list.get("test adding worked");
    cout << result << endl;
}
