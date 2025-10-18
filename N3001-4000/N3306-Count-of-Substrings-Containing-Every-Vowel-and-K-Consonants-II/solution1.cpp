class Solution {
private:
    bool IsVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    long long countOfSubstrings(string word, int k) {
        int n=word.size() , i=0 , j=0 , cons=0;
        long long res=0;
        vector<int>nxtcons(n);
        int idx=n;

        for(int m=n-1;m>=0;m--){
            nxtcons[m]=idx;
            if(!IsVowel(word[m])) idx=m;
        }

        unordered_map<char , int>mp;

        while(i<n){
            if(IsVowel(word[i])){
                mp[word[i]]++;
            }
            else{
                cons++;
            }

            while(j<=i && cons>k){
                if(IsVowel(word[j])){
                    mp[word[j]]--;
                    if(mp[word[j]]==0) mp.erase(word[j]);
                }
                else{
                    cons--;
                }
                j++;
            }

            while(j<i && mp.size()==5 && cons==k){
                res+=nxtcons[i]-i;

                if(IsVowel(word[j])){
                    mp[word[j]]--;
                    if(mp[word[j]]==0) mp.erase(word[j]);
                }
                else{
                    cons--;
                }
                j++;

            }

            i++;
        }

        return res;

    }
};
