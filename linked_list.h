#include <string>

using namespace std;

template<class V>
class LinkedList {
private:
    class Node {
    public:
        V value;
        Node *next;

        Node() = default;

        explicit Node(V value) {
            this->value = value;
        }
    };

    Node first;

public:
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
    }

    LinkedList() = default;

};
