class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> sQueue;
        sQueue.push_back(deck[0]);
        for(int i = 1; i < deck.size(); i++)
        {
            sQueue.push_front(sQueue.back());
            sQueue.pop_back();
            sQueue.push_front(deck[i]);  
        }
        vector<int> res(sQueue.begin(), sQueue.end());
        return res;
    }
};
