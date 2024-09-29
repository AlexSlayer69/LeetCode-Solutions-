class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(),c=0;
        int i = n-1;
        while(i>=0){
            if(s[i] != ' ')
                break;
            i--;
        }
        while(i >= 0){
            if(s[i] == ' ') break;
            c++;
            i--;
        }
        return c;
    }
};