class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0.0;
    }
    
    double next(int val) {
        if (qu.size() == size) {
            sum -= qu.front();
            qu.pop();
        }
        qu.emplace(val);
        sum += val;
        return sum / qu.size();
    }
private:
    int size;
    double sum;
    queue<int> qu;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
