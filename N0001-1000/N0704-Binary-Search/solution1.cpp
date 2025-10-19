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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (high+low)/2;
            int num = nums[mid];
            if (num == target){
                return mid;
            }else if(num < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution solution;
    cout <<  solution.search(nums, target);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


