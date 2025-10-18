class Solution {
public:
    int i=0; //index of vector
    vector<string> vs; //splitted string without spaces, ex.: (add 1 2) = {"(","add","1","2",")"}

    //get value - expression, integer or variable
    int getval(unordered_map<string,int> &hm){
        if(vs[i]=="(") return rec(hm);
        string s=vs[i++];
        return isalpha(s[0]) ? hm[s]:stoi(s); //handle variable or integer
    }
    //handle expression
    int rec(unordered_map<string,int> hm){
        int ans=0;
        i++; //pass '('
        string op = vs[i++];
        if(op=="let"){
            while(vs[i]!="(" && vs[i+1]!=")"){
                string var = vs[i++]; //variable name
                hm[var] = getval(hm); //variable value
            }
            ans = getval(hm);
        } else if(op=="add") ans=getval(hm)+getval(hm);
        else if(op=="mult") ans=getval(hm)*getval(hm);
        i++; //pass ')'
        return ans;
    }
    
    int evaluate(string s) {
        unordered_map<string,int> hm;
        for(int j=0, st=0;j<s.size();++j){
            if(s[j]==')' || s[j]=='(' || s[j]==' '){
                if(st!=j) vs.push_back(s.substr(st,j-st)); //push operator, integer or variable
                if(s[j]!=' ') vs.push_back(s.substr(j,1)); //push "(" or ")"
                st=j+1;
            }
        }
        return rec(hm);
    }
};
