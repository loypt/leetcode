class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexmap;
        for(int i = 0; i < list1.size(); i++){
            indexmap[list1[i]] = i;
        }
        vector<string> ret;
        int indexSum = INT_MAX;
        for(int j = 0; j < list2.size(); j++){
            if(indexmap.count(list2[j]) > 0){
                int k = indexmap[list2[j]];
                if(j+k < indexSum){
                    ret.clear();
                    ret.push_back(list2[j]);
                    indexSum = j+k;
                }else if(k + j == indexSum){
                    ret.push_back(list2[j]);
                }
            }
        }
        return ret;
    }
};
