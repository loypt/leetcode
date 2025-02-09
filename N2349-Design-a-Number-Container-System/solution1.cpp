class NumberContainers {
public:
    unordered_map<int,int> index2number;
    unordered_map<int,priority_queue<int, vector<int> , greater<int>>> number2index;
    
    NumberContainers() {}
    
    void change(int index, int number) 
    {
        index2number[index] = number;
        number2index[number].push(index);
    }
    
    int find(int number) 
    {
        
        while( (!number2index[number].empty()) && (index2number[number2index[number].top()]!=number) )
            number2index[number].pop();
        
        if(number2index[number].empty())
            return -1;
        return number2index[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
