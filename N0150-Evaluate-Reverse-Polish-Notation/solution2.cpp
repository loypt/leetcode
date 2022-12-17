class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int ans=0;
        for(int i=0; i<tokens.size() ;i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                int a=stoi(tokens[i]);   st.push(a);
            } 
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(a+b);
                }
                else if(tokens[i]=="-"){
                    st.push(b-a);
                }
                else if(tokens[i]=="*"){
                    st.push(1ll*a*b);
                }
                else {
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};
