#include <iostream>
#include <fstream>
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
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    Pair<K, V> pairToAdd = Pair<K, V>(key, value);
    list.add(pairToAdd);
    ++elementsStored;

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
    currSize *= 2;
    auto *resizedArray = new LinkedList<Pair<K, V>>[currSize];

    for (int listInd = 0; listInd < currSize / 2; ++listInd) {
        LinkedList<Pair<K, V>>& currList = array[listInd];
        for (int pairInd = 0; pairInd < currList.size(); ++pairInd) {

            Pair<K, V> currPair = currList.get(pairInd);
            int ind = getListIndexByKey(currPair.left);
            resizedArray[ind].add(currPair);
        }
    }
    array = resizedArray;
}
