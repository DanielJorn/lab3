#include <string>

using namespace std;

template<class V>
class LinkedList {
private:
    int mSize = 0;
    void addLast(V value);

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
    Node *last = nullptr;

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
        throw logic_error("index cannot be bigger than currSize");
    }

    Node *currNode = &first;
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
    addLast(value);
}

template<class V>
void LinkedList<V>::remove(int index) {
    Node *previous = &first;
    Node *toDelete = &first;
    for (int i = 0; i < index; ++i) {
        previous = toDelete;
        toDelete = (toDelete->next);
    }
    previous->next = toDelete->next;
    toDelete->next = NULL;
    --mSize;
    delete toDelete;
}

template<class V>
void LinkedList<V>::addLast(V value) {
    Node *lastPointer = last;
    Node *nodeToAdd = new Node(value);
    last = nodeToAdd;
    // if lastPointer is null, it means the list had no elements before
    // so we init the first node
    if (lastPointer == NULL) {
        first = *nodeToAdd;
        last = &first;
    }
        // if lastPointer wasn't null, we should now assign node "last" as next node of lastPointer
    else {
        lastPointer->next = last;
    }
    ++mSize;
}

