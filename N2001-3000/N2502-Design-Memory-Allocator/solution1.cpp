class Allocator {
public:
    Allocator(int n): n(n), memory(n) {}
    
    int allocate(int size, int mID) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (memory[i]) {
                count = 0;
            }
            else {
                ++count;
                if (count == size) {
                    for (int j = i - count + 1; j <= i; ++j) {
                        memory[j] = mID;
                    }
                    return i - count + 1;
                }
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (memory[i] == mID) {
                ++count;
                memory[i] = 0;
            }
        }
        return count;
    }

private:
    int n;
    vector<int> memory;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
