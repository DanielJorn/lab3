#include <string>

using namespace std;

template<class V>
class LinkedList {
private:
    int mSize = 0;

    class Node {
    public:
        V value;
        Node *next = nullptr;

        Node() {};

        explicit Node(V value) {
            this->value = value;
        }
    };

    Node first;

public:
    int size() {
        return mSize;
    }
    V get(int index);

    V get(V value) {
        Node *next = &first;
        while (next != nullptr) {
            if (next->value == value) {
                return next->value;
            }
            next = next->next;
        }
    }

    void add(V value) {
        Node *next = &first;
        while (next->next != nullptr) {
            next = next->next;
        }
        Node *n = (new Node(value));
        next->next = n;
        ++mSize;
    }

    LinkedList() {};

};

template<class V>
V LinkedList<V>::get(int index) {
    if (index >= this->size()) {
        cout << " ERROR " << endl;
        throw logic_error("index cannot be bigger than size");
    }

    Node* currNode = &first;
    for (int i = 0; i < this->size(); ++i) {
        currNode = currNode->next;
    }

    return currNode->value;
}
