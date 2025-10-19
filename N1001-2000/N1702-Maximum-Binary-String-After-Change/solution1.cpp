class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                while (j <= i || (j < n && binary[j] == '1')) {
                    j++;
                }
                if (j < n) {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }
};
