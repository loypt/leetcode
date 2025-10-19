struct SegNode {
    SegNode() {
        v00 = v01 = v10 = v11 = 0;
    }
    void set(long long v) {
        v00 = v01 = v10 = 0;
        v11 = max(v, 0LL);
    }
    long long best() {
        return v11;
    }
    
    long long v00, v01, v10, v11;
};

class SegTree {
public:
    SegTree(int n): n(n), tree(n * 4 + 1) {}
    void init(const vector<int>& nums) {
        internal_init(nums, 1, 1, n);
    }
    void update(int x, int v) {
        internal_update(1, 1, n, x + 1, v);
    }
    long long query() {
        return tree[1].best();
    }

private:
    void internal_init(const vector<int>& nums, int x, int l, int r) {
        if (l == r) {
            tree[x].set(nums[l - 1]);
            return;
        }
        int mid = (l + r) / 2;
        internal_init(nums, x * 2, l, mid);
        internal_init(nums, x * 2 + 1, mid + 1, r);
        pushup(x);
    }
    void internal_update(int x, int l, int r, int pos, int v) {
        if (l > pos || r < pos) {
            return;
        }
        if (l == r) {
            tree[x].set(v);
            return;
        }
        int mid = (l + r) / 2;
        internal_update(x * 2, l, mid, pos, v);
        internal_update(x * 2 + 1, mid + 1, r, pos, v);
        pushup(x);
    }
    void pushup(int x) {
        int l = x * 2, r = x * 2 + 1;
        tree[x].v00 = max(tree[l].v00 + tree[r].v10, tree[l].v01 + tree[r].v00);
        tree[x].v01 = max(tree[l].v00 + tree[r].v11, tree[l].v01 + tree[r].v01);
        tree[x].v10 = max(tree[l].v10 + tree[r].v10, tree[l].v11 + tree[r].v00);
        tree[x].v11 = max(tree[l].v10 + tree[r].v11, tree[l].v11 + tree[r].v01);
    }

private:
    int n;
    vector<SegNode> tree;
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegTree tree(n);
        tree.init(nums);
        
        int ans = 0;
        for (const auto& q: queries) {
            tree.update(q[0], q[1]);
            ans = ((long long)ans + tree.query()) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
