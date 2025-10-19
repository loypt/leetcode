//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/8/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    double average(vector<int>& salary) {
        double max = *max_element(salary.begin(), salary.end());
        double min = *min_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), -max - min);
        return sum/int(salary.size()-2);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> salary = {4000,3000,1000,2000};
    Solution solution;
    cout <<  solution.average(salary);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


