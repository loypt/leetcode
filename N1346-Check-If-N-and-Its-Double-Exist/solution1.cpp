class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (auto i = arr.begin(), j = arr.begin(); i != arr.end(); ++i) {
            while (j != arr.end() && *i * 2 > *j)
                ++j;
            if (j != arr.end() && i != j && *i * 2 == *j)
                return true;
        }
        for (auto i = arr.rbegin(), j = arr.rbegin(); i != arr.rend(); ++i) {
            while (j != arr.rend() && *i * 2 < *j)
                ++j;
            if (j != arr.rend() && i != j && *i * 2 == *j)
                return true;
        }
        return false;
    }
};
