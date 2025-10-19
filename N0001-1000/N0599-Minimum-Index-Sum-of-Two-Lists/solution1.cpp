//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<int, vector<string>> res;
        for (int i = 0; i < list1.size(); ++i) {
            for (int j = 0; j < list2.size(); ++j) {
                if (list1[i] == list2[j]){
                    res[i+j].push_back(list1[i]);
                }
            }
        }
        return res.begin()->second;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    Solution solution;
    vector<string> res =  solution.findRestaurant(list1, list2);
    for (string s:res) {
        cout << s << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

