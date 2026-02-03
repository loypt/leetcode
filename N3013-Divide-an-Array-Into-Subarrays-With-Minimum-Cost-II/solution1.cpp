class Container {
public:
    Container(int k): k(k), sm(0) {}

    void adjust() {
        while (st1.size() < k && st2.size() > 0) {
            int x = *(st2.begin());
            st1.emplace(x);
            sm += x;
            st2.erase(st2.begin());
        }
        while (st1.size() > k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            sm -= x;
        }
    }

    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            sm += x;
        }
        adjust();
    }

    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it), sm -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    long long sum() {
        return sm;
    }

private:
    int k;
    multiset<int> st1, st2;
    long long sm;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.sum() + nums[k - 1];
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
};
