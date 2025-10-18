class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i <= k; i++){
            temp.push_back(i);
        }
        temp.push_back(n+1);
        int j = 0;
        while(j < k){
            ans.emplace_back(temp.begin(), temp.begin()+k);
            j = 0;
            while(j < k && temp[j] +1 == temp[j+1]){
                temp[j] = j+1;
                j++;
            }
            temp[j]++;
        }
        return ans;
    }
};
