//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i+1, high = numbers.size() -1;
            while (low <= high){
                int mid = (high-low)/2 + low;
                if (numbers[mid] == target-numbers[i]){
                    return {i+1, mid+1};
                }else if(numbers[mid] > target - numbers[i]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return {-1, -1};
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution solution;
    vector<int> resArray = solution.twoSum(numbers, target);
    for (const auto& num:resArray) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


