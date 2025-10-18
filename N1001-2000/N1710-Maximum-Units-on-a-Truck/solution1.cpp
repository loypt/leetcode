class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> b1,  vector<int> b2){
            return b1[1] > b2[1];
        });
        int res = 0;
        for(const auto& box : boxTypes){
            int x = min(box[0], truckSize);
            res += x*box[1];
            truckSize-=x;
            if(!truckSize){
                break;
            }
        }
        return res;
    }
};
