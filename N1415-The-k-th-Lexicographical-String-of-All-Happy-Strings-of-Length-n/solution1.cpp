class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        vector<string> happyStrings;
        
        generateHappyStrings(n, currentString, happyStrings);

      
        if (happyStrings.size() < k) return "";

       
        sort(happyStrings.begin(), happyStrings.end());

        return happyStrings[k - 1];
    }

private:
    void generateHappyStrings(int n, string currentString,
                              vector<string> &happyStrings) {
        
        if (currentString.size() == n) {
            happyStrings.push_back(currentString);
            return;
        }

       
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
           
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            
            generateHappyStrings(n, currentString + currentChar, happyStrings);
        }
    }
};
