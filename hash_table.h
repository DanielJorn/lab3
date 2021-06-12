#include <iostream>
#include <fstream>
#include <chrono>
#include "linked_list.h"
#include "pair.h"

using namespace std::chrono;

int time() {
    milliseconds ms = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );
    return ms.count();
}

template<class K, class V>
class HashTable {
private:
    int currSize = 5;
    int elementsStored = 0;
    int bucketsUsed = 0;
    LinkedList<Pair<K, V>> *array = new LinkedList<Pair<K, V>>[currSize];

    LinkedList<Pair<K, V>> &getListByKey(K key);

    int getListIndexByKey(K key);

    bool overflowed();

public:
    void showStatistics();

    V get(K key);

    void add(K key, V value);

    void remove(K key);

    void resizeArray();
};

template<class K, class V>
V HashTable<K, V>::get(K key) {
    int startTime = time();
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    Pair<K, V> neededPair;

    for (int i = 0; i < list.size(); ++i) {
        Pair<K, V> currPair = list.get(i);
        if (currPair.left == key) {
            neededPair = currPair;
            break;
        }
    }
    int endTime = time();
    cout << "Time took " << endTime - startTime << " ms" << endl;
    return neededPair.right;
}

template<class K, class V>
void HashTable<K, V>::add(K key, V value) {
    LinkedList<Pair<K, V>> &list = getListByKey(key);
    if (list.size() == 0){
        ++bucketsUsed;
    }
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
    //cout << "the key is: " << key.str << endl;
    //cout << "the hash is: " << hash << endl;
    return hash % currSize;
}

template<class K, class V>
bool HashTable<K, V>::overflowed() {
    float percentageOfFuliness = (float (bucketsUsed) / (float) currSize) * 100;
    int maxPercentage = 80;
    return percentageOfFuliness > maxPercentage;
}

template<class K, class V>
void HashTable<K, V>::resizeArray() {

    cout << "-----" << endl;
    cout << "Num of buckets is " << currSize << endl;
    cout << "Num of buckets used is " << bucketsUsed << endl;
    cout << "Num of buckets not used is " << currSize - bucketsUsed << endl;

    currSize *= 2;
    auto *resizedArray = new LinkedList<Pair<K, V>>[currSize];


    bucketsUsed = 0;

    for (int listInd = 0; listInd < currSize / 2; ++listInd) {
        LinkedList<Pair<K, V>>& currList = array[listInd];
        for (int pairInd = 0; pairInd < currList.size(); ++pairInd) {

            Pair<K, V> currPair = currList.get(pairInd);
            int ind = getListIndexByKey(currPair.left);
            if (resizedArray[ind].size() == 0){
                ++bucketsUsed;
            }
            resizedArray[ind].add(currPair);
        }
    }
    array = resizedArray;


}

template<class K, class V>
void HashTable<K, V>::showStatistics() {
    cout << "-----" << endl;
    cout << "STATISTICS: " << endl;

    cout << "Num of buckets is " << currSize << endl;
    cout << "Num of buckets used is " << bucketsUsed << endl;
    cout << "Num of buckets not used is " << currSize - bucketsUsed << endl;
    cout << "-----" << endl;
    cout << "elements stored in bucket at average: " << elementsStored / bucketsUsed << endl;

    cout << "-----" << endl;

}

