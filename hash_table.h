#include <iostream>
#include "linked_list.h"
#include "pair.h"

template<class K, class V>
class HashTable {
private:
    int size = 5;
    LinkedList<Pair<K, V>> *array = new LinkedList<Pair<K, V>>[5];
    LinkedList<Pair<K, V>>& getListByKey(K key);
    int getListIndexByKey(K key);
public:
    V get(K key);
    void add(K key, V value);
    void remove(K key);
};

template<class K, class V>
V HashTable<K, V>::get(K key) {
    LinkedList<Pair<K, V>> &list = getListByKey(key);
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
void HashTable<K, V>::add(K key, V value) {
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    Pair<K, V> pairToAdd = Pair<K, V>(key, value);
    list.add(pairToAdd);
}

template<class K, class V>
void HashTable<K, V>::remove(K key) {
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    for (int i = 0; i < list.size(); ++i) {
        Pair<K, V> currPair = list.get(i);
        if (currPair.left == key){
            list.remove(i);
            break;
        }
    }
}

template<class K, class V>
LinkedList<Pair<K, V>> &HashTable<K, V>::getListByKey(K key) {
    int elementInd = getListIndexByKey(key);
    LinkedList<Pair<K, V>> &list = array[elementInd];
    return list;
}

template<class K, class V>
int HashTable<K, V>::getListIndexByKey(K key) {
    int hash = std::hash<K>()(key);
    return hash % size;
}
