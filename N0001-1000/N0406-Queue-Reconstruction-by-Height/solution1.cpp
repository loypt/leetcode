class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> person1, vector<int> person2){
            return person1[0] > person2[0] || (person1[0] == person2[0] && person1[1] < person2[1]);
        });
        vector<vector<int>> res;
        for(auto person : people){
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};
