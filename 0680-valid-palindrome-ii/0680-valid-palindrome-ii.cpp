class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0,j = n-1; 
        while(i < j){
            if(s[i] != s[j]){
                int k = i,l = j-1;
                int p = i+1,q = j;
                while(k < l && s[k] == s[l]){
                    k++;
                    l--;
                }
                while(p < q && s[p] == s[q]){
                    p++;
                    q--;
                }
                if(k >= l || p >= q) return true;
                else return false;        
            }
            i++;
            j--;
        }
        return true;
    }
};