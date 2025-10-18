/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '['){
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> stk;
        int num = 0;
        bool negative = false;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '-'){
                negative = true;
            }else if(isdigit(c)){
                num = num*10 + c - '0';
            }else if(c == '['){
                stk.emplace(NestedInteger());
            }else if(c == ',' || c == ']'){
                if(isdigit(s[i-1])){
                    if(negative){
                        num *= -1;
                    }
                    stk.top().add(NestedInteger(num));
                }
                num = 0;
                negative = false;
                if(c == ']' && stk.size() > 1){
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
            }
        }
        return stk.top();
    }
};
