class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); i++) queries[i].push_back(i);

        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
            
            return a[1] > b[1];
        });
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });
        int i = 0;
        set<int> st;
        vector<int> ans(queries.size());
        for(auto q : queries) {
            int prefer = q[0], minSize = q[1], idx = q[2];
            while(i < rooms.size() && rooms[i][1] >= minSize)
                st.insert(rooms[i++][0]);
            if(st.size()) {
                auto it = st.upper_bound(prefer);
                int res = it != st.end() ? abs(*it - prefer) : INT_MAX;
                int resRoomId = it != st.end() ? *it : INT_MAX;
                if(it != st.begin()) {
                    --it;
                    if(abs(*it - prefer) <= res)
                        resRoomId = *it;
                }
                ans[idx] = resRoomId;
            }else
                ans[idx] = -1;
        }
        return ans;
    }
};
