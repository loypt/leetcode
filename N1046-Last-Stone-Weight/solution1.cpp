class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;
        for(int s : stones){
            que.push(s);
        }
        while(que.size() > 1){
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            if(a > b){
                que.push(a-b);
            }
        }
        return que.empty() ? 0 : que.top();
    }
};
