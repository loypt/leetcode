class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for(const auto& x : arr){
            bit[x] = get(x);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y){
            if(bit[x] < bit[y]){
                return true;
            }
            if(bit[x] > bit[y]){
                return false;
            }
            return x < y;
        });
        return arr;
    }
    int get(int x){
        int ans = 0;
        while(x){
            ans += x % 2;
            x /= 2;
        }
        return ans;
    }
};
