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

        Node() = default;

        explicit Node(V value) {
            this->value = value;
        }
    };

    Node first;

public:
    int size();

    V get(int index);
    V get(V value);
    void add(V value);
    void remove(int index);

    LinkedList() = default;

};

template<class V>
V LinkedList<V>::get(int index) {
    if (index >= this->size()) {
        cout << " ERROR " << endl;
        throw logic_error("index cannot be bigger than size");
    }

    Node* currNode = &first;
    for (int i = 0; i < index; ++i) {
        currNode = currNode->next;
    }

    return currNode->value;
}

template<class V>
int LinkedList<V>::size() {
    return mSize;
}

template<class V>
V LinkedList<V>::get(V value) {
    Node *next = &first;
    while (next != nullptr) {
        if (next->value == value) {
            return next->value;
        }
        next = next->next;
    }
}

template<class V>
void LinkedList<V>::add(V value) {
    Node *next = &first;
    while (next->next != nullptr) {
        next = next->next;
    }
    Node *n = (new Node(value));
    next->next = n;
    ++mSize;
}

template<class V>
void LinkedList<V>::remove(int index) {
    Node *previous = &first;
    Node *toDelete = &first;
    for (int i = 0; i < index; ++i) {
        toDelete = &toDelete->next;
        previous = toDelete;
    }
    previous->next = toDelete->next;
    toDelete->next = NULL;
    delete toDelete;
}
