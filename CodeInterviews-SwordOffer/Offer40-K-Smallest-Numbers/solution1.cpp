class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
       vector<int> res(k, 0); 
       sort(arr.begin(), arr.end());
       for(int i = 0; i < k; ++i){
           res[i] = arr[i];
       }
       return res;
    }
};
