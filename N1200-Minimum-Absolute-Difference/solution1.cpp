class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int len = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for(int i = 0; i < len-1; ++i){
            int temp = arr[i+1]-arr[i];
            if(temp < minDiff){
                minDiff = temp;
                res = {{arr[i], arr[i+1]}};
            }else if(temp == minDiff){
                res.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
