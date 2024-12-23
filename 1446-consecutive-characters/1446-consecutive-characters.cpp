class Solution {
public:
    int maxPower(string s) {
        int max_length=0;
        int c=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                c++;
                max_length=max(max_length,c);
            }
            else c=1;
        }
        if(max_length<c) max_length=c;
        return max_length;
    }
};