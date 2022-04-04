class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
    }
};
