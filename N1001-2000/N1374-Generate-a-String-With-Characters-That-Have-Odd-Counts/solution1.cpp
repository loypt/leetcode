class Solution {
public:
    string generateTheString(int n) {
        return n & 1 ? string(n,'a') : string(n-1,'a') + 'b';
    }
};
