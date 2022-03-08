//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/8/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution{
public:
    int findKthLargest(vector<int>& nums, int k){
        srand(time(0));
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }

    int quickSelect(vector<int>& a, int l, int r, int index){
        int q = randomPartition(a, l, r);
        if (q == index){
            return a[q];
        }else{
            return q < index ? quickSelect(a, q+1, r, index) : quickSelect(a, l, q-1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r){
        int i = rand() % (r-l+1)+l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r){
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x){
                swap(a[++i], a[j]);
            }
        }
        swap(a[i+1], a[r]);
        return i+1;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution solution;
    cout << solution.findKthLargest(nums, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


