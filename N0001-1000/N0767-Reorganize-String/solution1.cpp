class Solution {
public:
    string reorganizeString(string s) {
        if (s.length() < 2) {
            return s;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            char c = s[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        auto cmp = [&](const char& letter1, const char& letter2) {
            return counts[letter1 - 'a']  < counts[letter2 - 'a'];
        };
        priority_queue<char, vector<char>,  decltype(cmp)> queue{cmp};
        for (char c = 'a'; c <= 'z'; c++) {
            if (counts[c - 'a'] > 0) {
                queue.push(c);
            }
        }
        string sb = "";
        while (queue.size() > 1) {
            char letter1 = queue.top(); queue.pop();
            char letter2 = queue.top(); queue.pop();
            sb += letter1;
            sb += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            counts[index1]--;
            counts[index2]--;
            if (counts[index1] > 0) {
                queue.push(letter1);
            }
            if (counts[index2] > 0) {
                queue.push(letter2);
            }
        }
        if (queue.size() > 0) {
            sb += queue.top();
        }
        return sb;
    }
};
