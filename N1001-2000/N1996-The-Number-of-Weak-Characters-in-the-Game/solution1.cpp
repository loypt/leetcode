class Solution{
public:
     int numberOfWeakCharacters(vector<vector<int>> &properties){
          sort(properties.begin(), properties.end(), [](const vector<int>& a1, const vector<int>& a2){
              return a1[0] == a2[0] ? (a1[1] > a2[1]) : (a1[0] < a2[0]);
          });
          int mtn = INT_MIN;
          int ans = 0;

          for (int i = properties.size() - 1; i >= 0; i--)
          {
               if (properties[i][1] < mtn)
                    ans++;
               mtn = max(mtn, properties[i][1]);
          }
          return ans;
     }
};
