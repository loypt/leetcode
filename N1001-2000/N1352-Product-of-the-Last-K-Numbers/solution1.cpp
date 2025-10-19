class ProductOfNumbers {
public:
    vector<int> v;  
    
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) 
    {
        int result = v[v.size() - 1];
        int i = v.size() - 2;
        
        while(k > 1) 
        { 
            result *= v[i];
            i--;
            k--;
        }

        return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
