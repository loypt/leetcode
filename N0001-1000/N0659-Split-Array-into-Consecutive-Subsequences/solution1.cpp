class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>,greater<int>>> mp;
        for (auto& x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>,greater<int>>();
            }
            if (mp.find(x - 1) != mp.end()) {
                int prevLength = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLength + 1);
            } else {
                mp[x].push(1);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            priority_queue<int, vector<int>,greater<int>> queue = it->second;
            if (queue.top() < 3) {
                return false;
            }
        }
        return true;
    }
};
