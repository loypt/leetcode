//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/3/22.
//

#include <iostream>
#include <chrono>
#include <stack>
#include <vector>

using namespace std;
using namespace std::chrono;



class NestedInteger {
private:
    int val;
    vector<NestedInteger> list;
public:
    NestedInteger(int val){
        val = val;
        list = vector<NestedInteger>{};
    }
    NestedInteger(vector<NestedInteger> inList){
        list = inList;
        val = NULL;
    }

    bool isInteger() const{
        if (isdigit(val)){
            return true;
        }else{
            return false;
        }
    }

    int getInteger() const{
        return val;
    }

    vector<NestedInteger> getList() {
        return list;
    }
};

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next(){
        return stk.top().first++->getInteger();
    }

    bool hasNext() {
        while (!stk.empty()){
            auto &p = stk.top();
            if (p.first == p.second){
                stk.pop();
                continue;
            }
            if (p.first == p.second){
                stk.pop();
                continue;
            }
            if (p.first->isInteger()){
                return true;
            }
            auto lst = p.first++->getList();
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    NestedInteger *niA = new NestedInteger({new NestedInteger(1), new NestedInteger(1)});
    NestedInteger *niB = new NestedInteger(2);
    NestedInteger *niC = new NestedInteger({new NestedInteger(1), new NestedInteger(1)});
    vector<NestedInteger> nestedList = {*niA, *niB, *niC};
    NestedIterator *iterator = new NestedIterator(nestedList);
    while (iterator->hasNext()){
        cout << iterator->next();
    }

    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

