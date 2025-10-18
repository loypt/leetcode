class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>temp(n+1,0);
        vector<int>res(n);
        int count=0;
        for(int i=0;i<n;i++)
        {
            temp[A[i]]++;
            temp[B[i]]++;
            if(temp[A[i]]==2)
            {
                count++;
            }
            if(temp[B[i]]==2){
                count++;
            }
            if(A[i]==B[i])
            {
                count--;
            }
            res[i]=count;
        }
        return res;
    }
};
