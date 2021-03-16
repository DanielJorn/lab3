#include <iostream>
#include "linked_list.h"
#include "pair.h"

template<class K, class V>
class HashTable {
private:
    int size = 5;
    LinkedList<Pair<K, V>> *array = new LinkedList<Pair<K, V>>[5];

public:
    V get(K key);
    void add(K key, V value);
    void remove(K key);
};

template<class K, class V>
V HashTable<K, V>::get(K key) {
    int hash = std::hash<K>()(key);
    int elementInd = hash % size;
    LinkedList<Pair<K, V>> list = array[elementInd];
    Pair<K, V> neededPair;

    for (int i = 0; i < list.size(); ++i) {
        Pair<K, V> currPair = list.get(i);
        if (currPair.left == key){
            neededPair = currPair;
            break;
        }
    }

    return neededPair.right;
}

template<class K, class V>
void HashTable<K, V>::add(K key, V valuew) {
    int hash = std::hash<K>()(key);
    int elementInd = hash % size;
    LinkedList<Pair<K, V>> &list = array[elementInd];
    Pair<K, V> pairToAdd = Pair<K, V>(key, valuew);
    list.add(pairToAdd);
}

template<class K, class V>
void HashTable<K, V>::remove(K key) {
    int hash = std::hash<K>()(key);
    int elementInd = hash % size;
    LinkedList<Pair<K, V>> &list = array[elementInd];

}
