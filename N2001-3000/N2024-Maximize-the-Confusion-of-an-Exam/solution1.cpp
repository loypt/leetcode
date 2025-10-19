class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                    maxConsecutiveChar(answerKey, k, 'F'));
    }
    int maxConsecutiveChar(string& answerKey, int k, char ch){
        int n = answerKey.length();
        int ans = 0;
        for(int left = 0, right = 0, sum = 0; right < n; right++){
            sum += answerKey[right] != ch;
            while(sum > k){
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
