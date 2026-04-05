class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        string res;
        for (int i = 0; i < cols; ++i){
            int r = 0;
            int c = i;
            while (r < rows && c < cols){
                res.push_back(encodedText[r*cols+c]);
                ++r;
                ++c;
            }
        }
        while (res.size() and res.back() == ' '){
            res.pop_back();
        }
        return res;
    }
};
