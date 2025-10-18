class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotation = check(tops[0], bottoms, tops, n);
        if(rotation != -1 || tops[0] == bottoms[0]){
            return rotation;
        } 
        else{
            return check(bottoms[0], tops, bottoms, n);
        } 
    }
    int check(int x, vector<int>& A, vector<int>& B, int n){
        int rotation_a = 0, rotation_b = 0;
        for(int i = 0; i < n; ++i){
            if(A[i] != x && B[i]!= x){
                return -1;
            }else if(A[i] != x){
                rotation_a++;
            }else if(B[i] != x){
                rotation_b++;
            }
        }   
        return min(rotation_a, rotation_b);
    }
};
