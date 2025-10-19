//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/28/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> max_queue;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& num:nums) {
            add(num);
        }
    }

    int add(int val) {
        max_queue.push(val);
        if (max_queue.size() > k) {
            max_queue.pop();
        }
        return max_queue.top();
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* kthLargest = new KthLargest(k, nums);
    cout << kthLargest->add(3) << endl;   // return 4
    cout << kthLargest->add(5) << endl;   // return 5
    cout << kthLargest->add(10) << endl;  // return 5
    cout << kthLargest->add(9) << endl;   // return 8
    cout << kthLargest->add(4) << endl;   // return 8
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

