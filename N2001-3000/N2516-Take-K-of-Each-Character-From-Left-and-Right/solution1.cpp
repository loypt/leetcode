class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3]{};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            return -1;
        }

        int mx = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s[right] - 'a';
            cnt[c]--;
            while (cnt[c] < k) {
                cnt[s[left] - 'a']++;
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return s.length() - mx;
    }
};
