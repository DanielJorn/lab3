#include <iostream>
#include "linked_list.h"

template<class K, class V>
class HashTable {
private:
    int size = 5;
    LinkedList<V> *array = new LinkedList<V>[size];
public:
    V get(K key);

    void add(K key, V value);
};

template<class K, class V>
V HashTable<K, V>::get(K key) {
    cout << hash<K>()(key) << endl;
}

template<class K, class V>
void HashTable<K, V>::add(K key, V value) {
    int hash = std::hash<K>()(key);
    int elementInd = hash % size;
    LinkedList<V> list = array[elementInd];
    //list.add(value);
}