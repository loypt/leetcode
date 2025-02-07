class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        int n= queries.size();
        map<int,int>ballMap;
        map<int,int>colorMap;

        vector<int>ans;

        for(auto it: queries){
            int ball = it[0];
            int color = it[1];

            if(ballMap.find(ball)!=ballMap.end()){
                int currColor = ballMap[ball];
                if(currColor!=color){
                    colorMap[currColor]--;
                    if(colorMap[currColor]==0){
                        colorMap.erase(currColor);
                    }
                    colorMap[color]++;
                    ballMap[ball]= color;
                }
            
            }
            else{
                ballMap[ball]= color;
                colorMap[color]++;
            }

            ans.push_back(colorMap.size());

        }
        return ans;
    }
};
