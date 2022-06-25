#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& A) {
        long total = 0;
        int n = A.size(), a;
        priority_queue<int> pq(A.begin(), A.end());
        for (int a : A)
            total += a;
        while (true) {
            a = pq.top();
            pq.pop();
            total -= a;

            if (a == 1 || total == 1)
                return true;
            if (a < total || total == 0 || a % total == 0)
                return false;
            a %= total;
            total += a;
            pq.push(a);
        }
    }
};

int main(){
    vector<int> target = {9, 3, 5};
    Solution solution;
    cout << solution.isPossible(target);
    return 0;
}
