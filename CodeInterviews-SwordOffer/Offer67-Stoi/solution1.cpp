class Solution {
public:
    int strToInt(string str) {
        long int ans=0;
        bool sign=false;
        int l=str.length();
        int i=0;
        while(str[i]==' '&&i<l){
            i++;
        }
        if(str[i]=='-'||str[i]=='+'){
            str[i]=='-'?sign=true:sign=false;
            i++;
        }
        if((str[i]<'0'||str[i]>'9')){
            return 0;
        }
        while(i<l){
            if(str[i]<'0'||str[i]>'9'){
                break;
            }
            ans*=10;
            ans+=str[i]-'0';
            i++;
            if(ans>INT_MAX){
                return sign?INT_MIN:INT_MAX;
            }
        }
        return sign?-ans:ans;
    }
};
