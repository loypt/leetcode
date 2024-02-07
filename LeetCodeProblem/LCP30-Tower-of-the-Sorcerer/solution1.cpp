class Solution {
public:
    int magicTower(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        long long hp = 1, delay = 0;
        for (int num: nums) {
            if (num < 0) {
                q.push(num);
            }
            hp += num;
            if (hp <= 0) {
                ++ans;
                delay += q.top();
                hp -= q.top();
                q.pop();
            }
        }
        hp += delay;
        return hp <= 0 ? -1 : ans;
    }
};
