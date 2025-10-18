class BinaryIndexedTree {
private:
    vector<int> tree;

public:
    BinaryIndexedTree(int n) : tree(n + 1) {}

    void add(int i) {
        while (i < tree.size()) {
            tree[i] += 1;
            i += i & -i;
        }
    }

    int get(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[sortedNums[i]] = i + 1;
        }

        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        BinaryIndexedTree tree1(n), tree2(n);
        tree1.add(index[nums[0]]);
        tree2.add(index[nums[1]]);

        for (int i = 2; i < n; ++i) {
            int count1 = arr1.size() - tree1.get(index[nums[i]]);
            int count2 = arr2.size() - tree2.get(index[nums[i]]);
            if (count1 > count2 || (count1 == count2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                tree1.add(index[nums[i]]);
            } else {
                arr2.push_back(nums[i]);
                tree2.add(index[nums[i]]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
