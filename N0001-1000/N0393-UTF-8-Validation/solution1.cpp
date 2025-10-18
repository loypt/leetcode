//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int index = 0;
        while (index < len){
            int num = data[index];
            int n = getBytes(num);
            if (n < 0 || index + n > len){
                return false;
            }
            for (int i = 1; i < n; ++i) {
                if(!isValid(data[index+i]))
                    return false;
            }
            index += n;
        }
        return true;
    }

    bool isValid(int num){
        return (num & MASK2) == MASK1;
    }

    int getBytes(int num){
        if ((num & MASK1) == 0){
            return 1;
        }
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0){
            n++;
            if (n>4){
                return -1;
            }
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> data = {145};
    Solution solution;
    cout << solution.validUtf8(data);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


