class Solution {
public:
    long long maximumImportance(int n,vector<vector<int>>& roads) {
        unordered_map<int,int> roadCnt;
        long long ans=0;
        for (int i=0;i<roads.size();++i)
        {
            ++roadCnt[roads[i][0]];
            ++roadCnt[roads[i][1]];
        }
        vector<pair<int,int>> vec(roadCnt.begin(),roadCnt.end());
        sort(vec.begin(),vec.end(),[](auto pr1, auto pr2){return pr1.second>pr2.second;});
        for (int i=0;i<vec.size();++i)
            ans+=(long long)vec[i].second*(n--);
        return ans;
    }
};
