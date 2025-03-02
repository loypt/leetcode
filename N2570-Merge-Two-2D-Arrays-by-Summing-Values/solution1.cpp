class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        unordered_map<int,int>mp;
        for( auto v : nums1 ){
            mp[v[0]] = v[1];
        }
        for( auto vec : nums2 ){
            if( mp[vec[0]] == 0 )
                result.push_back(vec);
            else{
                int temp = vec[1]+mp[vec[0]];
                result.push_back(vector<int>{vec[0],temp});
                mp[vec[0]] = -1;
            }
        }
        for( auto [mpp,cnt] : mp ){
            if( cnt > 0 ){
                result.push_back(vector<int>{mpp,cnt});
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
