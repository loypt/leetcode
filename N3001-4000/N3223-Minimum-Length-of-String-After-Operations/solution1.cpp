class Solution {
public:
    int minimumLength(string s) {
        map<int,int> freq;
        for(int n:s){
            freq[n]++;
        }
        int count = 0;
        for(auto& pair: freq){
            if(pair.second>=3){
                while(pair.second>=3){
                    pair.second-=2;
                }
                count += pair.second;
            }
            else if(pair.second<=2) count += pair.second;
        }
        return count;
    }
}
