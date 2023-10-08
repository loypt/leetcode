class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        int prevPrice = timePriceMap.count(timestamp) ? timePriceMap[timestamp] : 0;
        timePriceMap[timestamp] = price;
        if (prevPrice > 0) {
            auto it = prices.find(prevPrice);
            if (it != prices.end()) {
                prices.erase(it);
            }
        }
        prices.emplace(price);
    }
    
    int current() {
        return timePriceMap[maxTimestamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    multiset<int> prices;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
