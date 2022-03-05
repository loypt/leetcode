//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/5/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    int maxPoints(vector<vector<int>>& points){
        int len = points.size();
        if (len <= 2){
            return len;
        }
        int ret = 0;
        for (int i = 0; i < len; ++i) {
            // max 1. ret greater remain  2. ret greater than half
            if (ret >= len-i || ret > len/2){
                break;
            }
            unordered_map<int, int> mymap;
            for (int j = i+1; j < len; ++j) {
                // calc slope
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0){
                    y = 1;
                }else if(y == 0){
                    x = 1;
                }else{
                    if (y < 0){
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    x /= gcdXY, y /= gcdXY;
                }
                mymap[y + x*20001]++;
            }
            int maxn = 0;
            for (auto& [_, num]: mymap) {
                maxn = max(maxn, num+1);
            }
            ret = max(ret, maxn);
        }
        return ret;

    }

    int gcd(int num1, int num2){
        return num2 ? gcd(num2, num1%num2) : num1;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> points= {{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
    Solution solution;
    cout << solution.maxPoints(points);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

