class Solution {
public:
    bool winnerOfGame(string colors) {
        int freq[2] = {0, 0};
        int cnt = 0;
        int cur = 'C';
        for(char c : colors){
            if(c!= cur){
                cur = c;
                cnt = 1;
            }else if(++cnt >= 3){
                freq[c - 'A']++;
            }
        }
        return freq[0] > freq[1];
    }
};
