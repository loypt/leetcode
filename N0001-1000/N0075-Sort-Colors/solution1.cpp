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
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len < 2){
            return;
        }
        int zero = 0;
        int two = len;
        int i = 0;
        while(i < two){
            if (nums[i] == 0){
                swap(nums[i], nums[zero]);
                zero++;
                i++;
            }else if(nums[i] == 1){
                i++;
            }else{
                two--;
                swap(nums[i], nums[two]);
            }
        }
    }
};




int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {2,0,2,1,1,0};
    Solution solution;
    solution.sortColors(nums);
    for (int num : nums) {
        cout << num << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


