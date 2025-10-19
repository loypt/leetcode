class OrderedStream {
public:
    OrderedStream(int n) {
        stream.resize(n + 1);
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> res;
        while (ptr < stream.size() && !stream[ptr].empty()) {
            res.push_back(stream[ptr]);
            ++ptr;
        }
        return res;
    }

private:
    vector<string> stream;
    int ptr;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */