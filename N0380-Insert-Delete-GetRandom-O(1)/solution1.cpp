//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/3/22.
//

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

class RandomizedSet {
public:
    vector<int> elements;
    unordered_map<int, int> maps;
    RandomizedSet() {}

    bool insert(int val) {
        bool res = false;
        if (!maps.count(val)){
            res = true;
            elements.push_back(val);
            maps[val] = elements.size()-1;
        }
        return res;
    }

    bool remove(int val) {
        bool res = false;
        if (maps.count(val)){
            res = true;
            int last = elements.back();
            elements[maps[val]] = elements.back();
            elements.pop_back();
            maps[last] = maps[val];
            maps.erase(val);
        }
        return res;
    }

    int getRandom() {
        return elements[rand()%elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    RandomizedSet randomizedSet;
    cout << randomizedSet.insert(1) << endl; // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << randomizedSet.remove(2) << endl; // Returns false as 2 does not exist in the set.
    cout << randomizedSet.insert(2) << endl; // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << randomizedSet.getRandom() << endl; // getRandom() should return either 1 or 2 randomly.
    cout << randomizedSet.remove(1) << endl; // Removes 1 from the set, returns true. Set now contains [2].
    cout << randomizedSet.insert(2) << endl; // 2 was already in the set, so return false.
    cout << randomizedSet.getRandom() << endl; // Since 2 is the only number in the set, getRandom() will always return 2.
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

