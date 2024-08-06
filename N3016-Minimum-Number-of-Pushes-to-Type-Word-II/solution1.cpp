class Solution {
public:
    static int minimumPushes(string word) {
        int freq[26]={0};
        for(char c: word) 
            freq[c-'a']++;
        sort(freq, freq+26, greater<int>());
        int sz=lower_bound(freq, freq+26, 0, greater<int>())-freq, i=0; 
        return accumulate(freq, freq+sz, 0,  [&i](int sum, int f){
            return sum+=(f*(i++/8+1));
        });
    }
};
