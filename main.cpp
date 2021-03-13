#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    LinkedList<string> list = LinkedList<string>();
    list.add("test adding worked");
    string result = list.get("test adding worked");
    cout << result << endl;
}
