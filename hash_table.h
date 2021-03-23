#include <iostream>
#include "linked_list.h"
#include "pair.h"

template<class K, class V>
class HashTable {
private:
    int currSize = 5;
    int elementsStored = 0;
    LinkedList<Pair<K, V>> *array = new LinkedList<Pair<K, V>>[currSize];

    LinkedList<Pair<K, V>> &getListByKey(K key);

    int getListIndexByKey(K key);

    bool overflowed();

public:
    V get(K key);

    void add(K key, V value);

    void remove(K key);

    void resizeArray();
};

template<class K, class V>
V HashTable<K, V>::get(K key) {
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    Pair<K, V> neededPair;

    for (int i = 0; i < list.size(); ++i) {
        Pair<K, V> currPair = list.get(i);
        if (currPair.left == key) {
            neededPair = currPair;
            break;
        }
    }

    return neededPair.right;
}

template<class K, class V>
void HashTable<K, V>::add(K key, V value) {
    //bool list
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    Pair<K, V> pairToAdd = Pair<K, V>(key, value);
    list.add(pairToAdd);
    ++elementsStored;
    //cout << "ds" <<endl;
    //resizeArray();
    //currSize += 1;
    //cout << currSize << endl;

    if (overflowed()){
        resizeArray();
    }
}

template<class K, class V>
void HashTable<K, V>::remove(K key) {
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    for (int i = 0; i < list.size(); ++i) {
        Pair<K, V> currPair = list.get(i);
        if (currPair.left == key) {
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
    return hash % currSize;
}

template<class K, class V>
bool HashTable<K, V>::overflowed() {
    float percentageOfFuliness = (float (elementsStored) / (float) currSize) * 100;
    int maxPercentage = 80;
    return percentageOfFuliness > maxPercentage;
}

template<class K, class V>
void HashTable<K, V>::resizeArray() {
    cout << "resizeArray()" << endl;
    currSize *= 2;
    auto *doubleArray = new LinkedList<Pair<K, V>>[currSize];
    for (int i = 0; i < currSize / 2; ++i) {
        doubleArray[i] = array[i];
    }
    array = doubleArray;
}
