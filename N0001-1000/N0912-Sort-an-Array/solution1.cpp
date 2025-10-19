class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, nums.size()-1);
        return nums;
    }

    void randomized_quicksort(vector<int>& nums, int l, int r){
        if(l < r){
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos-1);
            randomized_quicksort(nums, pos+1, r);
        }
    }

    int randomized_partition(vector<int>& nums, int l, int r){
        int i = rand() % (r - l +1 ) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }
    
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int i = l-1;
        for(int j = l; j <= r-1; ++j){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
};
