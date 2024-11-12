class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto&& item1, auto&& item2) {
            return item1[0] < item2[0]; 
        });
        int n = items.size();
        for (int i = 1; i < n; ++i){
            items[i][1] = max(items[i][1], items[i-1][1]);
        }
        auto query = [&](int q) -> int{
            int l = 0, r = n;
            while (l < r){
                int mid = l + (r - l) / 2;
                if (items[mid][0] > q){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            if (l == 0){
                return 0;
            }
            else{
                return items[l-1][1];
            }
        };
        
        vector<int> res;
        for (int q: queries){
            res.push_back(query(q));
        }
        return res;
    }
};
