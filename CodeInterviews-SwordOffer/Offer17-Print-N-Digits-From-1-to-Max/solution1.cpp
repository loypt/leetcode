class Solution {
    vector<int> nums;
    string s;   
public:
    vector<int> printNumbers(int n) {
        s.resize(n, 0);
        dfs(n, 0);
        return nums;
    }

    void dfs(int end, int index){
        if(index == end){
            save();
            return;
        }
        for(int i = 0; i <= 9; ++i){
            s[index] = i + '0';
            dfs(end, index+1);
        }
    }

    void save(){
        int ptr= 0;
        while(ptr < s.size() && s[ptr] == '0') ptr++;
        if(ptr != s.size()){
            nums.emplace_back(stoi(s.substr(ptr)));
        }
    }
};
