class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for(int i = 0; i < length; i++){
            last[s[i] - 'a']  = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for(int i = 0; i < length; ++i){
            end = max(end, last[s[i]-'a']);
            if(i == end){
                partition.push_back(end-start+1);
                start = end+1;
            }
        }
        return partition;
    }
};
