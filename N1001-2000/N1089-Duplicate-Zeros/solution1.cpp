class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        int top = 0;
        int i = -1;
        while(top < len){
            i++;
            if(arr[i] != 0){
                top += 1;
            }else{
                top += 2;
            }
        }
        int j = len-1;
        if(top == len + 1){
            arr[j] = 0;
            i--;
            j--;
        }
        while (j >= 0) {
            arr[j] = arr[i];
            j--;
            if (!arr[i]) {
                arr[j] = arr[i];
                j--;
            } 
            i--;
        }
    }
};
