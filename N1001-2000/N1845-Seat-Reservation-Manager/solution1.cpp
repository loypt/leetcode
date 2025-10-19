class SeatManager {
public:
    vector<int> available;

    SeatManager(int n) {
        for (int i = 1; i <= n; ++i){
            available.push_back(i);
        }
    }
    
    int reserve() {
        pop_heap(available.begin(), available.end(), greater<int>());
        int tmp = available.back();
        available.pop_back();
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        available.push_back(seatNumber);
        push_heap(available.begin(), available.end(), greater<int>());
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
